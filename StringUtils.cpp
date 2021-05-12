#include "StringUtils.h"

bool writeStringAt(String& dest, const String& src, size_t index)
{
    for (auto&& c : src)
    {
        if (index >= dest.length())
            return false;
    
        dest[index] = c;
        ++index;
    }

    return true;
}
