// -------------------------------------------------
// Copyright (c) 2025 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  REST,

  NOTE_E4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_B3,
  NOTE_E4, NOTE_DS4, NOTE_B3, NOTE_E4, NOTE_FS4, NOTE_GS4,
  NOTE_B4, NOTE_CS5, NOTE_E5, NOTE_A5, NOTE_GS5, NOTE_FS5,
  NOTE_D5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_B4, NOTE_GS4, NOTE_A5, NOTE_B4,
  NOTE_DS5, NOTE_E5,
  NOTE_B4, NOTE_CS5, NOTE_E5, NOTE_A5, NOTE_GS5,
  NOTE_DS5,
  NOTE_B5, NOTE_A5, NOTE_GS5,

  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_FS5, NOTE_FS5,
  NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_DS5, NOTE_DS5, NOTE_DS5,

  NOTE_CS5, NOTE_E4, NOTE_CS5, NOTE_B4,
  NOTE_CS5, NOTE_B4, NOTE_GS4, NOTE_A4,
  NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_E4,
  NOTE_E4
};

int durations[] = {
  4,

  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  2, 4, 4, 4, 4,
  2, 4, 4, 4,
  2, 2,
  4, 4, 4, 4, 4,
  2,
  4, 4, 4,

  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,

  2, 4, 2, 4,
  2, 2, 4, 4,
  2, 2, 4, 4,
  1,
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
