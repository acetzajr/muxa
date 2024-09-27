#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
using namespace muxa;
auto main() -> int {
  Scale scale(180, 5, 9);
  Wave wave(20);
  Sya synth;
  synth.durationM = 1.0 / 4;
  real adder = synth.durationM;
  for (u64 i = 0; i < 12; i++) {
    synth.frequencyM = scale.frequencyOf(0);
    synth.wave(wave);
    synth.timeM += adder;
    synth.frequencyM = scale.frequencyOf(0 + 4);
    synth.wave(wave);
    synth.timeM += adder;
    synth.frequencyM = scale.frequencyOf(0 + 4 + 3);
    synth.wave(wave);
    synth.timeM += adder;
    synth.frequencyM = scale.frequencyOf(0);
    synth.wave(wave);
    synth.timeM += adder;
    synth.frequencyM = scale.frequencyOf(0 + 3);
    synth.wave(wave);
    synth.timeM += adder;
    synth.frequencyM = scale.frequencyOf(0 + 3 + 4);
    synth.wave(wave);
    synth.timeM += adder;
  }

  wave.normalize(0.75).save();
}