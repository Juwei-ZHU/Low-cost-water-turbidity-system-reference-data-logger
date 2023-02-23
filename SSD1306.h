#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin) - was 4 before (but 4 is for the SD card)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void blinker(int howlong) { //blink for howlong seconds
  digitalWrite(LED_BUILTIN, HIGH); delay(howlong);  // turn the LED on and wait
  digitalWrite(LED_BUILTIN, LOW); delay(howlong);   // turn the LED off and wait
}


void OLEDlms(String what) { //show a short message on the OLED screen until a new message erase it.
    display.clearDisplay();
    display.setTextWrap(true);
    if (what.length()<21) {display.setTextSize(2);display.setCursor(0, 20);}
    else if (what.length()<40) {display.setTextSize(2);display.setCursor(0, 0);}
    else {display.setTextSize(2);display.setCursor(0, 0);}
    display.println(what);
    display.display();
    display.setTextSize(1);
}

void OLEDsms(String what) { //show a short message on the OLED screen for a short time (5 seconds)
    OLEDlms(what);
    delay(5000);
    display.clearDisplay();
    display.display();  
}
 

void OLEDallInOne(String head, String texttodisplay) {
  display.clearDisplay();
  display.setTextWrap(true);
  display.setTextSize(1);                     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);                     // Start at top-left corner
  display.println(head);
  display.println(texttodisplay);
  display.display();
  delay(5000);
}

void OLEDsetup() { //initialize the OLED screen, once per startup
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); // Clear the buffer
  display.setTextColor(WHITE);
  OLEDlms(" OLED OK ");
  delay(1000);
}
