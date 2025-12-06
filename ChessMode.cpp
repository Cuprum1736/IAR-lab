#include <cstdint>
#include "ChessMode.h"
  ChessMode::ChessMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
CommonMode(leds, ledsOnOff)
    {
      
    }
    
/*    void ChessMode::Execute()
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
*/
void ChessMode::Execute()
{
    // Чётные и нечётные позиции
    for (std::size_t i = 0; i < std::size(mLeds); ++i)
    {
        if ((i % 2 == 0) == oddPhase)
            mLedsOnOff[i]->On();
        else
            mLedsOnOff[i]->Off();
    }

    // Переключение фазы
    oddPhase = !oddPhase;
}