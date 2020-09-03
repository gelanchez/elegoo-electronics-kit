/**
 * @file 01-Serial.ino
 * @brief Simple serial communication
 * @version 0.0.1
 * @date 2020-09-03
 * @copyright GPL-3.0
 */

/**
 * @brief Setup code here, to run once
 */
void setup()
{
    Serial.begin(9600);
}

/**
 * @brief Main code here, to run repeatedly
 */
void loop()
{
    Serial.println("Hello world");
    delay(1000);
}