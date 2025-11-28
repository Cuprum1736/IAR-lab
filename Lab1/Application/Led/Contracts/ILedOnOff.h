#if !defined(ILEDTONOFF_H)
#define ILEDTONOFF_H
#include "ILedToggable.h"
#include <array>// for std::array
#include <cstdint>

class ILedOnOff 
{
public:
  virtual void On() const = 0;
  virtual void Off() const = 0;
};
using tLedsOnOff = std::array<ILedOnOff*, ledsCount>;
#endif // ILEDTONOFF_H