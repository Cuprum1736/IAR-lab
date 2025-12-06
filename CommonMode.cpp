#include "CommonMode.h"
#include "Led.h"
#include <cassert>
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff

CommonMode::CommonMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
    mLeds(leds),
    mLedsOnOff(ledsOnOff),
    mCurrentLedNumber(0)
    {
      
    }
void CommonMode::Init()
    {
      mCurrentLedNumber = 0;
      for (auto it: mLedsOnOff)
      {
        it->Off();
      }
    }