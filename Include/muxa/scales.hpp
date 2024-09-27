#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include <vector>
namespace muxa {
class Scale {
private:
  double baseM;
  u64 fundamentalM;
  std::vector<rational> rationsM;

public:
  explicit Scale(double base = kScaleBase, u64 size = kScaleSize,
                 u64 fundamental = kScaleFundamental);
  void print() const;
  static void test();
};
} // namespace muxa