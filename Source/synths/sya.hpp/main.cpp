#include "muxa/constants.hpp"
#include "muxa/frameRate.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include "muxa/waveForms.hpp"
#include <cmath>
namespace muxa {
auto Sya::wave(Wave &waveP) const -> Wave {
  i64 startFrame = timeToFrame(timeM, frameRateM);
  i64 endFrame = startFrame;
  endFrame += timeToFrame(durationM, frameRateM);
  i64 releaseFrame = endFrame;
  endFrame += timeToFrame(releaseM, frameRateM);
  for (i64 frame = startFrame; frame < endFrame && frame < waveP.frames();
       frame++) {
    double time = frameToTime(frame, frameRateM);
    double part = std::fmod(time * frequencyM, 1);
    double sample = muxa::sin(part) * amplitudeM;
    for (i64 channel = 0; channel < waveP.channels(); channel++) {
      waveP[frame][channel] += sample;
    }
  }
  i64 releaseFrames = endFrame - releaseFrame;
  for (i64 frame = releaseFrame; frame < endFrame && frame < waveP.frames();
       frame++) {
    double part = static_cast<double>(frame - releaseFrame) / releaseFrames;
    double multiplier = std::sin(kHalfPi * part + kHalfPi);
    for (i64 channel = 0; channel < waveP.channels(); channel++) {
      waveP[frame][channel] *= multiplier;
    }
  }
  return waveP;
}
} // namespace muxa