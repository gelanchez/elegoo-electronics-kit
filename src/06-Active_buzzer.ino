/**
 * @file 06-Active_buzzer.ino
 * @brief Generate a sound with an active buzzer.
 * @version 0.0.1
 * @date 2020-09-04
 * @copyright GPL-3.0
 */

const int buzzer = 12;  //The pin of the active buzzer

void setup()
{
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    unsigned char i;

    //Output a frequency
    for (i = 0; i < 80; i++)
    {
        digitalWrite(buzzer, HIGH);
        delay(1);
        digitalWrite(buzzer, LOW);
        delay(1);
    }

    //Output another frequency
    for (i = 0; i < 100; i++)
    {
        digitalWrite(buzzer, HIGH);
        delay(2);
        digitalWrite(buzzer, LOW);
        delay(2);
    }
}