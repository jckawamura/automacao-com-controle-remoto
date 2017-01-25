int S1 = 4;
int S2 = 5;
int PWMMotor = 6;
int V = 255;
int A = 30;
int frente =1;

void setup() {
   pinMode(S1, OUTPUT);
   pinMode(S2, OUTPUT);
   pinMode(PWMMotor, OUTPUT);
}

void loop() {
  
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

  //desligar
  //digitalWrite(S1, LOW);
  //digitalWrite(S2, LOW);
    
}
void setFrente(){
  frente=1;
}
void setTras(){
  frente=0;
} 
void aumentaVel(){
  V+=A;
}
void diminuiVel(){
  V-=A;
}

