#include "muxa/waveForms.hpp"
#include <cmath>
#include <numbers>
namespace muxa {
auto sin(double partP) -> double {
  return std::sin(2 * partP * std::numbers::pi);
}
} // namespace muxa