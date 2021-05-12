#ifndef LCDUTILS_H
#define LCDUTILS_H

#include "Arduino.h"

#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// Slide str to the left and returns true if it slided entierely else returns false
// It takes the base offset as parameter and update it
bool slidedLeft(const String& str, String& slidedStr, size_t& leftOffset);

#endif