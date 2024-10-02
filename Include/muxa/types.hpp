#pragma once
#include <boost/rational.hpp>
#include <cstdint>
namespace muxa {
using byte = uint8_t;
using i64 = int64_t;
using u64 = uint64_t;
using real = double;
using rational = boost::rational<i64>;
} // namespace muxa
