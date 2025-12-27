#include <cassert>
#include "RunningLightMode.h"
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff


RunningLightMode::RunningLightMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
    CommonMode(leds, ledsOnOff)
    {
      
    }
void RunningLightMode::RunningLightMode::Execute()
    {
      mLeds[mCurrentLedNumber++]->Toggle();
      if (mCurrentLedNumber == std::size(mLeds))
      {
        mCurrentLedNumber = 0;
      }
    }
  
