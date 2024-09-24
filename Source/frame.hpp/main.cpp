#include "muxa/frame.hpp"
#include "muxa/types.hpp"
#include <cstddef>
namespace muxa {
Frame::Frame(double *samplesP, i64 channelsP)
    : samplesM(samplesP), channelsM(channelsP) {}
void Frame::setPointer(double *samplesP) {
  samplesM = samplesP;
  spanM = {samplesP, static_cast<std::size_t>(channelsM)};
}
auto Frame::operator[](i64 channelP) -> double & { return spanM[channelP]; }
} // namespace muxa