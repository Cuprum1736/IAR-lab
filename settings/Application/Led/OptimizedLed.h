#if !defined(OPTIMIZEDLED_H)
#define OPTIMIZEDLED_H
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include <cstdint> // for std::uint32_t

template <std::uint32_t registerAddress, std::uint32_t pinNum>
class OptimizedLed: public ILedToggable, public ILedOnOff //child class
{
public:
  void Toggle() const override
  {
    static_assert(pinNum <= 15, "номер пина не может быть больше 15");
    auto const ptrRegister = reinterpret_cast<volatile std::uint32_t*>(registerAddress);
    *ptrRegister ^= (1U << pinNum);
  }
  void On () const override
  {
    static_assert(pinNum <= 15, "номер пина не может быть больше 15");
    auto const ptrRegister = reinterpret_cast<volatile std::uint32_t*>(registerAddress);
    *ptrRegister |= (1U << pinNum);
  }
  void Off () const override
  {
    static_assert(pinNum <= 15, "номер пина не может быть больше 15");
    auto const ptrRegister = reinterpret_cast<volatile std::uint32_t*>(registerAddress);
    *ptrRegister &= ~(1U << pinNum);
  }
};
#endif // OPTIMIZEDLED_H