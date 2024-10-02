#pragma once
#include "muxa/types.hpp"
#include <Magick++/Image.h>
#include <vector>
namespace muxa {
class Ax0 {
private:
  std::vector<u64> lineM;
  u64 colorsCountM;
  Magick::Image image;

public:
  explicit Ax0(u64 width, u64 height, u64 colors = 11);
};
} // namespace muxa