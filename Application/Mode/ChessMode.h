#if !defined(CHESSMODE_H)
#define CHESSMODE_H
#include "CommonMode.h"
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include "LedConfig.h" // for tLeds, for tLedsOnOff

class ChessMode : public CommonMode // MODE 3
{
public:
  ChessMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
  void Init() override;
  void Execute() override;
};

#endif