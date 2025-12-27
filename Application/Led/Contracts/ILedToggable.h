#if !defined(ILEDTOGGABLE_H)
#define ILEDTOGGABLE_H
#include <cstdint> // for std::uint32_t
#include <array>// for std::array

class ILedToggable
{
  public:
    virtual void Toggle() const = 0;  //virtual method for using
};

#endif // ILEDTOGGABLE_H