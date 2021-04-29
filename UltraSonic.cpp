#include "UltraSonic.h"

UltraSonic::UltraSonic()
{
}

void UltraSonic::attach(uint8_t triggerPinNb, uint8_t echoPinNb)
{
    triggerPin = triggerPinNb;
    echoPin = echoPinNb;

    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    digitalWrite(triggerPin, LOW);
}

void UltraSonic::detach()
{
    triggerPin = -1;
    echoPin = -1;
}

void UltraSonic::trigger(unsigned int delayMs)
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(delayMs);
    digitalWrite(triggerPin, LOW);
}

void UltraSonic::echo(uint8_t state, unsigned long max)
{
    echoTime = pulseIn(echoPin, state, max);
}

const long &UltraSonic::getEchoTime() const
{
    return echoTime;
}

double UltraSonic::getEchoDistance() const
{
    return VELOCITY_COEF * echoTime;
}

bool UltraSonic::isAttached() const
{
    return triggerPin != -1 && echoPin != -1;
}