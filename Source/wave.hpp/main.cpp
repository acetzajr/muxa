#include "muxa/frame.hpp"
#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include <cmath>
#include <cstdio>
#include <fftw3.h>
#include <iostream>
#include <sndfile.h>
#include <stdexcept>
#include <string>
namespace muxa {
Wave::Wave(real durationP, u64 channelsP, u64 frameRateP)
    : framesCountM(timeToFrame(durationP, frameRateP)), channelsM(channelsP),
      frameRateM(frameRateP), samplesM(framesCountM * channelsM),
      framesM(framesCountM, Frame(samplesM.data(), channelsP)),
      fftInM(channelsP), fftOutM(channelsP), fftForwardPlansM(channelsP),
      fftBackwardPlansM(channelsP) {
  for (u64 i = 0; i < framesCountM; i++) {
    framesM[i].setPointer(&samplesM[i * channelsM]);
  }
}
Wave::~Wave() {
  for (u64 channel = 0; channel < channelsM; channel++) {
    if (fftInM[channel] != nullptr) {
      fftw_free(fftInM[channel]);
    }
    if (fftOutM[channel] != nullptr) {
      fftw_free(fftOutM[channel]);
    }
  }
}
auto Wave::operator[](u64 frameP) -> Frame & { return framesM[frameP]; }
auto Wave::frames() const -> u64 { return framesCountM; };
auto Wave::channels() const -> u64 { return channelsM; };
auto Wave::save(const std::string &pathP) -> Wave & {
  SF_INFO sfinfo;
  sfinfo.samplerate = frameRateM;
  sfinfo.channels = channelsM;
  sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE *file = sf_open(pathP.c_str(), SFM_WRITE, &sfinfo);
  if (file == nullptr) {
    throw std::runtime_error(sf_strerror(file));
  }
  auto written = sf_writef_double(file, samplesM.data(), framesCountM);
  if (static_cast<u64>(written) != framesCountM) {
    std::cerr << "writtten: " << written << ", frames: " << framesCountM
              << "\n";
    throw std::runtime_error(sf_strerror(file));
  }
  sf_close(file);
  return *this;
}
auto Wave::normalize(real amplitudeP) -> Wave & {
  real max = 0;
  for (auto &sample : samplesM) {
    if (sample > max) {
      max = sample;
    }
  }
  for (auto &sample : samplesM) {
    sample /= max;
    sample *= amplitudeP;
  }
  return *this;
}
auto Wave::reafirm(real power) -> Wave & {
  for (u64 channel = 0; channel < channelsM; channel++) {
    if (fftInM[channel] == nullptr) {
      fftInM[channel] =
          static_cast<real *>(fftw_malloc(sizeof(real) * framesCountM));
    }
    if (fftOutM[channel] == nullptr) {
      fftOutM[channel] = static_cast<fftw_complex *>(
          fftw_malloc(sizeof(fftw_complex) * framesCountM));
    }
    if (fftForwardPlansM[channel] == nullptr) {
      fftForwardPlansM[channel] = fftw_plan_dft_r2c_1d(
          framesCountM, fftInM[channel], fftOutM[channel], FFTW_ESTIMATE);
    }
    if (fftBackwardPlansM[channel] == nullptr) {
      fftBackwardPlansM[channel] = fftw_plan_dft_c2r_1d(
          framesCountM, fftOutM[channel], fftInM[channel], FFTW_ESTIMATE);
    }
  }
  for (u64 channel = 0; channel < channelsM; channel++) {
    for (u64 frame = 0; frame < framesCountM; frame++) {
      fftInM[channel][frame] = (*this)[frame][channel];
    }
    fftw_execute(fftForwardPlansM[channel]);
  }
  for (u64 channel = 0; channel < channelsM; channel++) {
    // Apply the low-pass filter
    real cutoff_freq = 440; // Adjust the cutoff frequency as needed
    for (u64 i = 0; i < framesCountM; i++) {
      double frequency = i * frameRateM / static_cast<real>(framesCountM);
      std::cout << frequency << "\n";
      if (frequency > cutoff_freq) {
        fftOutM[channel][i][0] = 0;
        fftOutM[channel][i][1] = 0;
      }
    }
    fftw_execute(fftBackwardPlansM[channel]);
  }
  for (u64 frame = 0; frame < framesCountM; frame++) {
    for (u64 channel = 0; channel < channelsM; channel++) {
      (*this)[frame][channel] = fftInM[channel][frame];
    }
  }
  return *this;
}
} // namespace muxa
