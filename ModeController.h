#if !defined(MODECONTROLLER_H)
#define MODECONTROLLER_H

#include "IController.h"
#include "IMode.h"       
#include <array>         

const std::uint32_t modesCount = 3;
using tModes = std::array<IMode*, modesCount>;

class ModeController : public IController
{
public:
    ModeController(const tModes& modes);
    void SwitchMode() override;
    void RunCurrentMode() override;

private:
    const tModes mModes;
    std::uint32_t mCurrentMode;
};

#endif // MODECONTROLLER_H