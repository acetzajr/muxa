#include "muxa/frame.hpp"
#include "muxa/types.hpp"
#include <cstddef>
namespace muxa {
Frame::Frame(real *samplesP, i64 channelsP)
    : samplesM(samplesP), channelsM(channelsP) {}
void Frame::setPointer(real *samplesP) {
  samplesM = samplesP;
  spanM = {samplesP, static_cast<std::size_t>(channelsM)};
}
auto Frame::operator[](i64 channelP) -> real & { return spanM[channelP]; }
} // namespace muxa