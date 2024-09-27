#include "muxa/math.hpp"
#include "muxa/types.hpp"
namespace muxa {
auto pmod(i64 n, i64 m) -> i64 { return (n % m + m) % m; }
} // namespace muxa