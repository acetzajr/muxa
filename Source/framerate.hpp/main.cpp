#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
namespace muxa {
auto timeToFrame(real timeP, i64 frameRateP) -> i64 {
  return timeP * frameRateP;
}
auto frameToTime(i64 frameP, i64 frameRateP) -> real {
  return static_cast<real>(frameP) / frameRateP;
}
} // namespace muxa