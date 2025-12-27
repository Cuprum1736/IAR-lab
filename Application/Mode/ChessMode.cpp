#include "ChessMode.h"
#include <cassert>
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff


ChessMode::ChessMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
  CommonMode(leds, ledsOnOff)
    {
      
    }
void ChessMode::Init()
  {
    mCurrentLedNumber = 0;
    for (auto it: mLedsOnOff)
    {
      mCurrentLedNumber++;
      (mCurrentLedNumber % 2 == 0) ? it->Off() : it->On(); //тернарная операция
    }
  }
void ChessMode::Execute()
  {
    mCurrentLedNumber = 0;
    for(auto it: mLeds)
    {
      mLeds[mCurrentLedNumber++]->Toggle();
      if (mCurrentLedNumber == std::size(mLeds))
      {
        mCurrentLedNumber = 0;
      }
    }
  }