#include "PushButton.h"

PushButton::PushButton()
    : pin(-1), currentState(HIGH), previousState(HIGH) 
{}

void PushButton::attach(uint8_t pinNb, uint8_t mode)
{
    pin = pinNb;

    pinMode(pin, mode);
}

void PushButton::detach()
{
    pin = -1;
}

void PushButton::read()
{
    if (!isAttached())
        return;

    previousState = currentState;
    currentState = digitalRead(pin);
}

bool PushButton::isAttached() const
{
    return pin != -1;
}

bool PushButton::isPressed(bool switchHighLow) const
{
    return currentState == (switchHighLow ? LOW : HIGH);
}

bool PushButton::isReleased(bool switchHighLow) const
{
    return currentState == (switchHighLow ? HIGH : LOW) && previousState == (switchHighLow ? LOW : HIGH); 
}