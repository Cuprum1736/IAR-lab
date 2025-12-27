#if !defined(ILEDTONOFF_H)
#define ILEDTONOFF_H
#include <array>// for std::array

class ILedOnOff 
{
public:
  virtual void On() const = 0;
  virtual void Off() const = 0;
};

#endif // ILEDTONOFF_H