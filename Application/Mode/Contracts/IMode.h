#if !defined(IMODE_H)
#define IMODE_H
#include <array>// for std::array
#include <cstdint> // for std::uint32_t

class IMode
{
public:
  virtual void Init() = 0;
  virtual void Execute() = 0;
};

#endif