#include "muxa/constants.hpp"
#include "muxa/scales.hpp"
#include "muxa/types.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace muxa {

void normalizeRation(rational &rP) {
  while (rP > kRationTwo) {
    rP /= kRationTwo;
  }
  while (rP < kRationOne) {
    rP *= kRationTwo;
  }
}
auto fillScale(std::vector<rational> &rationsP, u64 sizeP) -> void {
  rationsP[0] = kRationOne;
  u64 scaleIdx = 1;
  rational r = kRationOne;
  for (u64 i = 0; i < sizeP; i++) {
    r *= kRationUp;
    normalizeRation(r);
    rationsP[scaleIdx++] = r;
  }
  r = kRationOne;
  for (u64 i = 0; i < sizeP; i++) {
    r *= kRationDown;
    normalizeRation(r);
    rationsP[scaleIdx++] = r;
  }
  std::sort(rationsP.begin(), rationsP.end());
}

Scale::Scale(double baseP, u64 sizeP, u64 fundamentalP)
    : baseM(baseP), fundamentalM(fundamentalP), rationsM(sizeP * 2 + 1) {
  if (fundamentalM < 0 || fundamentalP >= rationsM.size()) {
    throw std::runtime_error(
        "fundamentalM < 0 || fundamentalM >= rationsM.size()");
  }
  std::vector<rational> temporal(rationsM.size());
  fillScale(temporal, sizeP);
  rational fundamentalRation = temporal[fundamentalP];
  u64 rationsIdx = 0;
  for (u64 i = fundamentalP; i < rationsM.size(); i++, rationsIdx++) {
    rationsM[rationsIdx] = temporal[i] / fundamentalRation;
    normalizeRation(rationsM[rationsIdx]);
  }
  for (u64 i = 0; i < fundamentalP; i++, rationsIdx++) {
    rationsM[rationsIdx] = temporal[i] / fundamentalRation;
    normalizeRation(rationsM[rationsIdx]);
  }
}
void Scale::print() const {
  std::cout << "base: " << baseM << "\n";
  std::cout << "fundamental: " << fundamentalM << "\n";
  std::cout << "rations: { ";
  for (const auto &ration : rationsM) {
    std::cout << ration << " ";
  }
  std::cout << "}\n";
  std::cout << "reals: { ";
  for (const auto &ration : rationsM) {
    std::cout << static_cast<double>(ration.numerator()) / ration.denominator()
              << " ";
  }
  std::cout << "}\n";
}
void Scale::test() {
  for (u64 i = 0; i < 11; i++) {
    Scale scale(360, 5, i);
    scale.print();
    std::cout << "\n";
  }
}
} // namespace muxa