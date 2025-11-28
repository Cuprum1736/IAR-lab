#include <cassert>
#include "ModeController.h"

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