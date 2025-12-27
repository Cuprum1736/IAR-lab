#if !defined(USERBUTTON_H)
#define USERBUTTON_H
#include "IButton.h" // for IButton
#include "cstdint" // for uint32_t

class UserButton : public IButton
{
public:
  UserButton(std::uint32_t pinNum, std::uint32_t registerAddress);
  bool WasPressed() const override;
private:
  std::uint32_t mRegisterAddress;
  std::uint32_t mPinNum;
};

#endif