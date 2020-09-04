/**
 * @file 05-Digital_inputs.ino
 * @brief Push buttons with digital inputs to turn an LED on and off.
 * Pressing the button will turn the LED on; pressing the other button
 *  will turn the LED off.
 * @version 0.0.1
 * @date 2020-09-04
 * @copyright GPL-3.0
 */

const int buttonApin(9);
const int buttonBpin(8);
const int ledPin(5);

void setup()
{
    pinMode(buttonApin, INPUT_PULLUP);
    pinMode(buttonBpin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    if (digitalRead(buttonApin) == LOW)
    {
        digitalWrite(ledPin, HIGH);
    }
    if (digitalRead(buttonBpin) == LOW)
    {
        digitalWrite(ledPin, LOW);
    }
}