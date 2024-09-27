#include "muxa/constants.hpp"
#include "muxa/waveForms.hpp"
#include <cmath>
namespace muxa {
auto sin(double partP) -> double { return std::sin(partP * kTwoPi); }
} // namespace muxa