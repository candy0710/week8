#include "pitches.h"
#define C41 262  //1 Do
#define D41 294  //2 Re
#define E41 330  //3 Mi
#define F41 349  //4 Fa
#define G41 392  //5 Sol
#define G42 415  //#5 #Sol
#define A41 440  //6 La
#define B41 494  //7 Si
#define C51 523  //1 Do_h
#define D51 587  //2 Re_h
#define D52 622  //#2 #Re_h
#define E51 659  //3 Mi_h
#define F51 698  //4 Fa_h
#define G51 784  //5 Sol_h
#define A51 880  //6 La_h
#define B51 988  //7 Si_h
#define O1 000  //休止符
int freq = 2000;
int channel = 0;
int resolution = 8;

int tonePin = 12;



int melody[] = {
 E51,D52,E51,D52,E51,B41,D51,C51,A41,O1,E41,A41,B41,E41,G42,B41,C51,E41,E51,D52,E51,D52,E51,B41,D51,C51,A41,O1,E41,A41,B41,E41,C51,B41,A41
};
int noteDurations[] = {
3,3,3,3,3,3,3,3,1,3,3,3,1,3,3,3,1,3,3,3,3,3,3,3,3,3,1,3,3,3,1,3,3,3,1
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);
}

void loop() {
    for (int thisNote = 0; thisNote < 35; thisNote++) {
      int noteDuration = 400 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}
