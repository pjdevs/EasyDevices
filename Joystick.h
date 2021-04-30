#ifndef LED_H
#define LED_H

#include "Arduino.h"
#include "PushButton.h"
#include "Vector2.h"
#include "constants.h"

class Joystick
{
    private:
        int pinX;
        int pinY;
        
        Vector2 joyXY;
        PushButton pressBtn;

    public:
        // Initialize a new Joystick
        Joystick();
        
        // Attach the Joystick its pins
        void attach(uint8_t xPin, uint8_t yPin, uint8_t pressBtnPin, int pressBtnMode = OUTPUT);
        // Detach the Joystick from its pins
        void detach();
        // Update the Joystick state (call it once per loop BEFORE access to members)
        void read();

        // Returns the Vector2 which represents the XY axis of the joystick (between -1.0 and 1.0)
        const Vector2& getXY() const;
        // Check wether the Joystick is pressed or not
        bool isPressed() const;
        // Check wether the Joystick has just been released
        bool isReleased() const;
        // Predicate if the Joystick is attached to a pin 
        bool isAttached() const;
};

#endif