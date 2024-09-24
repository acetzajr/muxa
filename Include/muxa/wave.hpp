#pragma once
#include "muxa/constants.hpp"
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
  explicit Wave(double duration, i64 channels = kChannels,
                i64 frameRate = kFrameRate);
};
} // namespace muxa
