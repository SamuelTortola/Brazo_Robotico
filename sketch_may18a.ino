#include<Servo.h>
//carro
Servo rotar;
Servo brazo;
Servo codo;
Servo rotagarra;
Servo garra;

int in1=7,in2=8,in3=9,in4=10;

int t=0;
int controtar=70,contbrazo=30,contcodo=90,controtagarra=90,contgarra=174;
char serial;

void setup() {
rotar.attach(2); //ya
brazo.attach(4); //ya
codo.attach(3);//ya
rotagarra.attach(5); //ya
garra.attach(6); //ya

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

Serial.begin(38400);
}

void loop() {
 serial=Serial.read();
 
 //**************************************control de garra*****************************************************:
rotar.write(contbrazo);
 brazo.write(controtar);
 codo.write(contcodo);
 rotagarra.write(controtagarra);
 garra.write(contgarra);


 
 //servomotor brazo:
if(controtar<21)
controtar=20;

if(controtar>131)
controtar=130;

   if(serial == 'A'){
   controtar = controtar+1;
   delay(10);
   }
   if(serial == 'B'){
   controtar = controtar-1;
   delay(10);
   }
   
//servomotor rotar:
if(contbrazo<1)
contbrazo=0;

if(contbrazo>179)
contbrazo=180;

   if(serial == 'C'){
   contbrazo = contbrazo+1;
   delay(10);
   }
   if(serial == 'D'){
   contbrazo  = contbrazo-1;
   delay(10);
   }

//servomotor codo:
    if(contcodo<25)
contcodo=24;
if(contcodo>151)
contcodo=150;

   if(serial == 'E'){
   contcodo = contcodo-1;
   delay(10);
   }
   if(serial == 'F'){
   contcodo  = contcodo+1;
   delay(10);
   }

//servomotor rotagarra:
  if(controtagarra<1)
controtagarra=0;

if(controtagarra>129)
controtagarra=130;

   if(serial == 'G'){
   controtagarra = controtagarra+1;
   delay(10);
   }
   if(serial == 'H'){
   controtagarra  = controtagarra-1;
   delay(10);
   }

//servomotor garra:
   if(contgarra<101)
contgarra=100;

if(contgarra>179)
contgarra=180;

   if(serial == 'I'){
   contgarra = contgarra+1;
   delay(10);
   }
   if(serial == 'J'){
   contgarra  = contgarra-1;
   delay(10);
   }
else {
  
}

//   *****************************codigo del carro***************************
   //para atras:
   if((serial=='W') && (t==0)){
    digitalWrite(in1,0);
    digitalWrite(in2,1);
    digitalWrite(in4,0);
    digitalWrite(in3,1);
   }

   //para adelante:
   if((serial=='V') && (t==0)){
    digitalWrite(in1,1);
    digitalWrite(in2,0);
    digitalWrite(in3,0);
    digitalWrite(in4,1);
    
}

//para dar la vuelta a la izquierda:
  if((serial=='S') && (t==0)){
    digitalWrite(in1,1);
    digitalWrite(in2,0);
    digitalWrite(in3,0);
    digitalWrite(in4,0);
}

//para dar la vuelta a la derecha:
if((serial=='Z')&& (t==0)){
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    digitalWrite(in3,0);
    digitalWrite(in4,1);
}
 else if(serial=='p'){
  t=1;
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    digitalWrite(in4,0);
    digitalWrite(in3,0);
    delay(15);
    t=0;
}

}
