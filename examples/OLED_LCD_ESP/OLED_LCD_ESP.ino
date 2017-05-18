#include <SPI.h>
#include <Wire.h>
// define screen size
//   #define SSD1306_128_64
   #define SSD1306_128_32
//   #define SSD1306_96_16

#define OLED_RESET 16  // RST-PIN for OLED (not used)
#define OLED_SDA   D1  // SDA-PIN for I2C OLED (D1)
#define OLED_SCL   D2  // SCL-PIN for I2C OLED (D2)

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
#ifdef ARDUINO_ARCH_ESP8266
  display.begin(OLED_SDA, OLED_SCL);
#else
  display.begin();
#endif

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello!!!");
  display.display();
}

uint16_t color = WHITE;
int16_t x_coord = 0;
int16_t y_coord = 15;

void loop() {
  display.drawFastVLine (x_coord, y_coord, 16, color);
  display.display();
  if ((x_coord++) >= 128)
  {
    x_coord = 0;
    color ^= WHITE;
  }
  delay(50);
}
