#include "iostream"//for std::cout
#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIOС
#include <array>// for std::array
#include "Led.h" // for Led, ILedToggable, ILedOnOff
#include "OptimizedLed.h" // for OptimizedLed
#include "CommonMode.h" //for CommonMode
#include "RunningLightMode.h" // for RunningLightMode
#include "FadeGlowMode.h" // for FadeGlowMode
#include "ChessMode.h" // for ChessMode
#include "UserButton.h" // for UserButton
#include "ModeController.h" // for ModeController


std::uint32_t SystemCoreClock = 16'000'000U;

extern "C" {
int __low_level_init(void)
{
  //Switch on external 16 MHz oscillator
  RCC::CR::HSION::On::Set();
  while (RCC::CR::HSIRDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hsi::Set();
  while (!RCC::CFGR::SWS::Hsi::IsSet())
  {

  }
  
  RCC::APB2ENR::SYSCFGEN::Enable::Set();

  return 1;
}
}

void delay(int cycles)
{
  for(int i = 0; i < cycles; ++i)    
  {
    asm volatile("");
  }    
}
///////////////////////////// ON/OFF LED /////////////////////////////

///////////////////////// BUTTON //////////////////
/*class IButton
{
public:
  virtual bool WasPressed() const = 0;
};
*/
/*class UserButton : public IButton
{
public:
  UserButton(std::uint32_t pinNum, std::uint32_t registerAddress):
    mPinNum(pinNum),
    mRegisterAddress(registerAddress)
    {
    
    }
  bool WasPressed() const override
  {
    bool isButtonPressed = ((*reinterpret_cast<std::uint32_t*>(mRegisterAddress) & (1 << mPinNum)) == 0);
    return isButtonPressed;
  }
private:
  std::uint32_t mRegisterAddress;
  std::uint32_t mPinNum;
};
*/

///////////////////////////////////// MODES FOR LEDS ///////////////////////
   
/*class IMode
{
public:
  virtual void Init() = 0;
  virtual void Execute() = 0;
};
*/
//const auto ledsCount = static_cast<std::size_t>(4);
//using tLeds = std::array<ILedToggable*, ledsCount>;
//using tLedsOnOff = std::array<ILedOnOff*, ledsCount>;

/*class CommonMode: public IMode
{
public:
  CommonMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
    mLeds(leds),
    mLedsOnOff(ledsOnOff),
    mCurrentLedNumber(0)
    {
      
    }
    void Init() override
    {
      mCurrentLedNumber = 0;
      for (auto it: mLedsOnOff)
      {
        it->Off();
      }
    }
protected:
  const tLeds& mLeds;
  const tLedsOnOff& mLedsOnOff; 
  std::uint32_t mCurrentLedNumber;
};
*/
/*class RunningLightMode : public CommonMode // MODE 1
{
public:
  RunningLightMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
    CommonMode(leds, ledsOnOff)
    {
      
    }
    void Execute() override
    {
      mLeds[mCurrentLedNumber++]->Toggle();
      if (mCurrentLedNumber == std::size(mLeds))
      {
        mCurrentLedNumber = 0;
      }
    }
};
*/
/*class FadeGlowMode : public CommonMode // MODE 2
{
public:
  FadeGlowMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
CommonMode(leds, ledsOnOff)
    {
      
    }
    
    void Execute() override
    {
      for(auto it: mLeds)
      {
        mLeds[mCurrentLedNumber++]->Toggle();
        if (mCurrentLedNumber == std::size(mLeds))
        {
          mCurrentLedNumber = 0;
        }
      }
    }
};*/
/*class ChessMode : public CommonMode // MODE 3
{
public:
  ChessMode(const tLeds& leds, const tLedsOnOff& ledsOnOff):
CommonMode(leds, ledsOnOff)
    {
      
    }
    
    void Execute() override
 {
    for (std::size_t i = 0; i < std::size(mLeds); ++i)
    {
        if ((i % 2 == 0) == oddPhase)
            mLedsOnOff[i]->On();
        else
            mLedsOnOff[i]->Off();
    }
    oddPhase = !oddPhase;
}
};
*/
////////////////////////MODE SWITCHER///////////////

/*class IController
{
public:
  virtual void SwitchMode() = 0;
  virtual void RunCurrentMode() = 0;
};
*/
//const std::uint32_t modesCount = 3;
//using tModes = std::array<IMode*, modesCount>;

/*class ModeController: public IController
{
public:
  ModeController(const tModes& modes):
    mModes(modes),
    mCurrentMode(0)
    {
      
    }
    void SwitchMode() override
    {
      mCurrentMode++;
        if (mCurrentMode == std::size(mModes))
        {
          mCurrentMode = 0;
        }
        mModes[mCurrentMode]->Init();
    }
    void RunCurrentMode() override
    {
      mModes[mCurrentMode]->Execute();
    }
private:
  const tModes mModes;
  std::uint32_t mCurrentMode;
};
*/
////////////////////////////////
/*class TestDynamic
{
public:
  int GetI() {return i;}
private:
  int i = 0;
};
*/
constexpr std::uint32_t buttonPinNum = 13;
constexpr std::uint32_t portCIdrAddress = 0x40020810U;
UserButton userButton(buttonPinNum, portCIdrAddress);

Led led1(5, 0x40020814U);
Led led2(8, 0x40020814U);
Led led3(9, 0x40020814U);
//Led led4(5, 0x40020014U);
OptimizedLed<0x40020014U, 5> led4;

tLeds leds = 
{
  &led1,
  &led2,
  &led3,
  &led4
};

tLedsOnOff ledsOnOff = 
{
  &led1,
  &led2,
  &led3,
  &led4
};

RunningLightMode runningLightMode(leds, ledsOnOff);
FadeGlowMode fadeGlowMode(leds, ledsOnOff);
ChessMode chessMode(leds, ledsOnOff);

tModes modes
{
  &runningLightMode,
  &fadeGlowMode,
  &chessMode
};

ModeController modeController(modes);

int main()
{ 
 
  //Подать тактирование на порт А
  RCC::AHB1ENR::GPIOAEN::Enable::Set() ;
  //Подать тактирование на порт С
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
  //Порта А.5 на вывод
  GPIOA::MODER::MODER5::Output::Set() ;
  //Порта C.5,C.8, C.9 на вывод
  GPIOC::MODER::MODER5::Output::Set() ;
  GPIOC::MODER::MODER8::Output::Set() ;
  GPIOC::MODER::MODER9::Output::Set() ;
  
  for(;;)
  {   
    if (userButton.WasPressed())
    {
      modeController.SwitchMode(); 
    }
    delay(500000);
    modeController.RunCurrentMode(); 
    
  
  
     //GPIOA::ODR::ODR5::High::Set();
     //GPIOC::ODR::ODR5::High::Set();
     //GPIOA::ODR::ODR5::Low::Set();
     //GPIOC::ODR::ODR5::Low::Set();
  }
  return 1;
}

