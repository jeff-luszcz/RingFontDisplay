# RingFontDisplay Library

Arduino library that allows alphanumerical text to be displayed on a NeoPixel Ring or similar ring of LEDs using Dendro, a custom ring based font. The library currently works with 24 LED rings.

The custom font has been designed to approximate standard letter shapes, some obvious tradeoffs have been made. The font should not require much human training for casual use.

The messages displayed by this library can be used for IoT messages, errors, alerts, IDs and other useful pieces of short text.

The Dendro font contains characters ranging from ASCII 32-ASCII 122. The lower case letters ASCII 97-122 are mapped to the capital letters. 

This library has been tested with the Adafruit Neopixel Ring 24. 

After downloading, rename folder to 'RingFontDisplay' and install in Arduino Libraries folder. Restart Arduino IDE, then open File->Sketchbook->Library->RingFontDisplay-> RingFontDisplayDemo sketch.

If you want to see what the font looks like you can view all the glyphs by viewing /docs/DendroFontGlyphs.pdf 

See them at https://github.com/jeff-luszcz/RingFontDisplay/blob/master/docs/DendroFontGlyphs.pdf

# Installation

Navigate to the Github Releases page.

Download the latest release or click green CODE button and then "Download ZIP file"

Rename zip file or directory "RingFontDisplay"

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


## Viewing or Changing the font glyphs

NOTE: This section is not needed for just using the library as is. It is only required if you want to redefine any of the glyphs.
 
The font is defined in the RingFontDisplay.cpp source file as an array of longs. The least significant / last 24 bits define each font glyph. Each glyph is a series of 1s and 0s that turn the LED on or off in each ring based glyph. LED 0 is defined at the top of the ring (e.g. 12 o'clock on a clock face).

You can see what the glyphs look like by examining the pre-generated file DendroFontGlyphs.pdf in the docs directory. These glyphs are generated using the Graphviz utility and the RingFontGraphvizGen.py file. Run the python script using:

`python RingFontGraphvizGen.py
`

and then run the generated script from inside the new 'glyphs' directory

`cd glyphs`

`chmod +x glyphsgenerateGlyphs.sh`

`./glyphsgenerateGlyphs.sh`


This will generate a glyphs.html file and interim .gv and png files. 
A page showing all the glyphs (glyphs.html) can be viewed using Firefox (Note: Safari can't view local files)

I have also used a printout of the LED numbering and small coins to try out different glyphs. Cover the LED #s with coins for 1s andleave blank for 0s. You can then read counter-clockwise to enter the bitfield of the new glyph in RingFontDisplay.cpp, edit the RingFontGraphvizGen.py file as well if you wish to generate an updated font-book. This is not needed for standard use of the library. The RingFontGraphvizGen.py file only uses the last 24 bits of the long.

You can find this printable template in docs/GlyphDesignTemplate.pdf


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
  
