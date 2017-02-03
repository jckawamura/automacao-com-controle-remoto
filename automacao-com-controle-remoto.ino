#include <IRremote.h>
#include <Wire.h>
#include "rgb_lcd.h"

//portas
const byte IRrec = 2;
const byte led = 9;
const byte S1 = 4;
const byte S2 = 5;
const byte PWMMotor = 6;

//----------
rgb_lcd lcd;
int intensLuz = 200;
int V = 255;
int frente = 1;
int flagLed = 0;
int flagMotor = 0;
long int botaoControle;

IRrecv irrecv(IRrec);

decode_results results;

void setup() {
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT);   
  Serial.begin(9600);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(PWMMotor, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
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
    case 0xCD0:
      aumentaBrilho();
    break;
    case 0x2D0:
      diminuiBrilho();
    break;
    case 0x70:
      onLCD();
    break;
    case 0x290:
      offLCD();
    break;
    case 0x10:
      setMessage(0);
    break;
    case 0x810:
      setMessage(1);
    break;
  }
  botaoControle = 0;
  if(flagLed)
    analogWrite(led, intensLuz);
  else
    digitalWrite(led, 0);
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
void onoffMotor(){
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
  if (intensLuz<=50)
    intensLuz = 50;
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
void onLCD(){
  lcd.display();
}
void offLCD(){
  lcd.noDisplay();
  lcd.setRGB(0, 0, 0);
}
