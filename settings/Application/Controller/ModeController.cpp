#include "ModeController.h"
#include "IMode.h"
#include <cassert>
#include "IController.h" // for IController
#include "ILedToggable.h" // for ILedToggable
#include "ILedOnOff.h" // for ILedOnOff
#include "LedConfig.h"

ModeController::ModeController(const tModes& modes):
    mModes(modes),
    mCurrentMode(0)
    {
      
    }
    void ModeController::SwitchMode() 
{
  mCurrentMode++;
    if (mCurrentMode == std::size(mModes))
    {
      mCurrentMode = 0;
    }
    mModes[mCurrentMode]->Init();
}
void ModeController::RunCurrentMode() 
{
  mModes[mCurrentMode]->Execute();
}