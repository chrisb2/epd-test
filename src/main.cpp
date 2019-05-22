#include <arduino.h>
#include "ep29.h"

// Wiring connections
// Blue - MOSI - PTD2
// Yellow - SCK - PTD1
// Orange - CS - PTD7
// Green - DC Data/Command - PTD6
// White - RST - PTA17
// Purple - BUSY - PTA16
// Black - GND
// Red - 3.3V

//definitions

// Constants

// look-up tables, provided by Waveshare
const unsigned char full_mode[] = {
        0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22, 0x66, 0x69,
        0x69, 0x59, 0x58, 0x99, 0x99, 0x88, 0x00, 0x00, 0x00, 0x00,
        0xf8, 0xb4, 0x13, 0x51, 0x35, 0x51, 0x51, 0x19, 0x01, 0x00 };
const unsigned char partial_mode[] = {
        0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x13, 0x14, 0x44, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


// Global Variables
char text[] = "Hello World";
static const int LED_D1 = 0;
unsigned char fbuf[EP_FRAMEMEMSIZE];

void setup() {
    pinMode(LED_D1, OUTPUT);
    ep_spi_init();
    ep_init((unsigned char*)full_mode);
    ep_setbg(fbuf, ALL_WHITE);

    ep_write_text(fbuf, text, 10, 50, COL_BLACK, 2.0, 1.0, NULL, PEN_MED);
    ep_setframe(fbuf, 0,0, EP_WIDTH, EP_HEIGHT);
    ep_displayframe();
}

void loop() {
    digitalWrite(LED_D1, HIGH);
    delay(200);
    digitalWrite(LED_D1, LOW);
    delay(200);
}
