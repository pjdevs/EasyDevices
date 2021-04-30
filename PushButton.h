#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <Arduino.h>

class PushButton
{
    private:
        int pin;
        int currentState;
        int previousState;

    public:
        // Initialize a new PushButton
        PushButton();
        
        // Attach the button to a digital pin
        void attach(uint8_t pinNb, uint8_t mode = INPUT_PULLUP);
        // Detach the button from its pin
        void detach();
        // Update the button state (call it once per loop BEFORE is....)
        void read();

        // Predicate if the button is attached to a pin 
        bool isAttached() const;
        // Predicate if the button is currently pressed
        bool isPressed(bool switchHighLow = false) const;
        // Predicate if the button has just been released
        bool isReleased(bool switchHighLow = false) const;
};

#endif