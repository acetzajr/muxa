#include "muxa/frame.hpp"
#include "muxa/frameRate.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sndfile.h>
#include <stdexcept>
#include <string>
namespace muxa {
Wave::Wave(double durationP, i64 channelsP, i64 frameRateP)
    : framesCountM(timeToFrame(durationP, frameRateP)), channelsM(channelsP),
      frameRateM(frameRateP), samplesM(framesCountM * channelsM),
      framesM(framesCountM, Frame(samplesM.data(), channelsP)) {
  for (i64 i = 0; i < framesCountM; i++) {
    framesM[i].setPointer(&samplesM[i * channelsM]);
  }
}
auto Wave::operator[](i64 frameP) -> Frame & { return framesM[frameP]; }
auto Wave::frames() const -> i64 { return framesCountM; };
auto Wave::channels() const -> i64 { return channelsM; };
auto Wave::save(const std::string &pathP) -> Wave {
  SF_INFO sfinfo;
  sfinfo.samplerate = frameRateM;
  sfinfo.channels = channelsM;
  sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE *file = sf_open(pathP.c_str(), SFM_WRITE, &sfinfo);
  if (file == nullptr) {
    throw std::runtime_error(sf_strerror(file));
  }
  auto written = sf_writef_double(file, samplesM.data(), framesCountM);
  if (written != framesCountM) {
    std::cerr << "writtten: " << written << ", frames: " << framesCountM
              << "\n";
    throw std::runtime_error(sf_strerror(file));
  }
  sf_close(file);
  return *this;
}
auto Wave::normalize() -> Wave {
  double max = 0;
  for (auto &sample : samplesM) {
    if (sample > max) {
      max = sample;
    }
  }
  for (auto &sample : samplesM) {
    sample /= max;
  }
  return *this;
}
} // namespace muxa
