#pragma once
#include "muxa/constants.hpp"
#include "muxa/frame.hpp"
#include "muxa/types.hpp"
#include <string>
#include <vector>
namespace muxa {
class Wave {
private:
  u64 framesCountM;
  u64 channelsM;
  u64 frameRateM;
  std::vector<real> samplesM;
  std::vector<Frame> framesM;

public:
  explicit Wave(real duration, u64 channels = kChannels,
                u64 frameRate = kFrameRate);
  auto operator[](u64 frame) -> Frame &;
  [[nodiscard]] auto frames() const -> u64;
  [[nodiscard]] auto channels() const -> u64;
  auto save(const std::string &path = "out/wave.wav") -> Wave;
  auto normalize(real amplitude = kAmpliude) -> Wave;
};
} // namespace muxa
