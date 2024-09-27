#include "muxa/constants.hpp"
#include "muxa/frameRate.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include "muxa/waveForms.hpp"
#include <cmath>
namespace muxa {
auto Sya::wave(Wave &waveP) const -> Wave {
  u64 startFrame = timeToFrame(timeM, frameRateM);
  u64 attackFrame = startFrame;
  u64 endFrame = startFrame;
  endFrame += timeToFrame(durationM, frameRateM);
  u64 releaseFrame = endFrame;
  endFrame += timeToFrame(releaseM, frameRateM);
  for (u64 frame = startFrame; frame < endFrame && frame < waveP.frames();
       frame++) {
    real time = frameToTime(frame, frameRateM);
    real part = std::fmod(time * frequencyM, 1);
    real sample = muxa::sin(part) * amplitudeM;
    for (u64 channel = 0; channel < waveP.channels(); channel++) {
      waveP[frame][channel] += sample;
    }
  }
  u64 attackFrames = timeToFrame(attackM, frameRateM);
  for (u64 frame = attackFrame;
       frame < attackFrame + attackFrames && frame < waveP.frames(); frame++) {
    real part = static_cast<real>(frame) / attackFrames;
    real multiplier = std::sin(kHalfPi * part);
    for (u64 channel = 0; channel < waveP.channels(); channel++) {
      waveP[frame][channel] *= multiplier;
    }
  }
  u64 releaseFrames = endFrame - releaseFrame;
  for (u64 frame = releaseFrame; frame < endFrame && frame < waveP.frames();
       frame++) {
    real part = static_cast<real>(frame - releaseFrame) / releaseFrames;
    real multiplier = std::sin(kHalfPi * part + kHalfPi);
    for (u64 channel = 0; channel < waveP.channels(); channel++) {
      waveP[frame][channel] *= multiplier;
    }
  }
  return waveP;
}
} // namespace muxa