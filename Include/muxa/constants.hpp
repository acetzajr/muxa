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
constexpr real kTime = 0;
constexpr real kFrequency = 360;
constexpr real kDuration = 1;
constexpr real kAmpliude = 1;
constexpr real kAttack = 1.0 / 4.0;
constexpr real kRelease = 1;
constexpr real kTwoPi = 2 * std::numbers::pi;
constexpr real kHalfPi = std::numbers::pi / 2;
constexpr real kScaleBase = 360;
constexpr u64 kScaleSize = 5;
constexpr u64 kScaleFundamental = 0;
constexpr u64 kColorMax = 65535;
} // namespace muxa