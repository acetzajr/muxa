#pragma once
#include "muxa/types.hpp"
namespace muxa {
i64 timeToFrame(double time, i64 frameRate = 48'000);
double frameToTime(i64 frame, i64 frameRate = 48'000);
} // namespace muxa