#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include <iostream>
auto main() -> int {
  std::cout << "Muxa\n";
  muxa::Wave wave(4);
  muxa::Sya synth;
  synth.wave(wave);
  muxa::Scale::test();
}