#pragma once
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
namespace muxa {
auto timeToFrame(double time, i64 frameRate = kFrameRate) -> i64;
auto frameToTime(i64 frame, i64 frameRate = kFrameRate) -> double;
} // namespace muxa