#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/wave.hpp"
using namespace muxa;
auto main() -> int {
  Scale scale(180, 5, 9);
  Wave wave(2);
  Sya synth;
  synth.wave(wave);
  wave.reafirm(0.5).normalize(0.75).save();
}