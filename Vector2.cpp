#include "Vector2.h"

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