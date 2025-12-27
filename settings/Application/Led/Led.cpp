#include "Led.h"
#include <cassert>

Led::Led(std::uint32_t pinNum, std::uint32_t registerAddress): //its own method
      mPinNum(pinNum), // number of pin
      mRegisterPtr(reinterpret_cast<std::uint32_t*>(registerAddress)) //address of pins
    {
      
    }
    
    void Led::Toggle() const 
    {
      assert(mPinNum <= 15);
      *mRegisterPtr ^= (1 << mPinNum); //switches on and of using number of pin
    }
    
    void Led::On () const 
    {
      *mRegisterPtr |= (1 << mPinNum);
    }
    void Led::Off () const 
    {
      *mRegisterPtr &= ~(1 << mPinNum);
    }