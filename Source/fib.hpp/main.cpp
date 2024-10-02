#include "muxa/fib.hpp"
#include "muxa/types.hpp"
#include <stdexcept>
namespace muxa {
Fib::Fib(u64 modP, u64 sizeP) : memoryM(sizeP) {
  if (sizeP < 2) {
    throw std::runtime_error("fib size < 2");
  }
  memoryM[0] = 0;
  memoryM[1] = 1;
  for (u64 i = 2; i < sizeP; i++) {
    memoryM[i] = memoryM[i - 1] + memoryM[i - 2];
    memoryM[i] %= modP;
  }
}
auto Fib::next(u64 modP) -> u64 {
  u64 next{};
  for (u64 mem : memoryM) {
    next += mem;
    next %= modP;
  }
  for (u64 i = 0; i < memoryM.size() - 1; i++) {
    memoryM[i] = memoryM[i + 1];
  }
  memoryM.back() = next;
  return next;
}
} // namespace muxa