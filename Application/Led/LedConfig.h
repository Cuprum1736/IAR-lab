#if !defined(LEDCONFIG_H)
#define LEDCONFIG_H
#include "ILedToggable.h"
#include "ILedOnOff.h" // for ILedOnOff
#include "Led.h" // for Led

const auto ledsCount = static_cast<std::size_t>(4);
using tLeds = std::array<ILedToggable*, ledsCount>;
using tLedsOnOff = std::array<ILedOnOff*, ledsCount>;

inline Led led1(5, 0x40020814U);
inline Led led2(8, 0x40020814U);
inline Led led3(9, 0x40020814U);
inline Led led4(5, 0x40020014U);
//OptimizedLed<0x40020014U, 5> led4;

inline tLeds leds = 
{
  &led1,
  &led2,
  &led3,
  &led4
};

inline tLedsOnOff ledsOnOff = 
{
  &led1,
  &led2,
  &led3,
  &led4
};

#endif