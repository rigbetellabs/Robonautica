int melody[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST,
  // NOTE_C5, NOTE_G4, REST, NOTE_E4,
  // NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  // NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  // REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  // NOTE_C5, NOTE_G4, REST, NOTE_E4,
  // NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  // NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  // REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,

  // REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  // REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  // REST, NOTE_DS5, REST, NOTE_D5,
  // NOTE_C5, REST,

  // REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  // REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  // REST, NOTE_DS5, REST, NOTE_D5,
  // NOTE_C5, REST,

  // NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,

  // NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  // REST,
  // NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  // NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  // NOTE_G5, REST, NOTE_G4, REST,
  // NOTE_C5, NOTE_G4, REST, NOTE_E4,

  // NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  // NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  // REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

  // NOTE_C5, NOTE_G4, REST, NOTE_E4,
  // NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  // NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  // REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  // NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,

  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  // NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  // NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  // REST,

  // NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  // NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  // NOTE_G5, REST, NOTE_G4, REST,
  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

  // NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  // NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  // NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  // NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  // NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,

  // // Game over sound
  // NOTE_C5, NOTE_G4, NOTE_E4,
  // NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
  // NOTE_G4, NOTE_D4, NOTE_E4
};

int durations[] = {
  8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  // 4, 8, 4, 4,
  // 4, 4, 8, 4,
  // 8, 8, 8, 4, 8, 8,
  // 8, 4,8, 8, 4,
  // 4, 8, 4, 4,
  // 4, 4, 8, 4,
  // 8, 8, 8, 4, 8, 8,
  // 8, 4,8, 8, 4,


  // 4, 8, 8, 8, 4, 8,
  // 8, 8, 8, 8, 8, 8, 8, 8,
  // 4, 4, 8, 4,
  // 2, 2,

  // 4, 8, 8, 8, 4, 8,
  // 8, 8, 8, 8, 8, 8, 8, 8,
  // 4, 4, 8, 4,
  // 2, 2,

  // 8, 4, 8, 8, 8, 4,
  // 8, 4, 8, 2,

  // 8, 4, 8, 8, 8, 8, 8,
  // 1,
  // 8, 4, 8, 8, 8, 4,
  // 8, 4, 8, 2,
  // 8, 8, 8, 8, 8, 8, 4,
  // 4, 4, 4, 4,
  // 4, 8, 4, 4,

  // 4, 4, 8, 4,
  // 8, 8, 8, 4, 8, 8,
  // 8, 4, 8, 8, 4,

  // 4, 8, 4, 4,
  // 4, 4, 8, 4,
  // 8, 8, 8, 4, 8, 8,
  // 8, 4, 8, 8, 4,

  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 8, 8, 8, 8, 8,

  // 8, 4, 8, 2,
  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 4, 8, 8, 8, 8,
  // 8, 4, 8, 2,

  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 8, 8, 8, 8, 8,

  // 8, 4, 8, 2,
  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 4, 8, 8, 8, 8,
  // 8, 4, 8, 2,
  // 8, 4, 8, 8, 8, 8, 8,
  // 1,

  // 8, 4, 8, 8, 8, 4,
  // 8, 4, 8, 2,
  // 8, 8, 8, 8, 8, 8, 4,
  // 4, 4, 4, 4,
  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 8, 8, 8, 8, 8,

  // 8, 4, 8, 2,
  // 8, 4, 8, 4, 4,
  // 8, 4, 8, 2,
  // 8, 4, 8, 8, 8, 8,
  // 8, 4, 8, 2,

  // //game over sound
  // 4, 4, 4,
  // 8, 8, 8, 8, 8, 8,
  // 8, 8, 2
};

void mario_bootup() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(buzzerPin, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(buzzerPin);
  }
}
