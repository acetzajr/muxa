#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include "muxa/waveForms.hpp"
#include <cmath>
namespace muxa {
auto sin(real partP) -> real { return std::sin(partP * kTwoPi); }
auto sqr(real part) -> real { return part < 0.5 ? 1 : -1; }
auto saw(real part) -> real { return 2 * (1 - part) - 1; }
} // namespace muxa