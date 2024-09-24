#include "muxa/frame.hpp"
#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
namespace muxa {
Wave::Wave(double durationP, i64 channelsP, i64 frameRateP)
    : framesCountM(timeToFrame(durationP, frameRateP)), channelsM(channelsP),
      frameRateM(frameRateP), samplesM(framesCountM * channelsM),
      framesM(framesCountM, Frame(samplesM.data(), channelsP)) {
  for (i64 i = 0; i < framesCountM; i++) {
    framesM[i].setPointer(&samplesM[i * channelsM]);
  }
}
auto Wave::operator[](i64 frameP) -> Frame & { return framesM[frameP]; }
auto Wave::frames() const -> i64 { return framesCountM; };
auto Wave::channels() const -> i64 { return channelsM; };

} // namespace muxa
