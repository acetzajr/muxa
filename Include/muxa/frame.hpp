#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include <span>
namespace muxa {
class Frame {
private:
  double *samplesM;
  i64 channelsM;
  std::span<double> spanM;

public:
  explicit Frame(double *samples, i64 channels = kChannels);
  void setPointer(double *samples);
  auto operator[](i64 channel) -> double &;
};
} // namespace muxa