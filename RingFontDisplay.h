/* 
  Copyright 2020 Jeff Luszcz
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the
  Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  
*/

/* This is a library to display text on a Adafruit Neopixel 24 ring using a custom circle based font
    Requires: AdaFruit NeoPixel library
    Configure the PIN define to specify which pin your NeoPixel ring is connected to
*/


#ifndef RingFontDisplay_h
#define RingFontDisplay_h

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

class RingFontDisplay
{
  public:

    RingFontDisplay(Adafruit_NeoPixel _pixels);



    /* Prints a String to the diaply one character at a time, pausing each letter based on value passed in using delayMillis
        Quickly flashes a duplicated letter if detected in string to let viewer know that two of the same characters are being displayed
    */
    void print(char text[], int delayMillis);

    void drawChar(int character);
    void drawGlyph(unsigned long fontGlyph);
    void clear();

    void marchingAnts(int timesToLoop, int delayMillis) ;
    /* Set's a pixel using the current foreground color */
    void setPixel(int ledNum) ;
    void drawArc(int start, int finish, int delayMillis);
    void drawNumArc(int num, int delayMillis);
    void drawSpinner(int cycles, int delayMillis);
    void printSmile();


    /* Sets the color of the display. Set by passing the value returned from pixels.Color(rVal, gVal, bVal)
       e.g. setForegroundColor(pixels.Color(0, 10, 0));  where r,g,b ranges from 0 to 255
    */
    void setForegroundColor(uint32_t color ) ;
    void setBackgroundColor(uint32_t color ) ;

    // timing functions
    void setDelayVal(int delay);
    void setFlashVal(int flash);

    // test functions
    void testAscii();
    void demo() ;


    Adafruit_NeoPixel pixels;

  private:
    uint32_t fgColor;
    uint32_t bgColor;

};

#endif
