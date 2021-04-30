#ifndef VECTOR2_H
#define VECTOR2_H

#include "Printable.h"

class Vector2 : public Printable
{
    public:
        double x;
        double y;

    public:
        virtual size_t printTo(Print& p) const;
};

#endif