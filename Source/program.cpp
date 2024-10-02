#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/wave.hpp"
using namespace muxa;
auto main() -> int {
  Scale scale(180, 5, 1);
  Wave wave(6);
  Sya synth;
  synth.frequencyM = scale.frequencyOf(0);
  synth.wave(wave);
  synth.frequencyM = scale.frequencyOf(6);
  synth.wave(wave);
  synth.timeM = 4.0;
  synth.frequencyM = scale.frequencyOf(3);
  synth.wave(wave);
  synth.frequencyM = scale.frequencyOf(9);
  synth.wave(wave);
  wave.reafirm().normalize().save();
}