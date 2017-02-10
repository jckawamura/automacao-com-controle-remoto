//bibliotecas
#include <IRremote.h>
#include <Wire.h>
#include "rgb_lcd.h"

//configuração controle
const long int botaoLed = 0xA90;
const long int botaoLedUp = 0xCD0;
const long int botaoLedDown = 0x2D0;
const long int botaoMotor = 0xA50;
const long int botaoMotorUp = 0x90;
const long int botaoMotorDown = 0x890;
const long int botaoMotorFrente = 0x490;
const long int botaoMotorTras = 0xC90;
const long int botaoLCDOn = 0x70;
const long int botaoLCDOff = 0x290;
const long int botaoMsg1 = 0x10;
const long int botaoMsg2 = 0x810;
const long int botaoMsg3 = 0x410;
const long int botaoMsg4 = 0xC10;
const long int botaoMsg5 = 0x210;
const long int botaoMsg6 = 0xA10;
const long int botaoMsg7 = 0x610;
const long int botaoMsg8 = 0xE10;
const long int botaoMsg9 = 0x110;
const long int botaoMsg0 = 0x910;

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
  irrecv.enableIRIn(); // Inicializa receptor IR
  Serial.begin(9600); //Inicializa serial
  pinMode(led, OUTPUT);  
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(PWMMotor, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2); //Inicializa LCD
}

void loop() {
  //Leitura do botão do controle
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    botaoControle = results.value;
    irrecv.resume(); 
  }
  //Seleciona função dependendo do botão apertado
  switch(botaoControle){
    case botaoLed:
      onoffLed();
    break;
    case botaoMotor:
      onoffMotor();
    break;
    case botaoMotorUp:
      aumentaVel();
    break;
    case botaoMotorDown:
      diminuiVel();
    break;
    case botaoMotorFrente:
      setFrente();
    break;
    case botaoMotorTras:
      setTras();
    break;
    case botaoLedUp:
      aumentaBrilho();
    break;
    case botaoLedDown:
      diminuiBrilho();
    break;
    case botaoLCDOn:
      onLCD();
    break;
    case botaoLCDOff:
      offLCD();
    break;
    case botaoMsg1:
      setMessage(0);
    break;
    case botaoMsg2:
      setMessage(1);
    break;
    case botaoMsg3:
      setMessage(2);
    break;
    case botaoMsg4:
      setMessage(3);
    break;
    case botaoMsg5:
      setMessage(4);
    break;
    case botaoMsg6:
      setMessage(5);
    break;
    case botaoMsg7:
      setMessage(6);
    break;
    case botaoMsg8:
      setMessage(7);
    break;
    case botaoMsg9:
      setMessage(8);
    break;
    case botaoMsg0:
      setMessage(9);
    break;
  }
  botaoControle = 0; //Para não repetir a chamada de função
  //Liga ou desliga led
  if(flagLed)
    analogWrite(led, intensLuz);
  else
    digitalWrite(led, 0);
  //Liga ou desliga motor
  if(flagMotor==1){
    //Decide direção do motor
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
  //desliga motor
  else {
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  
  delay(100); 
}
//muda flag de ligado/desligado do motor
void onoffMotor(){
  if (flagMotor==0)
    flagMotor = 1;
  else
    flagMotor = 0;
}
//muda flag de direção do motor
void setFrente(){
  frente=1;
}
//muda flag de direção do motor
void setTras(){
  frente=0;
} 
//aumenta velocidade do motor
void aumentaVel(){
  if (V==100)
    V=255;
}
//diminui velocidade do motor
void diminuiVel(){
  if (V==255)
    V=100;
}
//muda flag que liga ou desliga o LED
void onoffLed(){
  if (flagLed==0)
    flagLed = 1;
  else
    flagLed = 0;
}
//aumenta brilho do LED
void aumentaBrilho(){
  intensLuz += 100;
  if (intensLuz>=255)
    intensLuz = 255;
}
//diminui brilho do LED
void diminuiBrilho(){
  intensLuz -= 100;
  if (intensLuz<=20)
    intensLuz = 20;
}
//passa mensagem para o LCD
void setMessage(int message){
  switch(message){
    case 0: {
      lcd.clear();
      lcd.print("Disponivel");
      lcd.setRGB(0, 255, 0);
    }
    break;
    case 1: {
      lcd.clear();
      lcd.print("Ocupado");
      lcd.setRGB(255, 0, 0);
    }
    break;
    case 2: {
      lcd.clear();
      lcd.print("Estudando");
      lcd.setRGB(0, 0, 255);
    }
    break;
    case 3: {
      lcd.clear();
      lcd.print("No Mercado");
      lcd.setRGB(255, 255, 0);
    }
    break;
    case 4: {
      lcd.clear();
      lcd.print("Na Festa!!! xD");
      lcd.setRGB(255, 0, 255);
    }
    break;
    case 5: {
      lcd.clear();
      lcd.print("Jogando Online");
      lcd.setCursor(0, 1);
      lcd.print("(Nao Tem Pause)");
      lcd.setRGB(255, 128, 0);
    }
    break;
    case 6: {
      lcd.clear();
      lcd.print("No Banho");
      lcd.setRGB(0, 255, 255);
    }
    break;
    case 7: {
      lcd.clear();
      lcd.print("Na Aula");
      lcd.setRGB(0, 0, 128);
    }
    break;
    case 8: {
      lcd.clear();
      lcd.print("Dormindo");
      lcd.setCursor(0, 1);
      lcd.print("ZZZzzzZZZ");
      lcd.setRGB(128, 128, 128);
    }
    break;
    case 9: {
      lcd.clear();
      lcd.print("Em reuniao");
      lcd.setRGB(128, 64, 0);
    }
    break;
  }
}
//liga LCD
void onLCD(){
  lcd.clear();
  lcd.display();
  lcd.setRGB(255, 255, 255);
}
//desliga LCD
void offLCD(){
  lcd.clear();
  lcd.setRGB(0, 0, 0);
}
