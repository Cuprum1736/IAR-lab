#if !defined(LED_H)
#define LED_H
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include <cstdint> // for std::uint32_t

class Led: public ILedToggable, public ILedOnOff //child class
  {
  public:
    Led(std::uint32_t pinNum, std::uint32_t registerAddress); //its own method
    void Toggle() const override; 
    void On () const override;
    void Off () const override;
  private:
    std::uint32_t mPinNum;
    std::uint32_t* const mRegisterPtr;
    
  };
  #endif // LED_H