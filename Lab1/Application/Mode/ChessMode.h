#if !defined(CHESSMODE_H)
#define CHESSMODE_H
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include <cstdint>
#include "IMode.h"
#include "CommonMode.h"
#include <array>// for std::array
class ChessMode : public CommonMode // MODE 3
{
public:
  ChessMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
    void Execute() override;
    
private:
    bool oddPhase = false;   // Переключение фаз
};
#endif