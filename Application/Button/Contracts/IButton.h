#if !defined(IBUTTON_H)
#define IBUTTON_H

class IButton
{
public:
  virtual bool WasPressed() const = 0;
};

#endif