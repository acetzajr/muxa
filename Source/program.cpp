#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include <iostream>
auto main() -> int {
  std::cout << "Muxa\n";
  muxa::Wave wave(0.0001);
  wave[1][0] = 1.0;
  wave[2][1] = -1.0;
  for (muxa::i64 frameIdx = 0; frameIdx < wave.frames(); frameIdx++) {
    for (muxa::i64 channelIdx = 0; channelIdx < wave.channels(); channelIdx++) {
      std::cout << wave[frameIdx][channelIdx] << " ";
    }
    std::cout << "\n";
  }
}