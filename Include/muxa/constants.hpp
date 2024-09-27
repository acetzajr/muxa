#pragma once
#include "muxa/types.hpp"
#include <numbers>
namespace muxa {
constexpr i64 kChannels = 2;
constexpr i64 kFrameRate = 48'000;
constexpr rational kRationTwo = rational(2, 1);
constexpr rational kRationOne = rational(1, 1);
constexpr rational kRationUp(3, 2);
constexpr rational kRationDown(2, 3);
constexpr double kTime = 0;
constexpr double kFrequency = 360;
constexpr double kDuration = 1;
constexpr double kAmpliude = 1;
constexpr double kRelease = 1;
constexpr double kTwoPi = 2 * std::numbers::pi;
constexpr double kHalfPi = std::numbers::pi / 2;
constexpr double kScaleBase = 360;
constexpr u64 kScaleSize = 5;
constexpr u64 kScaleFundamental = 0;
} // namespace muxa