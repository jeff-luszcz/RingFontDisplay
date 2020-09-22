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


#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

#include <RingFontDisplay.h>

// ARDUINO hardware and Neopixels Config section
// CONFIG: What pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// CONFIG: many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24


// set up the neopixels
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// create the RigFontDisplay, passing in a configured set of neopixels
RingFontDisplay rfd(pixels);


void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  rfd.setForegroundColor(pixels.Color(20, 50, 0));  // set the font color to a dim green
  rfd.setFlashVal(100);
}

void loop() {
  rfd.print("Hello World!", 200);
  rfd.demo();
}
