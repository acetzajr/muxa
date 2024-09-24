#include "muxa/frameRate.hpp"
namespace muxa {
i64 timeToFrame(double timeP, i64 frameRateP) { return timeP * frameRateP; }
double frameToTime(i64 frameP, i64 frameRateP) {
  return (double)frameP / frameRateP;
}
} // namespace muxa