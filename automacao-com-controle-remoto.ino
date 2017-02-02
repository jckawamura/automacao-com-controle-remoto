#include <IRremote.h>
#include <Wire.h>
#include "rgb_lcd.h"

//portas
const byte IRrec = 2;
const byte led = 3;
const byte S1 = 4;
const byte S2 = 5;
const byte PWMMotor = 6;

//----------
rgb_lcd lcd;
int intensLuz = 150;
int V = 255;
int frente = 1;
int flagLed = 0;
int flagMotor =0;
long int botaoControle;

IRrecv irrecv(IRrec);

decode_results results;

void setup() {
   Serial.begin(9600);
   pinMode(S1, OUTPUT);
   pinMode(S2, OUTPUT);
   pinMode(PWMMotor, OUTPUT);
   pinMode(led, OUTPUT);
   lcd.begin(16, 2);
   
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {


  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    botaoControle = results.value;
    irrecv.resume(); // Permite a entrada do próximo valor
  }
  switch(botaoControle){
    case 0xA90:
      onoffLed();
    break;
    case 0xA50:
      onoffMotor();
    break;
    case 0x90:
      aumentaVel();
    break;
    case 0x890:
      diminuiVel();
    break;
    case 0x490:
      setFrente();
    break;
    case 0xC90:
      setTras();
    break;
    case :
      aumentaBrilho();
    break;
    case :
      diminuiBrilho();
    break;
    case :
      onLCD();
    break;
    case :
      offLCD();
    break;
    case :
      setMessage(0);
    break;
    case :
      setMessage(1);
    break;
  }
  botaoControle = 0;
  if(flagLed)
    digitalWrite(led, intensLuz);
  if(flagMotor==1){
    if(frente==1){
      //frente
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      analogWrite(PWMMotor, V);
    }
    else{
      //trás
      digitalWrite(S1, HIGH);
      digitalWrite(S2, LOW);
      analogWrite(PWMMotor, V);
    }
  }
  else {
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  
  delay(100);
}
void onoffaMotor(){
  if (flagMotor==0)
    flagMotor = 1;
  else
    flagMotor = 0;
}
void setFrente(){
  frente=1;
}
void setTras(){
  frente=0;
} 
void aumentaVel(){
  if (V==180)
    V=255;
}
void diminuiVel(){
  if (V==255)
    V=180;
}
void onoffLed(){
  if (flagLed==0)
    flagLed = 1;
  else
    flagLed = 0;
}
void aumentaBrilho(){
  intensLuz += 50;
  if (intensLuz>=255)
    intensLuz = 255;
}
void diminuiBrilho(){
  intensLuz -= 50;
  if (intensLuz<=100)
    intensLuz = 100;
}
void setMessage(int message){
  switch(message){
    case 0:
      lcd.print("hello, world!");
    break;
    case 1:
      lcd.print("test");
    break;
  }
}
void onLCD{
  lcd.display();
}
void offLCD{
  lcd.noDisplay();
}
