
//#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int pin = 5; //PINO DIGITAL UTILIZADO PELO MÓDULO
unsigned long clock1;
byte vezes=0;
char bits[9]; 
int c=12;
String letra="asa",binario;
void setup(){
  
 pinMode(pin, OUTPUT); //DEFINE O PINO COMO ENTRADA
 Serial.begin (9600); //INICIALIZA A SERIAL
 while(!Serial){}
 //delay(2000);
 digitalWrite(pin,LOW);
 delay(1000);


 
// digitalWrite(pin,HIGH); 
// delay(1000);
//
// digitalWrite(pin,LOW); 
// delay(1000);
//
// digitalWrite(pin,LOW); 
// delay(1000);
//
// digitalWrite(pin,LOW); 
// delay(1000);
//
// digitalWrite(pin,LOW); 
// delay(1000);
//
// digitalWrite(pin,LOW); 
// delay(200);
//
// digitalWrite(pin,HIGH); 
// delay(200);
// 
// digitalWrite(pin,LOW); 
// delay(200);
}
 
void loop(){
 if(Serial.available()){
    letra=(char)Serial.read();
     c=letra.toInt();
     binario=String(c,BIN);
       
     Serial.println(binario);
     Serial.print("Tamanho Binário:");
     Serial.println(binario.length());
     
     
  }
//  c=letra.toInt();
//  Serial.println(c);
//  delay(1000);
  
}
//void codificador(String letra){
//  int i,j,c;
//  letra="c";
//  Serial.print("Código binário: ");
////  char letra[55];
//
// // for(i=0;letra[i]!='\0';i++){
//    c=letra.toInt();
//    for(j=7;j+1>0;j--){
//      if(letra>=(1<<j)){
//        letra=letra-(1<<j);
//        Serial.println("1");
//      }else{
//        Serial.println("0");
//      }
//   // }
//    Serial.println(" ");
//  }
//}
