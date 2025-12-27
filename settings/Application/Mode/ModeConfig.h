#if !defined(MODECONFIG_H)
#define MODECONFIG_H
#include "IMode.h"
#include "FadeGlowMode.h" // for FadeGlowMode
#include "ChessMode.h" // for ChessMode
#include "UserButton.h" // for IButton, UserButton
#include "RunningLightMode.h"// for RunningLightMode

const inline std::uint32_t modesCount = 3;
using tModes = std::array<IMode*, modesCount>;

inline RunningLightMode runningLightMode(leds, ledsOnOff);
inline FadeGlowMode fadeGlowMode(leds, ledsOnOff);
inline ChessMode chessMode(leds, ledsOnOff);

inline tModes modes
{
  &runningLightMode,
  &fadeGlowMode,
  &chessMode
};

#endif