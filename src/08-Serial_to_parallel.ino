/**
 * @file 08-Serial_to_parallel.ino
 * @brief Drive 8 LEDs using a 74HC595 serial to parallel converter.
 * @version 0.0.1
 * @date 2020-09-05
 * @copyright GPL-3.0
 */

int tDelay = 500;
int latchPin = 11;    // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;     // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595
int OE = 3;           // (3) OE on 74HC595
int brightnes = 200;  // 0..255, 0: max brightnes

byte leds = 0;

void updateShiftRegister()
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

void setup() 
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    pinMode(OE, OUTPUT);
    analogWrite(OE, brightnes);
}

void loop() 
{
    leds = 0;
    updateShiftRegister();
    delay(tDelay);
    for (int i = 0; i < 8; i++)
    {
        bitSet(leds, i);
        updateShiftRegister();
        delay(tDelay);
    }
    delay(1000);
}