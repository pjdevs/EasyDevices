#ifndef LCDUTILS_H
#define LCDUTILS_H

#include "Arduino.h"

#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// Slide str to the left and returns true if it slided entierely
// else returns false
bool slidedLeft(const String& str, String& slidedStr, bool resetOffset = false);

#endif