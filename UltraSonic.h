#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

#define VELOCITY_COEF 1.7e-2 // better precompute the coef : v = d/t <=> d = t.v in meters (times 1e2 for cm) (must be / 2 because of leaving and returning back) (times 1e-6 for microseconds)

class UltraSonic
{
    private:
        long echoTime;
        int triggerPin;
        int echoPin;

    public:
        UltraSonic();

        // Attach the button to the given digital pins
        void attach(uint8_t triggerPin, uint8_t echoPin);
        // Detach the button from its pins
        void detach();

        void trigger(unsigned int delayMs = 10U);
        // Call the built-in pulseIn Arduino function
        void echo(uint8_t state = HIGH, unsigned long max = 1000000UL);

        // Returns the echo time calculated with pulseIn (requires pulseIn to be called before)
        const long& getEchoTime() const;
        // Returns the distance in cm calculated with echoTime (requires pulseIn to be called before)
        double getEchoDistance() const;
        // Predicate if the button is attached to pins 
        bool isAttached() const;

};

#endif