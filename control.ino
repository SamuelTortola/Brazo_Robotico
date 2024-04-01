/** en este prorgrama hecho en el año 2020 se hara el control del primer robot de samuel david torotla bardales  
 *  
 */




//CODIGO PARA EL CONTROL

 
int bot1=2,bot2=3;
int pot1x = A0;
int pot1y = A1;
int pot2x = A2;
int pot2y = A3;
int pot3x = A4;
int pot3y = A5;

void setup() {
  Serial.begin(38400);
 pinMode(bot2,INPUT);
 pinMode(bot1,INPUT);
}

void loop() {

  
  //*********************+*control de garra**********************:

//servomotor que rota la garra:
if(analogRead(pot1x) >= 1010){
Serial.write('A');
delay(15);
Serial.write(7);

}
else if(analogRead(pot1x) <= 10){
Serial.write('B');
delay(15);
Serial.write(7);

}

       
//servomor que eleva el brazo de la garra:
else if(analogRead(pot1y) >= 1010){
Serial.write('C');
delay(15);
Serial.write(7);

}
else if(analogRead(pot1y) <= 10){
Serial.write('D');
delay(15);
Serial.write(7);

}


//servomotor codo
else if(analogRead(pot2x) >= 1010){
Serial.write('E');
delay(15);
Serial.write(7);

}
else if(analogRead(pot2x) <= 10){
Serial.write('F');
delay(15);
Serial.write(7);

}

//servomotor rotagarra:
 else if(analogRead(pot2y) >= 1010){
Serial.write('G');
delay(15);
Serial.write(7);

}
 else if(analogRead(pot2y) <= 10){
Serial.write('H');
delay(15);
Serial.write(7);
}



//servomotor garra:
 else if(digitalRead(bot1)==LOW){
  Serial.write('I'); 
  delay(15);
Serial.write(7);

}

 else if(digitalRead(bot2)==LOW){
  Serial.write('J');
  delay(15);
Serial.write(7);

}




//****************** llantas del carro*************************
//para atras:
else if(analogRead(pot3x)>=1010){
  Serial.write('V');
delay(15);
Serial.write(7);


}

//para delante:
else if(analogRead(pot3x)<=5){
 Serial.write('W');
 delay(15);
Serial.write(7);

}

//dar vuelta a la izquierda
else if(analogRead(pot3y) >= 1010){
  Serial.write('S');
 delay(15);
Serial.write(7);

}
//dar la vuelta a la derecha

else if(analogRead(pot3y) <= 5){
  Serial.write('Z');
  delay(15);
Serial.write(7);

}

else if(analogRead(pot3x) < 800 && analogRead(pot3x) > 590){
Serial.write('p');
}
else if(analogRead(pot3x) < 480 && analogRead(pot3x) > 50){
Serial.write('p');
}

else if(analogRead(pot3y) < 800 && analogRead(pot3y) > 590){
Serial.write('p');
}
else if(analogRead(pot3y) < 480 && analogRead(pot3y) > 50){
Serial.write('p');
}

}
