#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include "muxa/waveForms.hpp"
namespace muxa {
class Sya {
public:
  WaveForm waveFormM = kWaveForm;
  real timeM = kTime;
  real frequencyM = kFrequency;
  real durationM = kDuration;
  real amplitudeM = kAmpliude;
  real attackM = kAttack;
  real releaseM = kRelease;
  i64 channelsM = kChannels;
  i64 frameRateM = kFrameRate;
  auto wave(Wave &wave) const -> Wave;
};
} // namespace muxa
