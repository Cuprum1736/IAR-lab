#include <cstdint>
#include "FadeGlowMode.h"
FadeGlowMode::FadeGlowMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
CommonMode(leds, ledsOnOff)
    {
      
    }
    
void FadeGlowMode::Execute()
    {
      for(auto it: mLeds)
      {
        mLeds[mCurrentLedNumber++]->Toggle();
        if (mCurrentLedNumber == std::size(mLeds))
        {
          mCurrentLedNumber = 0;
        }
      }
    }