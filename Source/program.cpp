#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/wave.hpp"
auto main() -> int {
  muxa::Scale scale;
  muxa::Wave wave(6);
  muxa::Sya synth;
  synth.frequencyM = scale.frequencyOf(0);
  synth.wave(wave);
  synth.timeM += 2;
  synth.frequencyM = scale.frequencyOf(0 + 1);
  synth.wave(wave);
  synth.timeM += 2;
  synth.frequencyM = scale.frequencyOf(0 + 1 + 1);
  synth.wave(wave);
  wave.normalize(0.75).save();
}