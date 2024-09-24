#pragma once
#include "muxa/constants.hpp"
#include "muxa/frame.hpp"
#include "muxa/types.hpp"
#include <vector>
namespace muxa {
class Wave {
private:
  i64 framesCountM;
  i64 channelsM;
  i64 frameRateM;
  std::vector<double> samplesM;
  std::vector<Frame> framesM;

public:
  explicit Wave(double duration, i64 channels = kChannels,
                i64 frameRate = kFrameRate);
  auto operator[](i64 frame) -> Frame &;
  [[nodiscard]] auto frames() const -> i64;
  [[nodiscard]] auto channels() const -> i64;
};
} // namespace muxa
