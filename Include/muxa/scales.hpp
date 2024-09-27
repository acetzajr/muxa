#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include <vector>
namespace muxa {
class Scale {
private:
  real baseM;
  u64 fundamentalM;
  std::vector<rational> rationsM;

public:
  explicit Scale(real base = kScaleBase, u64 size = kScaleSize,
                 u64 fundamental = kScaleFundamental);
  void print() const;
  static void test();
  auto frequencyOf(i64 noteIndex) -> real;
  auto size() -> u64;
  auto ssize() -> i64;
  auto powerOf(i64 noteIndex) -> i64;
  auto realPowerOf(i64 noteIndex) -> real;
  auto realOf(u64 rationIndex) -> real;
  auto rationIndexOf(i64 noteIndex) -> u64;
};
} // namespace muxa