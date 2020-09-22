# RingFontDisplay Library

Arduino library that allows alphanumerical text to be displayed on a NeoPixel Ring or similar ring of LEDs using Dendro, a custom ring based font. The library currently works with 24 LED rings.

The custom font has been designed to approximate standard letter shapes, some obvious tradeoffs have been made. The font should not require much training for casual use.

The messages displayed by this library can be used for IoT messages, errors, alerts, IDs and other useful pieces of short text.

The Dendro font contains characters ranging from ASCII 32-ASCII 122. The lower case letters ASCII 97-122 are mapped to the capital letters. 

This library has been tested with the Adafruit Neopixel Ring 24. 

After downloading, rename folder to 'RingFontDisplay' and install in Arduino Libraries folder. Restart Arduino IDE, then open File->Sketchbook->Library->RingFontDisplay-> RingFontDisplayDemo sketch.

# Installation

Navigate to the Github Releases page.
Download the latest release.
In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library


## Supported Modules and Displays
* Adafruit NeoPixel Ring - 24 x 5050 RGB LED with Integrated Drivers

## Functions
* clear()
* demo()
* drawArc()
* drawChar()
* drawGlyph()
* drawNumArc()
* drawSpinner()
* marchingAnts()
* print()
* printSmile()
* setBackgroundColor()
* setDelayVal()
* setFlashVal()
* setForegroundColor()
* setPixel()
* testAscii()

# Examples

 `#include <Adafruit_NeoPixel.h>
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

}`


## Getting the Source Code

RingFontDisplay is hosted on GitHub:

https://github.com/jeff-luszcz/RingFontDisplay



# License
This code is licensed under the terms of this MIT License

`Copyright 2020 Jeff Luszcz

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the
  
  Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
  
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
  
  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
  
  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.`
  
