#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED
{
    private:
        int pin;
        int state;

    public:
        // Initialize a new LED
        LED();
        
        // Attach the LED to a digital pin
        void attach(int pinNb, int mode = OUTPUT);
        // Detach the LED from its pin
        void detach();
        // Update the LED state (call it once per loop AFTER on, off, etc.)
        void write();
        
        // Switch on the LED
        void on();
        // Switch off the LED
        void off();

        // Predicate if the LED is attached to a pin 
        bool isAttached() const;
        // Predicate if the LED is currently on
        bool isOn() const;
};

#endif