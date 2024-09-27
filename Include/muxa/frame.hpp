#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include <span>
namespace muxa {
class Frame {
private:
  real *samplesM;
  i64 channelsM;
  std::span<real> spanM;

public:
  explicit Frame(real *samples, i64 channels = kChannels);
  void setPointer(real *samples);
  auto operator[](i64 channel) -> real &;
};
} // namespace muxa