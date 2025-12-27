#if !defined(COMMONMODE_H)
#define COMMONMODE_H
#include "IMode.h" //for IMode
#include <cstdint> //for std::uint32_t
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include "LedConfig.h" // for tLeds, for tLedsOnOff

class CommonMode: public IMode
{
public:
  CommonMode(const tLeds& leds, const tLedsOnOff& ledsOnOff);
  void Init() override;
protected:
  const tLeds& mLeds;
  const tLedsOnOff& mLedsOnOff; 
  std::uint32_t mCurrentLedNumber;
};
#endif