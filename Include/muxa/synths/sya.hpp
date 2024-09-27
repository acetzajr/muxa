#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
namespace muxa {
class Sya {
public:
  double timeM = kTime;
  double frequencyM = kFrequency;
  double durationM = kDuration;
  double amplitudeM = kAmpliude;
  double releaseM = kRelease;
  i64 channelsM = kChannels;
  i64 frameRateM = kFrameRate;
  auto wave(Wave &wave) const -> Wave;
};
} // namespace muxa
