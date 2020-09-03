/**
 * @file 02-Blink.ino
 * @brief Turns an LED on for one second, then off for one second, repeatedly.
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
 * @version 0.0.1
 * @date 2020-09-03
 * @copyright GPL-3.0
 */

void setup()
{
    // Initialize digital pin LED_BUILTIN as an output. LED_BUILTIN = 13.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
    delay(1000);                       // Wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off by making the voltage LOW
    delay(1000);                       // Wait for a second
}