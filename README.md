# STM32-Encoder
Latching Rotary Encoder Library for STM32 Microcontrollers

This library allows you to use a latching rotary encoder with a STM32 MCU. The code is only useful for slow applications, such as menu navigation by hand etc.


# Installation
Add the Encoder.cpp and the Encoder.hpp to your source / include folder

# Basic Usage
Create an interrupt routine for one of the encoder pins and for the button pin. Configure the other encoder pin as a normal input.

1. Include the Library with 
```C++
#include "Encoder.hpp"
```
2. Create a global Encoder object
```C++
Encoder encoder;
```
3. Call the tick() and setButtonPressed() function in the ISR
```C++
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  __disable_irq();
  if(GPIO_Pin == GPIO_PIN_5)
  {
    encoder.tick(HAL_GPIO_ReadPin(ENC2_GPIO_Port, ENC2_Pin));
  }
  if(GPIO_Pin == GPIO_PIN_15)
  {
    encoder.setButtonPressed();
  }
  __enable_irq();
}
```
The tick function increments or decrements the encoder counter variable starting at 0. Pass the PinState of the second encoder pin so that the library can determine the rotation direction.

4. Evaluate the button press and the encoder counter in the main
```C++
int main() 
{
  // Evaluate current encoder position
  int32_t count = encoder.getCounter();
  
  // Evaluate button press
  if(encoder.getButtonPressed())
  {
    // ...
  }
}
```
# Configuration options
## Rotation Direction
You can flip the counting direction by using
```C++
encoder.setDirection(changeDirection=true);
```
or by defining the direction in the constructor
```C++
Encoder encoder(changeDirection=true);
```
## Counter Set and Reset
You can set the counter variable manually by using
```C++
encoder.setCounter(int32_t value);
```
You can reset the counter variable to 0 by using
```C++
encoder.resetCounter();
```
## Counting Limits
Sometimes it is useful to introduce countig limits, e.g. when creating a menu navigation. You can set the upper and lower counting limit seperately
```C++
encoder.setUpperLimit(int32_t upperLimit);
encoder.setLowerLimit(int32_t lowerLimit);
```
You can reset the counting limits with
```C++
encoder.resetUpperLimit();
encoder.resetLowerLimit();
```
