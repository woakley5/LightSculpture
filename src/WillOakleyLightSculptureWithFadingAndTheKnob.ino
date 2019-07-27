
//      ******************************************************************
//      *                                                                *
//      *     Arduino program light display for the Light sculpture      *
//      *                                                                *
//      *           Will Oakley                   05/6/15                *
//      *                                                                *
//      ******************************************************************

//
// DO NOT EDIT setup, or loop in this program!!
//
//  Your modifications should be made in the following locations:
//
// 0. Make sure you have REPLACED the YourFirstLastName with your actual FirstLastName of this file and the folder 
// 
// 1. Edit the Title Block above and replace YourNameGoesHere with your FirstLastName AND ENTER TodaysDate
//
// 2. Adding your own LightShow function definitions in the LightShow function definitions area
//
// 3. Adding your own BackgroundShow function definitions in the BackgroundShow function definitions area
//
// 4. Begin entering LightShow function calls in the LightShow Funtion Calls Area inside the runLightShow function definition
//
// 5. Begin entering BackgroundShow function calls in the BackgroundShow Funtion Calls Area inside the runBackgroundShow function definition
//
// 6. Create new function definitions and function calls to the above areas to complete your light sculpture program.
//
// 7. Feel free to modify or remove the example function definitions listed below:
//
//         ShowAllTheColors(1000,2000,6);
//         SlowlyBlinkEachLedOneAtATime(100,100,6);
//         fadeUpAndDownOneLEDAtATimeGoingClockwise(100,100,6,4);
//         fadeUpAndDownRightAndLeft(100,100,6,4);
//
//  LEAVE EVERYTHING ELSE AS IT IS. 
//
//                          MR. HARLOW
//
//

#include "Fade.h"
Fade fade;

//
// top level setup function
//
void setup()
{  
  Serial.begin(9600); // Open serial monitor at 9600 baud for debuging using Serial.print Commands
  Serial.println("");       // prints a new line
  Serial.print("Begining setup"); // prints "Begining setup" to the screen
  Serial.println("");       // prints a new line

  int pinNum;

  //
  // configure the LED pins as outputs
  //
  for(pinNum = 2; pinNum <= 15; pinNum++)
  {
    pinMode(pinNum, OUTPUT); 
    Serial.print("pinNum  "); // prints "pinNum" to the screen
    Serial.print(pinNum);     // prints the VALUE of pinNum to the screen
    Serial.println("");       // prints a new line 
  } 

  Serial.println("Setup Complete"); // prints "Setup Complete" to the screen

}

//
// select the displays using the position of the knob
//
void loop()
{ 
  int knobZoneNumber;

  //
  // get the zone number that the knob is in:
  //  0 = off, 1 = light show, 2 = background, 3 = nightlight
  //
  knobZoneNumber = fade.getKnobPosition();

  //
  // run the light show if knob in zone 1
  //
  if (knobZoneNumber == 1)
  {
    runLightShow();
  }

  //
  // run the background show if knob in zone 2
  //
  if (knobZoneNumber == 2)
  {
    runBackgroundShow();
  }

  //
  // run the nightlight if knob in zone 3
  //
  if (knobZoneNumber == 3)
  {
    fade.nightLightModeWhileInZoneThree();
  }
}


//
// LightShow Funtion Calls Area
//
// run the "LightShow" while the knob is in zone 1
//
// THIS SHOULD be a list of function calls to functions defined in the LightShow function definitions area
//
//
void runLightShow()
{
  Serial.print("Light Show Beginning");
  Serial.println("");
  LEDsChasing(100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  buildOnEachRow(100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  LEDsSlideTogether(100,0,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  swoopUpThenDown(20,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  allLEDsBlink(100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  inverseChasing(100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  fourQuadrants(200,200,200,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  LEDsOnOutwards(200,100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  LEDsOnInwards(100,200,200,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  bounceUp(50,100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  bounceUpThenInverse(50,100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  zigZagAccross(300,0,3);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  groupOfThree(200,0,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  eachWaveOn(100,100,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  LEDsOnInwards(100,200,200,5);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  SlowlyBlinkEachLedOneAtATime(100,100,6);
  if (fade.getKnobPosition() != 1) return;   // return if not in LightShow mode
  Serial.print("Light Show Complete");
  Serial.println("");
  delay(2000);
}



//
// BackgroundShow Funtion Calls Area
//
// run the "Background Show" while the knob is in zone 2
//
// THIS SHOULD be a list of function calls to functions defined in the BackgroundShow function definitions area
//
void runBackgroundShow()
{
  Serial.print("Background Show Beginning");
  Serial.println("");
  fadeBuildUpOpposite(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  fadeBuildUpTogether(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  fadeOutwards(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  fadeUpAndDownOneLEDAtATimeGoingClockwise(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  fadeTwoTogether(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode]
  pulseFade(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode]
  fadeUpAndDownRightAndLeft(100,100,1,2);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  Serial.print("Background Show Complete");
  Serial.println("");
  delay(2000);  
}


//------------------------------------------------------------------------
//                        LightShow function definitions
//------------------------------------------------------------------------
// ALL your function definitions for LightShow should be entered here!!
//
void LEDsChasing(int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("LEDs Chasing");
  Serial.println("");
  int LEDNumber[7] = { 
    2,3,4,5,6,7,8   };
  int otherLEDNumber[7] = { 
    15,14,13,12,11,10,9      };
  int index;
  int repeat;
  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(index = 0; index < 7; index++)
    {
      digitalWrite(LEDNumber[index], HIGH);
      digitalWrite(otherLEDNumber[index], HIGH);
      delay(LEDOnTime);
      digitalWrite(LEDNumber[index], LOW);
      digitalWrite(otherLEDNumber[index], LOW);
      
    }
  }
}

void buildOnEachRow(int LEDOnTime, int LEDStayOnTime, int RepeatCount) 
{
  Serial.print("Build on Each Row");
  Serial.println("");
  int LEDNumber[7] = {
    2,3,4,5,6,7,8    };
  int otherLEDNumber[7] = {
    15,14,13,12,11,10,9   };
  int index;
  int repeat;
  int finalIndex = 6;

  for(repeat = 1; repeat <= RepeatCount; repeat++) //Loop that keeps track of repeats
  {
    finalIndex = 6;
    while(finalIndex >= 0){ //While the final Index is greater than 0
      for(index = 0; index <= finalIndex; index++) //Each individual Slide up, final index will decrease each time this completes
      {
        digitalWrite(LEDNumber[index], HIGH);
        digitalWrite(otherLEDNumber[index], HIGH);
        delay(LEDOnTime);
        if(index != finalIndex) //If the index is not equal to the final index than turn the LED off
        {
          digitalWrite(LEDNumber[index], LOW);
          digitalWrite(otherLEDNumber[index], LOW);
        }
        else{ //If the index is equal, keep the final LED's on, decrease the final index and repeat the loop from the first for loop.
          finalIndex = finalIndex - 1;
        }
      } 
    }
    delay(LEDStayOnTime); //Holds all LED's on once all are turned on
    for(index = 0 ; index <= 6; index++) // Turns off all led's in sequence they were turned on but backwards
    {
      delay(LEDOnTime);
      digitalWrite(LEDNumber[index], LOW);
      digitalWrite(otherLEDNumber[index], LOW);
    }
  }
}

void swoopUpThenDown(int delayIncrement,int ledOnTime, int RepeatCount)
{
  Serial.print("Swoop up then down");
  Serial.println("");
  int LEDNumberYellow[7] = { 
    8,7,6,5,4,3,2          };
  int LEDNumberBlue[7] = { 
    9,10,11,12,13,14,15          }; 
  int index;
  int repeat;
  int increasingDelay;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    index = 0;
    while(index < 7)
    {
      for(increasingDelay = delayIncrement; increasingDelay <= delayIncrement * 7; increasingDelay = increasingDelay + delayIncrement)
      {
        digitalWrite(LEDNumberYellow[index], HIGH);
        digitalWrite(LEDNumberBlue[index], HIGH);
        delay(increasingDelay);
        digitalWrite(LEDNumberYellow[index], LOW);
        digitalWrite(LEDNumberBlue[index], LOW);
        index++;
      }
    }
    index = 6;
    while(index >= 0)
    {
      for(increasingDelay = delayIncrement * 7; increasingDelay >= delayIncrement; increasingDelay = increasingDelay - delayIncrement)
      {
        digitalWrite(LEDNumberYellow[index], HIGH);
        digitalWrite(LEDNumberBlue[index], HIGH);
        delay(increasingDelay);
        digitalWrite(LEDNumberYellow[index], LOW);
        digitalWrite(LEDNumberBlue[index], LOW);
        index--;
      }
    }
  }
}

void allLEDsBlink(int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("All LED's Blink");
  Serial.println("");
  int repeat;
  int LEDNumber;
  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(LEDNumber = 2; LEDNumber <= 15; LEDNumber ++)
    {
      digitalWrite(LEDNumber, HIGH);
    }
    delay(LEDOnTime);
    for(LEDNumber = 2; LEDNumber <= 15; LEDNumber ++)
    {
      digitalWrite(LEDNumber, LOW);
    }
    delay(LEDOffTime);
  }
}

void LEDsSlideTogether (int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("LEDs Slide Together");
  Serial.println("");
  int repeat;
  int LEDNumberYellow[7] = { 
    2,3,4,5,6,7,8          };
  int LEDNumberBlue[7] = { 
    9,10,11,12,13,14,15    };
  int index;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(index = 0; index < 6; index++)
    {
      digitalWrite(LEDNumberYellow[index], HIGH);
      digitalWrite(LEDNumberBlue[index], HIGH);
      delay(LEDOnTime);
      digitalWrite(LEDNumberYellow[index], LOW);
      digitalWrite(LEDNumberBlue[index], LOW);
      delay(LEDOffTime);
    } 
  }
}

void inverseChasing (int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("Inverse Chasing");
  Serial.println("");
  int repeat;
  int LEDNumberYellow[7] = { 
    2,3,4,5,6,7,8          };
  int LEDNumberBlue[7] = { 
    15,14,13,12,11,10,9    };
  int index;
  for (repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(index = 0; index <= 6; index++)
    {
      digitalWrite(LEDNumberYellow[index], HIGH);
      digitalWrite(LEDNumberBlue[index], HIGH);
    }

    for(repeat = 1; repeat <= RepeatCount; repeat++)
    {
      for(index = 0; index <= 6; index++)
      {
        digitalWrite(LEDNumberYellow[index], LOW);
        digitalWrite(LEDNumberBlue[index], LOW);
        delay(LEDOnTime);
        digitalWrite(LEDNumberYellow[index], HIGH);
        digitalWrite(LEDNumberBlue[index], HIGH);
        delay(LEDOffTime);
      } 
    }

    for(index = 0; index <= 6; index++)
    {
      digitalWrite(LEDNumberYellow[index], LOW);
      digitalWrite(LEDNumberBlue[index], LOW);
    }
  }
}

void fourQuadrants (int delayIncrement,int totalOnTime,int totalOffTime, int RepeatCount)
{
  Serial.print("Four Quadrants");
  Serial.println("");
  int repeat;
  int quadrant1[4] = {
    5,6,7,8    };
  int quadrant2[3] = {
    2,3,4    };
  int quadrant3[4] = {
    9,10,11,12    };
  int quadrant4[3] = {
    13,14,15    };

  int index;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(index = 0; index < 4; index++)
    {
      digitalWrite(quadrant1[index], HIGH);
    }
    delay(delayIncrement);
    for(index = 0; index < 3; index++)
    {
      digitalWrite(quadrant2[index], HIGH);
    }
    delay(delayIncrement);
    for(index = 0; index < 4; index++)
    {
      digitalWrite(quadrant3[index], HIGH);
    }
    delay(delayIncrement);
    for(index = 0; index < 3; index++)
    {
      digitalWrite(quadrant4[index], HIGH);
    }
    delay(totalOnTime);
    for(index = 0; index < 4; index++)
    {
      digitalWrite(quadrant1[index], LOW);
    }
    delay(delayIncrement);
    for(index = 0; index < 3; index++)
    {
      digitalWrite(quadrant2[index], LOW);
    }
    delay(delayIncrement);
    for(index = 0; index < 4; index++)
    {
      digitalWrite(quadrant3[index], LOW);
    }
    delay(delayIncrement);
    for(index = 0; index < 3; index++)
    {
      digitalWrite(quadrant4[index], LOW);
    }
    delay(totalOffTime);
  }
}

void LEDsOnOutwards (int delayIncrement,int totalOnTime,int totalOffTime, int RepeatCount)
{
  Serial.print("LEDs On Outwards");
  Serial.println("");
  int repeat;
  int LEDsYellow[6] = { 
    4,6,3,7,2,8   };
  int LEDsBlue[6] = { 
    11,13,10,14,9,15    };
  int index;

  for (repeat = 1; repeat <= RepeatCount; repeat++)
  {
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    delay(delayIncrement);
    for(index = 0; index < 6; index = index + 2)
    {
      digitalWrite(LEDsYellow[index], HIGH);
      digitalWrite(LEDsYellow[index + 1], HIGH);
      digitalWrite(LEDsBlue[index], HIGH);
      digitalWrite(LEDsBlue[index + 1], HIGH);
      delay(delayIncrement);
    }
    delay(totalOnTime);
    for(index = 5; index >= 0; index = index - 2)
    {
      digitalWrite(LEDsYellow[index], LOW);
      digitalWrite(LEDsYellow[index - 1], LOW);
      digitalWrite(LEDsBlue[index], LOW);
      digitalWrite(LEDsBlue[index - 1], LOW);
      delay(delayIncrement);
    }
    digitalWrite(5, LOW);
    digitalWrite(12, LOW);
    delay(totalOffTime);
  }
}

void bounceUp(int delayIncrement, int LEDOnTime, int LEDOffTime, int repeatCount)
{
  Serial.print("Bounce Up");
  Serial.println("");
  int yellowLEDs[7] = {2,3,4,5,6,7,8};
  int blueLEDs[7] = {9,10,11,12,13,14,15};
  int repeat;
  int index;
  for(repeat = 1; repeat<=repeatCount; repeat++)
  {
    for(index = 0; index < 7; index++)
    {
      digitalWrite(yellowLEDs[index], HIGH);
      digitalWrite(blueLEDs[index], HIGH);
      delay(delayIncrement);
    }
    delay(LEDOnTime);
    for(index = 6; index >= 0; index--)
    {
      digitalWrite(yellowLEDs[index], LOW);
      digitalWrite(blueLEDs[index], LOW);
      delay(delayIncrement);
    }
    delay(LEDOffTime);

  }
}

void bounceUpThenInverse(int delayIncrement, int LEDOnTime, int LEDOffTime, int repeatCount)
{
  Serial.print("Bounce Up Then Inverse");
  Serial.println("");
  int yellowLEDs[7] = {2,3,4,5,6,7,8};
  int blueLEDs[7] = {9,10,11,12,13,14,15};
  int repeat;
  int index;
  for(repeat = 1; repeat<=repeatCount; repeat++)
  {
    for(index = 0; index < 7; index++)
    {
      digitalWrite(yellowLEDs[index], HIGH);
      digitalWrite(blueLEDs[index], HIGH);
      delay(delayIncrement);
    }
    delay(LEDOnTime);   
    for(index = 0; index < 7; index++)
    {
      digitalWrite(yellowLEDs[index], LOW);
      digitalWrite(blueLEDs[index], LOW);
      delay(delayIncrement);
    }
    delay(LEDOffTime);

  }
}

void zigZagAccross(int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("LEDs Zig Zag");
  Serial.println("");
  int repeat;
  int LEDNumberSequence[7] = {9,3,11,5,13,7,15};
  int index;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(index = 0; index < 7; index++)
    {
      digitalWrite(LEDNumberSequence[index], HIGH);
      delay(LEDOnTime);
      digitalWrite(LEDNumberSequence[index], LOW);
      delay(LEDOffTime);
    } 
  }
}

void groupOfThree(int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("Group of three");
  Serial.println("");
  int repeat;
  int LEDNumberSequence[14] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int index;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    digitalWrite(2,HIGH);
    delay(LEDOnTime);
    digitalWrite(3, HIGH);
    delay(LEDOnTime);
    digitalWrite(4, HIGH);
    for(index = 0; index < 14; index++)
    {
      digitalWrite(LEDNumberSequence[index], HIGH);
      digitalWrite(LEDNumberSequence[index + 1], HIGH);
      digitalWrite(LEDNumberSequence[index + 2], HIGH);    
      delay(LEDOnTime);
      digitalWrite(LEDNumberSequence[index], LOW);
      if(index < 12)
      {
      digitalWrite(LEDNumberSequence[index + 1], LOW);
      digitalWrite(LEDNumberSequence[index + 2], LOW);
      } 
      delay(LEDOffTime);
    } 
  }
}

void eachWaveOn(int LEDOnTime, int LEDOffTime, int RepeatCount)
{
  Serial.print("Each Wave On");
  Serial.println("");
  int LEDNumber;
  int repeat;
  int index;

  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
    for(LEDNumber = 2; LEDNumber <= 8; LEDNumber++)
    {
      digitalWrite(LEDNumber, HIGH);
    }
    delay(LEDOnTime);
    for(LEDNumber = 2; LEDNumber <= 8; LEDNumber++)
    {
      digitalWrite(LEDNumber, LOW);
    }
    delay(LEDOffTime);
    for(LEDNumber = 9; LEDNumber <= 15; LEDNumber++)
    {
      digitalWrite(LEDNumber, HIGH);
    }
    delay(LEDOnTime);
    for(LEDNumber = 9; LEDNumber <= 15; LEDNumber++)
    {
      digitalWrite(LEDNumber, LOW);
    }
    delay(LEDOffTime);
  }
}

void LEDsOnInwards(int delayTime, int LEDOffTime, int LEDOnTime, int RepeatCount)
{
  Serial.print("On Inwards");
  Serial.println("");
  int LEDNumberSequence1[4] = {2,9,8,15};
  int LEDNumberSequence2[4] = {3,10,7,14};
  int LEDNumberSequence3[4] = {4,11,6,13};

  int repeat;
  int index;
  
  for(repeat = 1; repeat <= RepeatCount; repeat++)
  {
     for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence1[index], HIGH);
     }
     delay(delayTime);
     for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence2[index], HIGH);
     }
     delay(delayTime);
     for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence3[index], HIGH);
     }
     delay(delayTime);
     digitalWrite(5, HIGH);
     digitalWrite(12, HIGH);
     delay(LEDOnTime);
     digitalWrite(5, LOW);
     digitalWrite(12, LOW);
     delay(delayTime);
      for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence3[index], LOW);
     }
     delay(delayTime);
     for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence2[index], LOW);
     }
     delay(delayTime);
     for(index = 0; index < 4; index++)
     {
       digitalWrite(LEDNumberSequence1[index], LOW);
     }
     delay(LEDOffTime);
  }
}
// END OF CUSTOM DEFINITIONS
//
// turn on the LEDs, one group of colors at a time
//
void ShowAllTheColors(int onTime, int offTime, int repeatCount)
{ 
  int pinNumber;
  int count;

  //
  // turn on all colors
  //
  for(count = 1; count <= repeatCount; count++)
  {
    //
    // turn on all the reds
    //
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(onTime);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

    //
    // turn on all the greens
    //
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    delay(onTime);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

    //
    // turn on all the blues
    //
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    delay(onTime);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

    //
    // turn on all the yellows
    //
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    delay(onTime);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

    //
    // turn on all the oranges
    //
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(onTime);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode
    delay(onTime);

    //
    // now turn all the LEDs off
    //
    for(pinNumber = 2; pinNumber <= 15; pinNumber++)
    { 
      digitalWrite(pinNumber, LOW);
    }
    delay(offTime);
  }
}


//
// turn on the LEDs, one at a time
//
void  SlowlyBlinkEachLedOneAtATime(int onTime, int offTime, int repeatCount)
{
  int count;
  int pinNumber;

  for(count = 1; count <= repeatCount; count++)
  {
    for(pinNumber = 8; pinNumber >= 2; pinNumber--)
    { 
      digitalWrite(pinNumber, HIGH);
      delay(onTime);
      digitalWrite(pinNumber, LOW);
      if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode
      delay(offTime);
    }

    for(pinNumber = 9; pinNumber <= 15; pinNumber++)
    { 
      digitalWrite(pinNumber, HIGH);
      delay(onTime);
      digitalWrite(pinNumber, LOW);
      if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode
      delay(offTime);
    }
  }
}


//------------------------------------------------------------------------
//                        BackgroundShow function definitions
//------------------------------------------------------------------------
// ALL your function definitions for BackgroundShow should be entered here!!
//

//
// fade an LED up and down, then move to the next LED in a clockwise direction
//

void fadeBuildUpTogether(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;

  for(count = 1; count <= repeatCount; count++)
  {
    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber, ledNumber + 7);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }

    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.down(fadeSpeed, ledNumber, ledNumber + 7);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
  }
}

void fadeBuildUpOpposite(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;
  int difference = 13;
  
  for(count = 1; count <= repeatCount; count++)
  {
    difference = 13;
    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber, ledNumber + difference);
      difference = difference - 2;
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
    difference = 13;
    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.down(fadeSpeed, ledNumber, ledNumber + difference);
      difference = difference - 2;      
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
  }
}

void fadeUpAndDownOneLEDAtATimeGoingClockwise(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;

  for(count = 1; count <= repeatCount; count++)
  {
    for(ledNumber = 8; ledNumber >= 2; ledNumber--)
    { 
      fade.up(fadeSpeed, ledNumber);
      fade.down(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }

    for(ledNumber = 9; ledNumber <= 15; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber);
      fade.down(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
  }
}

void fadeTwoTogether(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;

  for(count = 1; count <= repeatCount; count++)
  {
    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber, ledNumber + 7);
      fade.down(fadeSpeed, ledNumber, ledNumber + 7);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
  }
}

void pulseFade(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;

  for(count = 1; count <= repeatCount; count++)
  {
     fade.up(fadeSpeed);
     fade.down(fadeSpeed);
     if(fade.getKnobPosition() != 2) return;   // return if not in background mode
  }
}

void fadeOutwards(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int ledNumber;
  int count;

  for(count = 1; count <= repeatCount; count++)
  {
     fade.up(fadeSpeed,5, 12);
     fade.up(fadeSpeed,4,6,11,13);
     fade.up(fadeSpeed,3,7,10,14);
     fade.up(fadeSpeed,2,8,9,15);
     delay(onTime);
     fade.down(fadeSpeed);
     if(fade.getKnobPosition() != 2) return;   // return if not in background mode
  }
}

//
// alternate all the LEDs on the right and left
//
void fadeUpAndDownRightAndLeft(int onTime, int offTime, int repeatCount, int fadeSpeed)
{
  int count;

  fade.up(fadeSpeed, 9, 10, 11, 12, 13, 14, 15);

  for(count = 1; count <= repeatCount; count++)
  {
    fade.crossFade(fadeSpeed, 2, 9, 3, 10, 4, 11, 5, 12, 6, 13, 7, 14, 8, 15);
    fade.crossFade(fadeSpeed, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15, 8);
    if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  }

  fade.down(fadeSpeed, 9, 10, 11, 12, 13, 14, 15);
}
