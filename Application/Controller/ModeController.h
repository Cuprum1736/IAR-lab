#if !defined(MODECONTROLLER_H)
#define MODECONTROLLER_H
#include "IController.h" // for IController
#include "IMode.h"
#include <cstdint> // for std::uint32_t
#include "ModeConfig.h"// for tModes

class ModeController: public IController
{
public:
  ModeController(const tModes& modes);
    void SwitchMode() override;
    void RunCurrentMode() override;
private:
  const tModes mModes;
  std::uint32_t mCurrentMode;
};

#endif