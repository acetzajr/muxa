#include "muxa/automata/ax0.hpp"
#include "muxa/constants.hpp"
#include "muxa/types.hpp"
#include <Magick++/Color.h>
#include <Magick++/Geometry.h>
#include <magick/magick-type.h>
namespace muxa {
Ax0::Ax0(u64 widthP, u64 heightP, u64 colorsP)
    : lineM(widthP), colorsCountM(colorsP),
      image(Magick::Geometry(widthP, heightP), "white") {
  u64 color{};
  for (u64 y = 0; y < heightP; y++) {
    for (u64 x = 0; x < widthP; x++) {
      if ((x + y) % 2 == 0) {
        color = 0;
      } else {
        color = kColorMax;
      }
      image.pixelColor(x, y, Magick::Color(color, color, color));
    }
  }
  image.write("out/img.png");
}
} // namespace muxa