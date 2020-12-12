/**
 * @file 10-Photocell.ino
 * @brief Measure light intensity using a photocell and control the number of LEDs
 * to be lit through a 74HC595 serial to parallel converter.
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

int ligthPin = 0;

byte leds = 0;

void updateShiftRegister()
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

void setup() 
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    pinMode(OE, OUTPUT);
    analogWrite(OE, brightnes);
    updateShiftRegister();
}

void loop() 
{
    int reading = analogRead(ligthPin);
    int numLEDSLit = reading / 57;  //1023 / 9 / 2 CHECK CIRCUIT
    if (numLEDSLit > 8)
        numLEDSLit = 8;
    leds = 0;  // no LEDs lit to start
    for (int i = 0; i < numLEDSLit; i++)
    {
        leds = leds + (1 << i);  // sets the i'th bit
    }
    updateShiftRegister();
}
