#include "Vector2.h"

Vector2::Vector2()
    : x(0.0), y(0.0)
{}

Vector2::Vector2(double x, double y)
    : x(x), y(y)
{}

size_t Vector2::printTo(Print& p) const
{
    size_t s = 4;

    p.print('(');
    s += p.print(x);
    p.print(", ");
    s += p.print(y);
    p.println(')');

    return  s;
}