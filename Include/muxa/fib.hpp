#pragma once
#include "muxa/types.hpp"
#include <vector>
namespace muxa {
class Fib {
private:
  std::vector<u64> memoryM;

public:
  explicit Fib(u64 mod, u64 size = 2);
  auto next(u64 mod) -> u64;
};
} // namespace muxa