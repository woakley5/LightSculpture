//      ******************************************************************
//      *                                                                *
//      *       Subroutines to support fading the LEDs up and down       *
//      *                                                                *
//      *             Stan Reifel                    1/26/13             *
//      *                                                                *
//      ******************************************************************

#include <Arduino.h> 
#include "Fade.h"


//
// global storage for PWM values
//
int ledPwm[lastLEDNumber + 1];


//
//throb table - sinusoidal table normalize for eye linearity with a log function
//
const int throbTable[] PROGMEM = {
0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 
4, 4, 5, 6, 7, 8, 10, 12, 14, 17, 21, 26, 31, 38, 47, 57, 
70, 85, 104, 126, 153, 185, 222, 266, 316, 375, 441, 516, 599, 691, 791, 899, 
1012, 1130, 1250, 1370, 1487, 1599, 1702, 1793, 1870, 1931, 1972, 1993, 1993, 1972, 1931, 1870, 
1793, 1702, 1599, 1487, 1370, 1250, 1130, 1012, 899, 791, 691, 599, 516, 441, 375, 316, 
266, 222, 185, 153, 126, 104, 85, 70, 57, 47, 38, 31, 26, 21, 17, 14, 
12, 10, 8, 7, 6, 5, 4, 4, 3, 3, 2, 2, 2, 2, 2, 1, 
1, 1, 1, 1, 0, 0, 0, 0};


//------------------------------------------------------------------------


//
// constructor for the Fade class
//
Fade::Fade()
{
  //
  // configure the on/off switch as an input
  //
  pinMode(onOffSwitch, INPUT_PULLUP);
}


//------------------------------------------------------------------------
//                            Fading Up Subroutines
//------------------------------------------------------------------------

//
// fade up one or more LEDs, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            led1, led2, led3... = LED numbers to fade up
//
void Fade::up(int fadeSpeed, int led1)
{
  up(fadeSpeed, led1, 0, 0, 0, 0, 0, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2)
{
  up(fadeSpeed, led1, led2, 0, 0, 0, 0, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3)
{
  up(fadeSpeed, led1, led2, led3, 0, 0, 0, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3, int led4)
{
  up(fadeSpeed, led1, led2, led3, led4, 0, 0, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5)
{
  up(fadeSpeed, led1, led2, led3, led4, led5, 0, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6)
{
  up(fadeSpeed, led1, led2, led3, led4, led5, led6, 0, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7)
{
  up(fadeSpeed, led1, led2, led3, led4, led5, led6, led7, 0);
}

void Fade::up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8)
{ 
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  unsigned char ledNum;
  int throbTableHalfLength;
  
  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);
  
  
  //
  // start with a PWM value for each LED set to 0, so LEDs no included in this 
  // fade will remain unchanged
  //
  for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }
  
  //
  // loop to fade one or more LEDs up
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = 0; tableIndex < throbTableHalfLength; tableIndex += tableStep)
  { 
    pwm = pgm_read_word(&throbTable[tableIndex]);
    ledPwm[led1] = pwm;
    ledPwm[led2] = pwm;
    ledPwm[led3] = pwm;
    ledPwm[led4] = pwm;
    ledPwm[led5] = pwm;
    ledPwm[led6] = pwm;
    ledPwm[led7] = pwm;
    ledPwm[led8] = pwm;
    
    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }
  
  //
  // after the fade, leave the LEDs turned on
  //
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}


//
// fade up all the LEDs
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::up(int fadeSpeed)
{
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  unsigned char ledNum;
  int throbTableHalfLength;
  
  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);
  
 
  //
  // loop to fade up all the LEDs
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = 0; tableIndex < throbTableHalfLength; tableIndex += tableStep)
  { 
    pwm = pgm_read_word(&throbTable[tableIndex]);
    
    for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
    {
      ledPwm[ledNum] = pwm;
    }
    
    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }
  

  //
  // after the fade, leave the LEDs turned on
  //
  for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
  {
    digitalWrite(ledNum, HIGH);
  }
}


//------------------------------------------------------------------------
//                            Fading Down Subroutines
//------------------------------------------------------------------------

//
// fade down one or more LEDs, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            led1, led2, led3... = LED numbers to fade down
//
void Fade::down(int fadeSpeed, int led1)
{
  down(fadeSpeed, led1, 0, 0, 0, 0, 0, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2)
{
  down(fadeSpeed, led1, led2, 0, 0, 0, 0, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3)
{
  down(fadeSpeed, led1, led2, led3, 0, 0, 0, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3, int led4)
{
  down(fadeSpeed, led1, led2, led3, led4, 0, 0, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5)
{
  down(fadeSpeed, led1, led2, led3, led4, led5, 0, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6)
{
  down(fadeSpeed, led1, led2, led3, led4, led5, led6, 0, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7)
{
  down(fadeSpeed, led1, led2, led3, led4, led5, led6, led7, 0);
}

void Fade::down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8)
{
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  byte ledNum;
  int throbTableHalfLength;
  
  //
  // start with a PWM value for each LED set to 0, so LEDs no included in this 
  // fade will remain unchanged
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);
  
  
  //
  // set the PWM value for every LED to 0 so it will be unchanged
  //
  for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }
  
  //
  // loop to fade one or more LEDs down
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = throbTableHalfLength; tableIndex >= 0; tableIndex -= tableStep)
  { 
    pwm = pgm_read_word(&throbTable[tableIndex]);
    ledPwm[led1] = pwm;
    ledPwm[led2] = pwm;
    ledPwm[led3] = pwm;
    ledPwm[led4] = pwm;
    ledPwm[led5] = pwm;
    ledPwm[led6] = pwm;
    ledPwm[led7] = pwm;
    ledPwm[led8] = pwm;
    
    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }
  
  //
  // after the fade, leave the LED turned off
  //
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
}



//
// fade down all the LEDs
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::down(int fadeSpeed)
{
  int tableStep;
  int PWMCycleCount;
  int tableIndex;
  int pwm;
  unsigned char ledNum;
  int throbTableHalfLength;
  
  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);
  
 
  //
  // loop to fade down all the LEDs
  //
  throbTableHalfLength = getThrobTableHalfLength();
  for(tableIndex = throbTableHalfLength; tableIndex >= 0; tableIndex -= tableStep)
  { 
    pwm = pgm_read_word(&throbTable[tableIndex]);
    for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
    {
      ledPwm[ledNum] = pwm;
    }
    
    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
  }
  

  //
  // after the fade, leave the LEDs turned off
  //
  turnOffAllLEDs();
}


//------------------------------------------------------------------------
//                         Cross Fading Subroutines
//------------------------------------------------------------------------

//
// fade one LED up and at the same time fade a different LED down, LEDs not specified are not changed
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//            Up1, Up2, Up3... = the LED numbers to fade up
//            Down1, Down2, Down3... = the LED numbers to fade down
//
void Fade::crossFade(int fadeSpeed, int up1, int down1)
{
  crossFade(fadeSpeed, up1, down1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2)
{
  crossFade(fadeSpeed, up1, down1, up2, down2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3)
{
  crossFade(fadeSpeed, up1, down1, up2, down2, up3, down3, 0, 0, 0, 0, 0, 0, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4)
{
  crossFade(fadeSpeed, up1, down1, up2, down2, up3, down3, up4, down4, 0, 0, 0, 0, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5)
{
  crossFade(fadeSpeed, up1, down1, up2, down2, up3, down3, up4, down4, up5, down5, 0, 0, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5, int up6, int down6)
{
  crossFade(fadeSpeed, up1, down1, up2, down2, up3, down3, up4, down4, up5, down5, up6, down6, 0, 0);
}

void Fade::crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5, int up6, int down6, int up7, int down7)
{
  int tableStep;
  int PWMCycleCount;
  int upTableIndex;
  int downTableIndex;
  int pwm;
  unsigned char ledNum;
  int throbTableHalfLength;
  
  //
  // use the "fadeSpeed" value to compute how long the LEDs are on for each PWM cycle
  // and how quickly to step through the throb table
  //
  getFadeSpeedValues(fadeSpeed, &PWMCycleCount, &tableStep);
  
  
  //
  // start with a PWM value for each LED set to 0, so LEDs no included in this 
  // fade will remain unchanged
  //
  for (ledNum = firstLEDNumber; ledNum <= lastLEDNumber; ledNum++)
  {
    ledPwm[ledNum] = 0;
  }
  
  //
  // loop to fade LEDs
  //
  throbTableHalfLength = getThrobTableHalfLength();
  downTableIndex = throbTableHalfLength;
  for(upTableIndex = 0; upTableIndex < throbTableHalfLength; upTableIndex += tableStep)
  { 
    pwm = pgm_read_word(&throbTable[upTableIndex]);
    ledPwm[up1] = pwm;
    ledPwm[up2] = pwm;
    ledPwm[up3] = pwm;
    ledPwm[up4] = pwm;
    ledPwm[up5] = pwm;
    ledPwm[up6] = pwm;
    ledPwm[up7] = pwm;
    
    pwm = pgm_read_word(&throbTable[downTableIndex]);
    ledPwm[down1] = pwm;
    ledPwm[down2] = pwm;
    ledPwm[down3] = pwm;
    ledPwm[down4] = pwm;
    ledPwm[down5] = pwm;
    ledPwm[down6] = pwm;
    ledPwm[down7] = pwm;

    //
    // now turn on the LEDs for a short period with their PWM value
    //
    pwmAllPins(PWMCycleCount);
    
    downTableIndex -= tableStep;
  }
  
  //
  // after the fade, turn the downs off, and the ups on
  //
  digitalWrite(up1, HIGH);
  digitalWrite(up2, HIGH);
  digitalWrite(up3, HIGH);
  digitalWrite(up4, HIGH);
  digitalWrite(up5, HIGH);
  digitalWrite(up6, HIGH);
  digitalWrite(up7, HIGH);
  digitalWrite(down1, LOW);
  digitalWrite(down2, LOW);
  digitalWrite(down3, LOW);
  digitalWrite(down4, LOW);
  digitalWrite(down5, LOW);
  digitalWrite(down6, LOW);
  digitalWrite(down7, LOW);
}


//------------------------------------------------------------------------
//                            Night Light Subroutines
//------------------------------------------------------------------------

//
// display all the LEDs using a brightness set by the knob, as long as the knob is in zone 3
//
void Fade::nightLightModeWhileInZoneThree()
{ int knobZone;
  int knobZoneValue;
  int pwm;
  int ledNumber;
  int tableIndex;

  while(true)
  {
    //
    // check if the knob is not in zone 3, if not then return
    //
    knobZone = getKnobPosition(&knobZoneValue);
    if (knobZone != 3)
    {
      return;
    }
    
    //
    // determine a PWM value from the knob
    //
    tableIndex = map(knobZoneValue, 0, 320, 0, getThrobTableHalfLength());
    pwm = pgm_read_word(&throbTable[tableIndex]);

    //
    // set the LED brightness
    //
    for (ledNumber = firstLEDNumber; ledNumber <= lastLEDNumber; ledNumber++)
    {
      ledPwm[ledNumber] = pwm;
    }
    pwmAllPins(1);
  }  
}


//------------------------------------------------------------------------
//                             Knob Subroutines
//------------------------------------------------------------------------

//
// return the state of the user mode
//    Exit:  0 returned if on/off switch in the off position
//           1 returned if in the left zone
//           2 returned if in the middle zone
//           3 returned if in the right zone
//           -1 returned if in the no zone
//
int Fade::getKnobPosition()
{ int ZoneValue;

  return(getKnobPosition(&ZoneValue));
}


//
// return the state of the user mode
//    Exit:  0 returned if on/off switch in the off position
//           1 returned if in the left zone
//           2 returned if in the middle zone
//           3 returned if in the right zone
//           -1 returned if in the no zone
//          *ZoneValue = where in the zone the knob is in (0 to 330)
//
int Fade::getKnobPosition(int *ZoneValue)
{ int analogValue;
  const int ZoneWidth = 330;
  const int startOfZoneOne = 0;
  const int startOfZoneTwo = (1023 / 2) - (ZoneWidth / 2);
  const int startOfZoneThree = 1023 - ZoneWidth;


  //
  // check if the on/off switch is off
  // 
  if (digitalRead(onOffSwitch) == HIGH)
  {
    *ZoneValue = 0;
    turnOffAllLEDs();
    return(0);
  }
  
  //
  // switch is on, read the pot position
  //
  analogValue = analogRead(5);


  //
  // determine what zone the knob is in
  //
  if ((analogValue >= startOfZoneOne) && (analogValue <= startOfZoneOne + ZoneWidth))
  {
    *ZoneValue = analogValue - startOfZoneOne;
    return(1);
  }
  
  if ((analogValue >= startOfZoneTwo) && (analogValue <= startOfZoneTwo + ZoneWidth))
  {
    *ZoneValue = analogValue - startOfZoneTwo;
    return(2);
  }
  
  if ((analogValue >= startOfZoneThree) && (analogValue <= startOfZoneThree + ZoneWidth))
  {
   *ZoneValue = analogValue - startOfZoneThree;
   return(3);
  }
  
  *ZoneValue = 0;
  turnOffAllLEDs();
  return(-1);
}


//------------------------------------------------------------------------
//                           Support Subroutines
//------------------------------------------------------------------------

//
// turn off all the LEDs
//
void Fade::turnOffAllLEDs()
{
  int ledNumber;
  
  for (ledNumber = firstLEDNumber; ledNumber <= lastLEDNumber; ledNumber++)
  {
    digitalWrite(ledNumber, LOW);
  }  
}



//
// use the "fadeSpeed" value to compute how long the LEDs are on for 
// each PWM cycle and how quickly to step through the throb table
//    Enter:  fadeSpeed = a speed value of how fast to fade (1 to 10, 10 being the fastest)
//
void Fade::getFadeSpeedValues(int fadeSpeed, int *PWMCycleCount, int *tableStep)
{
  switch(fadeSpeed)
  {
    case 10:
    {
      *PWMCycleCount = 1;
      *tableStep = 10;
      break;
    }
    
    case 9:
    {
      *PWMCycleCount = 1;
      *tableStep = 8;
      break;
    }
    
    case 8:
    {
      *PWMCycleCount = 1;
      *tableStep = 6;
      break;
    }
    
    case 7:
    {
      *PWMCycleCount = 1;
      *tableStep = 4;
      break;
    }
    
    case 6:
    {
      *PWMCycleCount = 1;
      *tableStep = 3;
      break;
    }
    
    case 5:
    {
      *PWMCycleCount = 1;
      *tableStep = 2;
      break;
    }
    
    case 4:
    {
      *PWMCycleCount = 1;
      *tableStep = 1;
      break;
    }
    
    case 3:
    {
      *PWMCycleCount = 2;
      *tableStep = 1;
      break;
    }
    
    case 2:
    {
      *PWMCycleCount = 3;
      *tableStep = 1;
      break;
    }
    
    case 1:
    {
      *PWMCycleCount = 5;
      *tableStep = 1;
      break;
    }
    
    default:
    {
      *PWMCycleCount = 1;
      *tableStep = 1;
      break;
    }
  }
}
  
  
  
//
// get the length of the throb table (the size of the array)
//
int Fade::getThrobTableLength()
{
  return(sizeof(throbTable) / sizeof(int));
}
  
  
  
//
// get the length of the throb table (the size of the array)
//
int Fade::getThrobTableHalfLength()
{
  return((sizeof(throbTable) / sizeof(int)) / 2);
}



//
// PWM all pins with a value between 0 and 2000, for aprox n milliseconds
//    Enter:  ledPwm[] contains the array of PWM values, corresponding to each LED
//            PWMCycleCount = number of times the PWM should by cycled.  Typical values
//              are 1 or 2 or 3
//
void Fade::pwmAllPins(int PWMCycleCount)
{ int i;
  int j;
  int onTime;
    
  for (j = 0; j < PWMCycleCount; j++)
  { //
    // turn on all LEDS that have a PWM value greater than 0
    //
    if (ledPwm[2]) bitSet(PORTD, 2); 
    if (ledPwm[3]) bitSet(PORTD, 3); 
    if (ledPwm[4]) bitSet(PORTD, 4); 
    if (ledPwm[5]) bitSet(PORTD, 5); 
    if (ledPwm[6]) bitSet(PORTD, 6); 
    if (ledPwm[7]) bitSet(PORTD, 7);
    if (ledPwm[8]) bitSet(PORTB, 0); 
    if (ledPwm[9]) bitSet(PORTB, 1); 
    if (ledPwm[10]) bitSet(PORTB, 2);  
    if (ledPwm[11]) bitSet(PORTB, 3);  
    if (ledPwm[12]) bitSet(PORTB, 4); 
    if (ledPwm[13]) bitSet(PORTB, 5); 
    if (ledPwm[14]) bitSet(PORTC, 0); 
    if (ledPwm[15]) bitSet(PORTC, 1); 
   
    //
    // loop for one PWM cycle, turning off each LED at the right PWM value
    //
    for (i = 1; i <= 2000; i++)
    { if (i == ledPwm[2]) bitClear(PORTD, 2);
      if (i == ledPwm[3]) bitClear(PORTD, 3);
      if (i == ledPwm[4]) bitClear(PORTD, 4);
      if (i == ledPwm[5]) bitClear(PORTD, 5);
      if (i == ledPwm[6]) bitClear(PORTD, 6);
      if (i == ledPwm[7]) bitClear(PORTD, 7);
      if (i == ledPwm[8]) bitClear(PORTB, 0);
      if (i == ledPwm[9]) bitClear(PORTB, 1);
      if (i == ledPwm[10]) bitClear(PORTB, 2);
      if (i == ledPwm[11]) bitClear(PORTB, 3);
      if (i == ledPwm[12]) bitClear(PORTB, 4);
      if (i == ledPwm[13]) bitClear(PORTB, 5);
      if (i == ledPwm[14]) bitClear(PORTC, 0);
      if (i == ledPwm[15]) bitClear(PORTC, 1);
    }
  }
}


