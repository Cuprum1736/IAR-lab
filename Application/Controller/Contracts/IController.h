#if !defined(ICONTROLLER_H)
#define ICONTROLLER_H

class IController
{
public:
  virtual void SwitchMode() = 0;
  virtual void RunCurrentMode() = 0;
};

#endif