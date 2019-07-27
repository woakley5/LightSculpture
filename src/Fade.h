//      ******************************************************************
//      *                                                                *
//      *               DPEA LED Sculpture - Fading Class                *
//      *                                                                *
//      *             Stan Reifel                    1/26/13             *
//      *                                                                *
//      ******************************************************************

#ifndef Fade_h
#define Fade_h
#include <avr/pgmspace.h>

//
// IO pin constants
//
const int firstLEDNumber = 2;
const int lastLEDNumber = 15;
const int onOffSwitch = 18;


//
// global storage for PWM values
//
extern int ledPwm[];
extern const int throbTable[] PROGMEM;


//
// the Fade class
//
class Fade
{
  public:

    Fade();
    
    void up(int fadeSpeed, int led1);
    void up(int fadeSpeed, int led1, int led2);
    void up(int fadeSpeed, int led1, int led2, int led3);
    void up(int fadeSpeed, int led1, int led2, int led3, int led4);
    void up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5);
    void up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6);
    void up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7);
    void up(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8);
    void up(int fadeSpeed);

    void down(int fadeSpeed, int led1);
    void down(int fadeSpeed, int led1, int led2);
    void down(int fadeSpeed, int led1, int led2, int led3);
    void down(int fadeSpeed, int led1, int led2, int led3, int led4);
    void down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5);
    void down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6);
    void down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7);
    void down(int fadeSpeed, int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8);
    void down(int fadeSpeed);

    void crossFade(int fadeSpeed, int up1, int down1);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5, int up6, int down6);
    void crossFade(int fadeSpeed, int up1, int down1, int up2, int down2, int up3, int down3, int up4, int down4, int up5, int down5, int up6, int down6, int up7, int down7);

    int getKnobPosition();
    int getKnobPosition(int *ZoneValue);
    void turnOffAllLEDs();
    void nightLightModeWhileInZoneThree();

    void getFadeSpeedValues(int fadeSpeed, int *PWMCycleCount, int *tableStep);
    int getThrobTableLength();
    int getThrobTableHalfLength();
    void pwmAllPins(int PWMCycleCount);
    
  private:
};

#endif

