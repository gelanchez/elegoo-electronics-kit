/**
 * @file 04-RGB_LED.ino
 * @brief It starts with the LED in the red color state, then fades to green,
 * then fades to blue and finally back to the red color.
 * @version 0.0.1
 * @date 2020-09-03
 * @copyright GPL-3.0
 */

/**
 * @brief Define pins
 */
#define BLUE 3
#define GREEN 5
#define RED 6

#define DELAYTIME 10  // Fading time between colors

void setup()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
}

// Define variables
int redValue;
int greenValue;
int blueValue;

void loop()
{
    /**
     * @brief Choose a value between 1 and 255 to change the color.
     */
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
    
    for(int i = 0; i < 255; i += 1)  // Fades out red bring green full when i=255
    {
        redValue -= 1;
        greenValue += 1;
        analogWrite(RED, redValue);
        analogWrite(GREEN, greenValue);
        delay(DELAYTIME);
    }

    redValue = 0;
    greenValue = 255;
    blueValue = 0;

    for(int i = 0; i < 255; i += 1)  // Fades out green bring blue full when i=255
    {
        greenValue -= 1;
        blueValue += 1;
        analogWrite(GREEN, greenValue);
        analogWrite(BLUE, blueValue);
        delay(DELAYTIME);
    }

    redValue = 0;
    greenValue = 0;
    blueValue = 255;

    for(int i = 0; i < 255; i += 1)  // Fades out blue bring red full when i=255
    {
        // The following code has been rearranged to match the other two similar sections
        blueValue -= 1;
        redValue += 1;
        analogWrite(BLUE, blueValue);
        analogWrite(RED, redValue);
        delay(DELAYTIME);
    }
}