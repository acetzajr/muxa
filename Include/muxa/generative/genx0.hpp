#pragma once
#include "muxa/fib.hpp"
#include "muxa/scales.hpp"
#include "muxa/synths/sya.hpp"
#include "muxa/types.hpp"
#include "muxa/wave.hpp"
#include <list>
namespace muxa {
struct Note {
  i64 index;
  real time;
  real duration;
  real end;
};
class Genx0 {
private:
  Sya leadM;
  Sya bassM;
  Scale scaleM;
  Fib fibM;
  std::list<Note> leadNotesM;
  std::list<Note> bassNotesM;

public:
  Genx0();
  auto gen() -> Wave;
};
} // namespace muxa