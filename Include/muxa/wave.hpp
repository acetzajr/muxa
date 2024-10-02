#pragma once
#include "muxa/constants.hpp"
#include "muxa/frame.hpp"
#include "muxa/types.hpp"
#include <fftw3.h>
#include <string>
#include <vector>
namespace muxa {
class Wave {
private:
  u64 framesCountM;
  u64 channelsM;
  u64 frameRateM;
  std::vector<real> samplesM;
  std::vector<Frame> framesM;
  std::vector<real *> fftInM;
  std::vector<fftw_complex *> fftOutM;
  std::vector<fftw_plan> fftForwardPlansM;
  std::vector<fftw_plan> fftBackwardPlansM;

public:
  Wave(const Wave &) = default;
  Wave(Wave &&) = delete;
  auto operator=(const Wave &) -> Wave & = default;
  auto operator=(Wave &&) -> Wave & = delete;
  explicit Wave(real duration, u64 channels = kChannels,
                u64 frameRate = kFrameRate);
  ~Wave();
  auto operator[](u64 frame) -> Frame &;
  [[nodiscard]] auto frames() const -> u64;
  [[nodiscard]] auto channels() const -> u64;
  auto save(const std::string &path = "out/wave.wav") -> Wave &;
  auto normalize(real amplitude = kAmpliude) -> Wave &;
  auto reafirm() -> Wave &;
};
} // namespace muxa
