#if !defined(ILEDTOGGABLE_H)
#define ILEDTOGGABLE_H
#include <array>// for std::array

class ILedToggable
{
  public:
    virtual void Toggle() const = 0;  //virtual method for using
};
const auto ledsCount = static_cast<std::size_t>(4);
using tLeds = std::array<ILedToggable*, ledsCount>;
#endif // ILEDTOGGABLE_H