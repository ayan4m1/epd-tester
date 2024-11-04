#include <Arduino.h>
#include <GxEPD2_BW.h>

#define DISP_WIDTH 800
#define DISP_HEIGHT 480

const uint8_t PIN_EPD_BUSY = 14;
const uint8_t PIN_EPD_CS = 13;
const uint8_t PIN_EPD_RST = 21;
const uint8_t PIN_EPD_DC = 22;
const uint8_t PIN_EPD_SCK = 18;
const uint8_t PIN_EPD_MISO = 19;
const uint8_t PIN_EPD_MOSI = 23;
const uint8_t PIN_EPD_PWR = 26;

GxEPD2_BW<GxEPD2_750_T7, GxEPD2_750_T7::HEIGHT> display = GxEPD2_750_T7(PIN_EPD_CS,
                                                                        PIN_EPD_DC,
                                                                        PIN_EPD_RST,
                                                                        PIN_EPD_BUSY);

void setup()
{
  pinMode(PIN_EPD_PWR, OUTPUT);
  digitalWrite(PIN_EPD_PWR, HIGH);
  display.init(115200, true, 10, false);
  SPI.end();
  SPI.begin(PIN_EPD_SCK,
            PIN_EPD_MISO,
            PIN_EPD_MOSI,
            PIN_EPD_CS);

  display.setRotation(0);
  display.setTextSize(1);
  display.setTextColor(GxEPD_BLACK);
  display.setTextWrap(false);
  // display.fillScreen(GxEPD_WHITE);
  display.setFullWindow();
  display.firstPage(); // use paged drawing mode, sets fillScreen(GxEPD_WHITE)
  display.fillScreen(GxEPD_BLACK);
  display.nextPage();
  display.fillScreen(GxEPD_WHITE);
  display.nextPage();
  display.end();
}

void loop()
{
  while (true)
  {
    delay(100);
  }
}