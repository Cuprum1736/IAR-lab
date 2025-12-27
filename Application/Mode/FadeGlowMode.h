#if !defined(FADEGLOWMODE_H)
#define FADEGLOWMODE_H
#include "CommonMode.h"
#include "ILedToggable.h" // for leds
#include "ILedOnOff.h" // for ledsOnOff
#include "LedConfig.h" // for tLeds, for tLedsOnOff

class FadeGlowMode : public CommonMode // MODE 2
{
public:
  FadeGlowMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
  void Execute() override;
};

#endif