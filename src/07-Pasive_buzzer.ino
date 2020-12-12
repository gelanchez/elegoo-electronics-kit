/**
 * @file 07-Pasive_buzzer.ino
 * @brief Use a passive buzzer, generating eight different sounds, each sound
 * lasting 0.5 seconds: from Alto Do (523Hz), Re (587Hz), Mi (659Hz),
 * Fa (698Hz), Sol (784Hz), La (880Hz), Si (988Hz) to Treble Do (1047Hz).
 * Circuit: 8 ohm speaker on digital pin 8.
 * http://www.arduino.cc/en/Tutorial/Tone
 * @version 0.0.1
 * @date 2020-09-04
 * @copyright GPL-3.0
 */

#include "pitches.h"

/**
 * @brief Notes in the melody.
 */
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

/**
 * @brief Note duration: 4 = quarter note, 8 = eighth note, etc.
 */
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
    // Iterate over the notes of the melody.
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
        /**
         * @brief To calculate the note duration, take one second divided by the note type.
         * e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
         */
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);

        /**
         * @brief To distinguish the notes, set a minimum time between them.
         * The note's duration + 30% seems to work well.
         */
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        
        // Stop the tone playing
        noTone(8);
    }
}

void loop()
{
    // No need to repeat the melody.
}