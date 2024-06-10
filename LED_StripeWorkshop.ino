#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Hier werden die unterschiedlichen Beispiele ein und ausgeschaltet.
// #define row 
// #define SINGLECOLOR
#define random

int i=0;

#define PIN 2 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 9 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pause=1000; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
  randomSeed(analogRead(0)); // Startwert für die Zufallszahlgeneration
  pixels.begin(); // Initialisierung der NeoPixel
  #ifdef SINGLECOLOR
  for (i=0;i<=NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(100,0,0)); // Pixel leuchtet in der Farbe rot
  }
    pixels.show(); // Durchführen der Pixel-Ansteuerung
  #endif
}

void loop() 
{
  #ifdef row
  pixels.setPixelColor(i, pixels.Color(0,100,0)); // Pixel leuchtet in der Farbe Grün
  pixels.setPixelColor(i-1, pixels.Color(0,0,0)); // Der vorherige Pixel wird abgeschaltet
  pixels.show(); // Durchführen der Pixel-Ansteuerung
    
  if (i==0) {
    pixels.setPixelColor(NUMPIXELS-1, pixels.Color(0,0,0)); // Im Fall von Pixel "0" muss die vorherige (8) ausgeschaltet werden.
  }
  pixels.show(); // Durchführen der Pixel-Ansteuerung
  delay (pause);
  i = i + 1; // Die Variable "i" wird um eine Zahl vergrößert. Die neue Zahl "i" ist dann die nächste LED im Led-Ring
  if (i==NUMPIXELS) {
    i=0; // Wenn die Variable den Wert 9 erreicht hat, wird die Variable auf den Wert "0" zurück gesetzt, da die Nummerierung der LEDs nur von 0 bis 8 geht.
  }
  #endif

  #ifdef random
    for (int i = 0; i <= NUMPIXELS; i++){
      { int brightness = 50;
        int r = random(brightness); // Zufällige Helligkeit der Farbe rot
        int g = random(brightness); // Zufällige Helligkeit der Farbe grün
        int b = random(brightness); // Zufällige Helligkeit der Farbe blau
        pixels.setPixelColor(i, pixels.Color(r,g,b)); // Pixel leuchtet in einer bunten Farbe      
      }
    }
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); 
  #endif

}
