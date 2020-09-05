/**
 * @file 09-Serial_monitor.ino
 * @brief Control 8 LEDs from the serial monitor through a 74HC595 serial to parallel converter.
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

    Serial.begin(9600);
    while (! Serial);  // Wait untilSerial is ready - Leonardo
    Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}

void loop() 
{
    if (Serial.available())
    {
        char ch = Serial.read();
        if (ch >= '0' && ch <= '7')
        {
            int led = ch - '0';
            bitSet(leds, led);
            updateShiftRegister();
            Serial.print("Turned on LED ");
            Serial.println(led);
        }
        if (ch == 'x')
        {
            leds = 0;
            updateShiftRegister();
            Serial.println("Cleared");
        }
    }
}