#if !defined(RUNNINGLIGHTMODE_H)
#define RUNNINGLIGHTMODE_H
#include "CommonMode.h"
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include "LedConfig.h" // for tLeds, tLedsOnOff

class RunningLightMode : public CommonMode // MODE 1
{
public:
  RunningLightMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
  void Execute() override;
};

#endif