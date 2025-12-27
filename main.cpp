#include "iostream"//for std::cout
#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIO?
#include <array>// for std::array
#include "UserButton.h" // for IButton, UserButton
#include "ModeController.h" // for IController, ModeController
#include "ModeConfig.h" // for modes
#include "stkregisters.hpp" // for stk (system timer)
#include "tim2registers.hpp" // for tim2

const std::uint32_t SystemCoreClock = 16000000U; // hsi
const std::uint32_t ticks = SystemCoreClock/1000U-1U;
const std::uint16_t  timPresc = 1U;
const std::uint32_t timPeriod = SystemCoreClock/(timPresc*1000U)-1U;
extern "C" {
int __low_level_init(void)
{
  RCC::CR::HSION::On::Set();
  while (RCC::CR::HSIRDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hsi::Set();
  while (!RCC::CFGR::SWS::Hsi::IsSet())
  {

  }
  //Switch on external 8 MHz oscillator
  /*RCC::CR::HSEON::On::Set();
  while (RCC::CR::HSERDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hse::Set();
  while (!RCC::CFGR::SWS::Hse::IsSet())
  {

  }
  RCC::CR::HSION::Off::Set();

  RCC::PLLCFGR::PLLSRC::HseSource::Set();
  
  RCC::PLLCFGR::PLLN0::Set(64); // n = 64
  RCC::PLLCFGR::PLLP0::Set(3); // p = 8
  RCC::PLLCFGR::FieldValues::Set(2); // m = 2
  
 RCC::CR::PLLON::On::Set();
  while (RCC::CR::PLLRDY::Unclocked::IsSet())
  {

  }
  RCC::CFGR::SW::Pll::Set();
  while (!RCC::CFGR::SWS::Pll::IsSet())
  {

  } //????? ?????????? pll ?? 32 ???*/
  
//  STK::LOAD::RELOAD::Set(ticks);
//  STK::VAL::Write(0);
//  STK::CTRL::CLKSOURCE::Set(0);
//  STK::CTRL::ENABLE::Enable::Set();
  
  RCC::APB1ENR::TIM2EN::Enable::Set();
  
  
  RCC::APB2ENR::SYSCFGEN::Enable::Set();

  return 1;
}
}

bool IsTimeoutExpired()
{
  if (TIM2::SR::UIF::InterruptPending::IsSet())
    {
      TIM2::SR::UIF::Set(0);
      return true;
    }
  return false;
}

void SetTimeout(std::uint32_t delayInms)
{
  TIM2::PSC::Set(timPresc - 1U);
  TIM2::ARR::Write(delayInms * timPeriod); // T = 1*dealayInms
  TIM2::SR::UIF::Set(0);
  TIM2::CNT::Set(0);
  TIM2::CR1::CEN::Set(1);
}

void delay(int cycles)
{
  for(int i = 0; i < cycles; ++i)    
  {
    asm volatile("");
  }    
}

constexpr std::uint32_t buttonPinNum = 13;
constexpr std::uint32_t portCIdrAddress = 0x40020810U;
UserButton userButton(buttonPinNum, portCIdrAddress);

ModeController modeController(modes);

int main()
{ 
 
  //?????? ???????????? ?? ???? ?
  RCC::AHB1ENR::GPIOAEN::Enable::Set() ;
  //?????? ???????????? ?? ???? ?
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
  //????? ?.5 ?? ?????
  GPIOA::MODER::MODER5::Output::Set() ;
  //????? C.5,C.8, C.9 ?? ?????
  GPIOC::MODER::MODER5::Output::Set() ;
  GPIOC::MODER::MODER8::Output::Set() ;
  GPIOC::MODER::MODER9::Output::Set() ;
  
  SetTimeout(200U);
  
  for(;;)
  {  
    if (IsTimeoutExpired())
    {
       if (userButton.WasPressed()) // 50 ms
       {
         modeController.SwitchMode(); 
       }
      modeController.RunCurrentMode();// 200ms
    } 
  }
  return 1;
}