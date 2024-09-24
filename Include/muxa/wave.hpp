#pragma once
#include "muxa/types.hpp"
#include <vector>
namespace muxa {
class Wave {
private:
  i64 framesM;
  i64 channelsM;
  i64 frameRateM;
  std::vector<double> samplesM;

public:
  Wave(double duration, i64 channels = 2, i64 frameRate = 48'000);
};
} // namespace muxa
