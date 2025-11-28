#if !defined(FADEGLOWMODE_H)
#define FADEGLOWMODE_H
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include <cstdint>
#include "IMode.h"
#include "CommonMode.h"
#include <array>// for std::array
class FadeGlowMode : public CommonMode // MODE 2
{
public:
  FadeGlowMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
    void Execute() override;
};
#endif