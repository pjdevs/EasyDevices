#include "LED.h"

LED::LED()
    : pin(-1), state(LOW)
{}

void LED::attach(uint8_t pinNb, uint8_t mode)
{
    pin = pinNb;

    pinMode(pin, mode);
}

void LED::detach()
{
    pin = -1;
}

void LED::write()
{
    if (!isAttached())
        return;

    digitalWrite(pin, state);
}

void LED::on()
{
    state = HIGH;
}

void LED::off()
{
    state = LOW;
}

bool LED::isAttached() const
{
    return pin != -1;
}

bool LED::isOn() const
{
    return state == HIGH;
}