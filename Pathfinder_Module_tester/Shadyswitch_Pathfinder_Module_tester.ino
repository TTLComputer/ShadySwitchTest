//Pins 2-8  -> SP1-Sx
//LEDS on K lines to gnd
#define SX 8

void setup() {
  pinMode(13, OUTPUT);
  for(int i=0; i < 8; i++)
    pinMode(i+2, OUTPUT);
}
bool flash =false;

void loop() {
  for(int i=0; i < 7 ; i++){
    digitalWrite(i+2, 1);  digitalWrite (SX, 1);  
    delay(100);  
    digitalWrite(i+2, 0);  
    delay(250);
    digitalWrite (SX, 0);
    delay(10);  
  }
  digitalWrite(13, flash);
  flash = !flash;
}
