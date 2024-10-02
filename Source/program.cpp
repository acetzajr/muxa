#include "muxa/generative/genx0.hpp"
using namespace muxa;
auto main() -> int {
  Genx0 generative;
  generative.gen().reafirm().normalize().save();
}