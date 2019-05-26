#include <arduino.h>
#include "ep154.h"

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
char text[] = "Hello";
unsigned char fbuf[EP_FRAMEMEMSIZE];

void setup() {
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
    ep_spi_init();
    ep_init((unsigned char*)full_mode);
    ep_setbg(fbuf, ALL_WHITE);

    ep_write_text(fbuf, text, 10, 50, COL_BLACK, 1.0, 1.0, NULL, PEN_MED);
    ep_setframe(fbuf, 0,0, EP_WIDTH, EP_HEIGHT);
    ep_displayframe();
    Serial.println("Setup Done");
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.println("Loop");
}
