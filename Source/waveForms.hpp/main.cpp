#include "muxa/waveForms.hpp"
#include <cmath>
#include <numbers>
namespace muxa {
double sin(double partP) { return std::sin(2 * partP * std::numbers::pi); }
} // namespace muxa