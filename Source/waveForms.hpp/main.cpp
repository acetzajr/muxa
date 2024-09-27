#include "muxa/constants.hpp"
#include "muxa/waveForms.hpp"
#include <cmath>
namespace muxa {
auto sin(real partP) -> real { return std::sin(partP * kTwoPi); }
} // namespace muxa