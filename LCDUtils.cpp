#include "LCDUtils.h"

// Slides str to the left and returns true if it slided entierely
// else returns false
bool slidedLeft(const String& str, String& slidedStr, size_t& leftOffset)
{
    static const String blankLine("                ");

    String fullStr(blankLine + str + blankLine);
    slidedStr = fullStr.substring(leftOffset, leftOffset + LCD_WIDTH);

    ++leftOffset;

    if (leftOffset + LCD_WIDTH >= fullStr.length())
    {
        leftOffset = 0;
        return true;
    }
    else return false;
}