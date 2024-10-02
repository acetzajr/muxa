#pragma once
#include "muxa/types.hpp"
namespace muxa {
using WaveForm = real (*)(real part);
auto sin(real part) -> real;
auto sqr(real part) -> real;
auto saw(real part) -> real;
} // namespace muxa