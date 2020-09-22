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

    v0.9 released 2020-09-21

*/

#include <Adafruit_NeoPixel.h>
#include "RingFontDisplay.h"

/* To use this library, use the following sample code

  #include <Adafruit_NeoPixel.h>
  #include "Arduino.h"

  #include "RingFontDisplay.h"
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
*/

// The Dendro font v0.9
// Define the Glyphs for each character in printable ASCII from 32-127
const unsigned long font[95] = {
  // Define LETTER font glyphs, array index is the ASCII value - 32
  // since we skip the  unprintable first 32 characters of ASCII table
  // The Glyphs include:
  // ASCII characters from 32 through 66 [ space through ' chracter ]
  // including all UPPERCASE chracters
  // skips lower case letters, they get printed as UPPERCASE
  // this toupper conversion is handled in the drawChar() method
  // The font glyph is made up of the last 24 bits of the folowing longs
  // The LEDS are numbered in decending counter clockwise order
  // ignore leading bits 32-24, I use a 1 in bit 24 as a visual guide, it isn't printed
  //         Pin number on led ring (23-0)
  //        222211111111110000000000
  //[IGNORE]321098765432109876543210     Character-Name     ascii  array-index
  0b00000001000000000000000000000000, // space                32   index = [0]
  0b00000001000000000001001111111100, // exclamation-mark     33
  0b00000001011000000000000000001100, // quotation-mark       34
  0b00000001100010100010100010100010, // number-sign          35
  0b00000001011100001101011100001101, // dollar-sign          36
  0b00000001001010011000001010011000, // percent-sign         37
  0b00000001100000111111110101000111, // ampersand   (&)      38
  0b00000001000000000000000000011000, // apostrophe           39
  0b00000001111111111110000000000001, // left-parenthesis     40
  0b00000001000000000001111111111111, // right-parenthesis    41
  0b00000001001001001001001001001001, // asterisk             42
  0b00000001000001000001000001000001, // plus-sign            43
  0b00000001000000000000011100000000, // comma                44
  0b00000001000011000000000011000000, // hyphen               45
  0b00000001000000000000010000000000, // period               46
  0b00000001000000001100000000001100, // slash (/)            47
  0b00000001111111111111111111111111, // zero                 48
  0b00000001000000000000111111111110, // one
  0b00000001110001011111110001111111, // two
  0b00000001000000000001111011011111, // three
  0b00000001011110000001000000000001, // four
  0b00000001111110000111111010000111, // five
  0b00000001111111111111111110000001, // six
  0b00000001110000000000111111111011, // seven
  0b00000001111100111100111100111100, // eight
  0b00000001111100000011111111111111, // nine
  0b00000001000001000000000001000000, // colon
  0b00000001000000000000011101000000, // semicolon
  0b00000001011111111010000000000001, // less-than-sign
  0b00000001000101000100000101000000, // equals-sign
  0b00000001000000000001011111111101, // greater-than-sign
  0b00000001111100000010011111111111, // question-mark
  0b00000001111000011111111010100001, // commercial-at (@)
  0b00000001111111111000001111111111, // A
  0b00000001000000000000111110111110, // B
  0b00000001111111111110000000000001, // C
  0b00000001000000000001111111111111, // D
  0b00000001111011011110000000000001, // E
  0b00000001111111111100000000101011, // F
  0b00000001111111111111111111000001, // G
  0b00000001001111111000001111111000, // H
  0b00000001000000001111110000000011, // I
  0b00000001000000011111111111111111, // J
  0b00000001111111111100000110110000, // K
  0b00000001111111111111111000000000, // L
  0b00000001111111010000000010111110, // M
  0b00000001000000000000000011111010, // N
  0b00000001111111111111111111111111, // O
  0b00000001111111111110000001111111, // P
  0b00000001111111111111110011111111, // Q
  0b00000001111111111000000000011111, // R
  0b00000001111010000111111010000111, // S
  0b00000001111100000001000000111111, // T
  0b00000001001111111111111111110000, // U
  0b00000001000000001111111000000000, // V
  0b00000001001011111000011111010011, // W
  0b00000001001110011100011100111000, // X
  0b00000001011000000011000000011000, // Y
  0b00000001111100100111111100101111,  // Z
  0b00000001100111100111000000000011,  // opening bracket      91
  0b00000001011000000000011000000000,  // backslash (/)
  0b00000001000000000011100111100111,  // closing bracket
  0b00000001101000000000000000010111,  // caret - circumflex
  0b00000001000000001111110000000000,  // underscore
  0b00000001110000000000000000000000   // grave accent         96
};

// Add some special non-ascii character glyphs
// glpyh for a smily face
const unsigned long smile =     0b000000010010000111111111100001000;

int lastChar = 0; // used to flash a black screen for a brief period if repeatedly printing the same character

int delayVal = 1000; // Time (in milliseconds) to pause between printed characters
int flashVal = 100;  // Time (in milliseconds) to flash blank between repeated chracters


RingFontDisplay::RingFontDisplay(Adafruit_NeoPixel _pixels) {

  // When setting up the NeoPixel library, we tell it how many pixels,
  // and which pin to use to send signals. Note that for older NeoPixel
  // strips you might need to change the third parameter -- see the
  // strandtest example for more information on possible values.
  //Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
  pixels = _pixels;
  fgColor = pixels.Color(0, 10, 0);  // sets the default foreground color

}


void RingFontDisplay::demo() {
  setForegroundColor(pixels.Color(0, 10, 0));
  marchingAnts(10, 100);
  print("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 500);
  print("abcdefghijklmnopqrstuvwxyz", 500);
  print("0123456789", 500);
  print(" !\"#$%&'()*+,-./", 500);
  print("[\]^_`", 500);
  printSmile();
}

void RingFontDisplay::clear() {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();   // Send the updated pixel colors to the hardware.

}

/* Sets the color of the display. Set by passing the value returned from pixels.Color(rVal, gVal, bVal)
   e.g. setForegroundColor(pixels.Color(0, 10, 0));  where r,g,b ranges from 0 to 255
*/
void RingFontDisplay::setForegroundColor(uint32_t color ) {
  fgColor = color;
}

/* Sets the bckground color of the display. Set by passing the value returned from pixels.Color(rVal, gVal, bVal)
   e.g. setBackgroundColor(pixels.Color(0, 10, 0));  where r,g,b ranges from 0 to 255
*/
void RingFontDisplay::setBackgroundColor(uint32_t color ) {
  bgColor = color;
}



/* Prints a String to the display one character at a time, pausing each letter based on value passed in using delayMillis
    Quickly flashes a duplicated letter if detected in string to let viewer know that two of the same characters are being displayed
*/
void RingFontDisplay::print(char text[], int delayMillis) {

  for (int i = 0; i < strlen(text); i++ ) {

    char x = text[i];

    // test to see if we are printing same char twice in row, flash quickly if so
    if (lastChar == x) {
      clear();
      delay(flashVal);
    }
    lastChar = x;  // store the current character to test if printintg repeating character

    drawChar(x);
    delay(delayVal);
  }
}


void RingFontDisplay::drawChar(int character) {
  // We only have one case for this font, so turn all lowercase letters into UPPER case
  // by subtracting 32 from the current ascii value, basically a toupper() call
  if (character > 96 && character < 123) {
    character = character - 32;
  }
  // look up the font for this ascii character, first remove 30 from the ascii
  // value since we ignore the first 30 unprintable characters (removed to save memory)
  character = character - 32;
  unsigned long fontGlyph = font[character];
  drawGlyph(fontGlyph);

}

void RingFontDisplay::drawGlyph(unsigned long fontGlyph) {
  pixels.clear(); // Set all pixel colors to 'off'
  for (int i = 0; i < 24; i++) {
    if (bitRead( fontGlyph, i)) {
      // glyph has 1 in matrix, turn LED on using current foreground color
      // use setForegroundColor() to set this foreground color
      pixels.setPixelColor(i, fgColor);
    } else {
      // glyph has 0 in matrix, make the LED the background color (often black or 0,0,0)
      pixels.setPixelColor(i, bgColor);
    }
  }
  pixels.show();   // Send the updated pixel colors to the hardware.
}


void RingFontDisplay::marchingAnts(int timesToLoop, int delayMillis) {
  for (int i = 0; i < timesToLoop; i++) {
    pixels.clear();
    for (int led = 0; led < 24; led = led + 2) {
      pixels.setPixelColor(led, fgColor);
    }
    pixels.show();

    delay(delayMillis);

    pixels.clear();
    for (int led = 1; led < 24; led = led + 2) {
      pixels.setPixelColor(led, fgColor);
    }
    pixels.show();

    delay(delayMillis);
  }
}

/* Set's a pixel using the current foreground color */
void RingFontDisplay::setPixel(int ledNum) {
  pixels.clear();   // Send the updated pixel colors to the hardware.
  pixels.setPixelColor(ledNum, fgColor);
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void RingFontDisplay::drawNumArc(int num, int delayMillis) {
  pixels.clear();
  for (int led = 0; led < num; led++) {
    pixels.setPixelColor(led, fgColor);
  }
  pixels.show();
  delay(delayMillis);
}

void RingFontDisplay::drawArc(int start, int finish, int delayMillis) {
  pixels.clear();
  for (int led = start; led <= finish; led++) {
    pixels.setPixelColor(led, fgColor);
  }
  pixels.show();
  delay(delayMillis);
}

void RingFontDisplay::drawSpinner(int cycles, int delayMillis) {
  pixels.clear();
  int dot = 0;
  for (int i = 0; i < cycles; i++) {
    for (int led = 0; led < 24; led++) {
      pixels.setPixelColor(led, fgColor);
    }
    pixels.setPixelColor(dot % 24, pixels.Color(0, 0, 0));
    pixels.show();
    delay(delayMillis);
    dot++;
  }
}

void RingFontDisplay::testAscii() {
  for (int i = 91; i < 98; i++) {
    drawChar(i);
    delay(900);
  }
}


void RingFontDisplay::printSmile() {
  drawGlyph(smile);
}


void RingFontDisplay::setDelayVal(int delay) {
  delayVal = delay;
}
void RingFontDisplay::setFlashVal(int flash) {
  flashVal = flash;
}


