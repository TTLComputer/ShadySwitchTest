//DTMF Tester. Build for teensy 3.6
//Pin A21 -> T
// LEDs on all other pins -> 5V

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine2;          //xy=123,364
AudioSynthWaveformSine   sine1;          //xy=141,328
AudioMixer4              mixer1;         //xy=303,346
AudioOutputAnalog        dac1;           //xy=513,343
AudioConnection          patchCord1(sine2, 0, mixer1, 1);
AudioConnection          patchCord2(sine1, 0, mixer1, 0);
AudioConnection          patchCord3(mixer1, dac1);
// GUItool: end automatically generated code

void setup() {
  // put your setup code here, to run once:
  AudioMemory(18);
  //pinMode(2, OUTPUT)
  sine1.amplitude(0.5);
  sine2.amplitude(0.5);
  dac1.analogReference(EXTERNAL);
  pinMode(13, OUTPUT);
}
bool flash = false;

unsigned int row[] = {1209, 1336,1477,1633};
unsigned int column[] = {697,770,852,941};

void loop() {
  // put your main code here, to run repeatedly:
  for(int r=0; r <4; r++){
    sine1.frequency(row[r]);
    for(int c=0; c<4; c++){
      sine2.frequency(column[c]);
      delay(100);
      mixer1.gain(0,0);
      mixer1.gain(1,0);
      delay(100);
      mixer1.gain(0,1);
      mixer1.gain(1,1);
    }
    
  }
  digitalWrite(13, flash);
  flash = !flash;
}
