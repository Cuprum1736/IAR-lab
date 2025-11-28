#include "UserButton.h"
#include <cstdint>

UserButton::UserButton(std::uint32_t pinNum, std::uint32_t registerAddress)
    : mPinNum(pinNum)
    , mRegisterAddress(registerAddress)
{
  
}

bool UserButton::WasPressed() const
{
    bool isButtonPressed = ((*reinterpret_cast<std::uint32_t*>(mRegisterAddress) & (1U << mPinNum)) == 0);
    return isButtonPressed;
}