#include "muxa/fib.hpp"
#include "muxa/generative/genx0.hpp"
#include "muxa/scales.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include "muxa/waveForms.hpp"
namespace muxa {
Genx0::Genx0() : scaleM(360, 3, 0), fibM(11, 12) {
  leadM.waveFormM = muxa::saw;
  bassM.waveFormM = muxa::saw;
}
auto Genx0::gen() -> Wave {
  u64 notes = 30;
  real time{};
  real step = 1.0 / 11.0 * 2;
  for (u64 i = 0; i < notes; i++) {
    u64 lob = fibM.next(2);
    i64 index = static_cast<i64>(fibM.next(11UL * 2));
    real duration = step * fibM.next(11);
    Note note{index, time, duration, time + duration + bassM.releaseM};
    time += step * fibM.next(11);
    if (lob == 0) {
      note.index -= 11L * 2;
      bassNotesM.push_back(note);
    } else {
      leadNotesM.push_back(note);
    }
  }
  real duration = leadNotesM.back().end;
  if (bassNotesM.back().end > duration) {
    duration = bassNotesM.back().end;
  }
  Wave wave{duration};
  for (auto &note : bassNotesM) {
    bassM.timeM = note.time;
    bassM.frequencyM = scaleM.frequencyOf(note.index);
    bassM.durationM = note.duration;
    bassM.wave(wave);
  }
  for (auto &note : leadNotesM) {
    leadM.timeM = note.time;
    leadM.frequencyM = scaleM.frequencyOf(note.index);
    leadM.durationM = note.duration;
    leadM.wave(wave);
  }
  return wave;
}
} // namespace muxa