#if !defined(IMODE_H)
#define IMODE_H

class IMode
{
public:
  virtual void Init() = 0;
  virtual void Execute() = 0;
};
#endif