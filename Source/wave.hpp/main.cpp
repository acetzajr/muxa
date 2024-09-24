#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
namespace muxa {
Wave::Wave(double durationP, i64 channelsP, i64 frameRateP)
    : framesM(timeToFrame(durationP, frameRateP)), channelsM(channelsP),
      frameRateM(frameRateP), samplesM(framesM * channelsM) {}
} // namespace muxa
