#include "muxa/constants.hpp"
#include "muxa/math.hpp"
#include "muxa/scales.hpp"
#include "muxa/types.hpp"
#include <algorithm>
#include <cmath>
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

Scale::Scale(real baseP, u64 sizeP, u64 fundamentalP)
    : baseM(baseP), fundamentalM(fundamentalP), rationsM(sizeP * 2 + 1) {
  if (fundamentalP >= rationsM.size()) {
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
    std::cout << static_cast<real>(ration.numerator()) / ration.denominator()
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
auto Scale::powerOf(i64 noteIndexP) -> i64 {
  return noteIndexP < 0 ? (noteIndexP + 1) / ssize() - 1 : noteIndexP / ssize();
}
auto Scale::frequencyOf(i64 noteIndexP) -> real {
  return baseM * realOf(rationIndexOf(noteIndexP)) * realPowerOf(noteIndexP);
}
auto Scale::rationIndexOf(i64 noteIndexP) -> u64 {
  return pmod(noteIndexP, size());
}
auto Scale::size() -> u64 { return rationsM.size(); }
auto Scale::ssize() -> i64 { return static_cast<i64>(rationsM.size()); }
auto Scale::realOf(u64 rationIndexP) -> real {
  auto &ration = rationsM[rationIndexP];
  return static_cast<real>(ration.numerator()) / ration.denominator();
}
auto Scale::realPowerOf(i64 noteIndexP) -> real {
  return std::pow(static_cast<long double>(2),
                  static_cast<long double>(powerOf(noteIndexP)));
}
} // namespace muxa