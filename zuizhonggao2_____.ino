#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use
int buzzer = A5;
int melody[] = {

  // Happy Birthday
  // Score available at https://musescore.com/user/8221/scores/26906

  NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
  NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

  NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
  NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
  NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2,
 
};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
//引脚
int ROWS[] ={10,11,12,13,A0,A1,A2,A3};
int COLS[] ={2,3,4,5,6,7,8,9};
// //1=关,0=开
byte smile11[8][8] ={
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,   
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,
};
byte smile22[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,0,1,
  1,1,1,1,1,1,0,1,   
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,1,1,
  1,0,1,1,1,1,1,1,
  1,0,0,0,0,0,0,1,
};
byte smile33[8][8] ={
  1,1,1,0,1,1,1,1,
  1,1,0,0,1,1,1,1,
  1,1,1,0,1,1,1,1,
  1,1,1,0,1,1,1,1,   
  1,1,1,0,1,1,1,1,
  1,1,1,0,1,1,1,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,
};
byte smile[8][8] ={
  1,1,0,1,0 ,1,1,1,
  1,0,0,1,0,1,1,1,
  0,0,0,0,0,0,0,0,
  1,1,1,1,0,1,1,1,
  1,0,0,0,0,0,0,0,
  1,1,1,1,0,1,1,1,
  1,1,1,1,0,1,1,1 ,
  0,0,0,0,0,0,0,0,
};
byte smile2[8][8] ={
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1 ,
  1,0,0,0,0,0,0,1,
};
byte smile3[8][8] ={
  1,0,1,1,0,1,1,1,
  1,0,1,0,0,0,0,1,
  1,0,1,1,0,1,0,1,
  0,0,0,0,0,1,0,0,   
  0,0,0,1,0,0,1,1,
  1,0,0,1,0,1,0,1,
  1,0,1,1,0 ,1,0,1,
  1,0,1,0,1,1,1,0,
};
byte smile4[8][8] ={
  1,0,0,0,0,0,0,0,
  1,0,1,1,0,1,1,1,
  1,0,1,1,0,1,1,1,
  1,0,0,0,0,0,0,0,   
  1,1,1,1,0,1,1,1,
  1,0,1,1,0,1,0,1,
  1,0,1,1,0,1,0,1,
  0,1,1,0,0,1,1,0,
};
byte smile5[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,1,1,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,   
  0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
};
byte smile6[8][8] ={
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  1,1,0,1,1,0,1,1,
  1,0,0,0,0,0,0,1,   
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
  1,1,1,1,1,1,1,1,
};
byte smile7[8][8] ={
  1,1,1,1,1,1,1,1,
  1,0,0,1,1,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,   
  0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,1,
  1,1,0,0,0,0,1,1,
  1,1,1,0,0,1,1,1,
};



// 初始化设置
void setup(){
for(int i = 0;i < 8; i++){
  pinMode(COLS[i],OUTPUT);
  
  pinMode(ROWS[i], OUTPUT);
}
 // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
   
}

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }

}
void loop() {
  for(int i = 0;i < 100; i++){
  displayLed(smile11);
};
delay(1000);  
  for(int i = 0;i < 100; i++){
  displayLed(smile22);
};
delay(1000);   
  for(int i = 0;i < 100; i++){
  displayLed(smile33);
};
delay(1000);   
for(int i = 0;i < 100; i++){
  displayLed(smile);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile2);
};
delay(100);

for(int i = 0;i < 100; i++){
  displayLed(smile3);
};
delay(100);

for(int i = 0;i < 100; i++){
  displayLed(smile4);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile5);
};
delay(50);
for(int i = 0;i < 100; i++){
  displayLed(smile6);
};
delay(100);
for(int i = 0;i < 100; i++){
  displayLed(smile7);
};
delay(50);

}
void displayLed(unsigned char dat[8][8]){
for (int c = 0;c < 8;c++) {
  digitalWrite(COLS[c],HIGH);
  for (int r = 0; r < 8; r++){
    digitalWrite(ROWS[r],dat[r][c]);
  }
    delay(1);
    clearLed();
  }
}
// 
void clearLed(){
for (int i = 0;i <8; i++){
digitalWrite(ROWS[i], HIGH);
digitalWrite(COLS[i], LOW);
};
}
