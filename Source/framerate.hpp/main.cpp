#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
namespace muxa {
auto timeToFrame(double timeP, i64 frameRateP) -> i64 {
  return timeP * frameRateP;
}
auto frameToTime(i64 frameP, i64 frameRateP) -> double {
  return static_cast<double>(frameP) / frameRateP;
}
} // namespace muxa