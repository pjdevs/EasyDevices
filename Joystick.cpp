#include "Joystick.h"

Joystick::Joystick()
    : pinX(-1), pinY(-1), pressBtn()
{}

void Joystick::attach(uint8_t xPin, uint8_t yPin, uint8_t pressBtnPin, uint8_t pressBtnMode)
{
    pinX = xPin;
    pinY = yPin;

    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);

    pressBtn.attach(pressBtnPin, pressBtnMode);
}

void Joystick::detach()
{
    pinX = -1;
    pinY = -1;

    pressBtn.detach();
}

static double joyRawToPhys(int raw)
{
    return (double)(raw - HALF_ANALOG_VALUE) / HALF_ANALOG_VALUE;
}

void Joystick::read()
{
    pressBtn.read();

    joyXY.x = joyRawToPhys(analogRead(pinX));
    joyXY.y = joyRawToPhys(analogRead(pinY));    
}

const Vector2& Joystick::getXY() const
{
    return joyXY;
}

bool Joystick::isPressed() const
{
    return pressBtn.isPressed();
}

bool Joystick::isReleased() const
{
    return pressBtn.isReleased();
}

bool Joystick::isAttached() const
{
    return pinX != -1 && pinY != -1 && pressBtn.isAttached();
}