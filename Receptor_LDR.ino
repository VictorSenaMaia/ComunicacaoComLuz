#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Led = 18;
int cont;
int carac = 4;
int value = 0;
int x = 0;
int z = 0;
int y = 0;
int t = 6;
const int analogInPin = A0; // Porta analógica utilizada pelo LDR; 
float estado = 0;           // Estado do LDR;

String Pala;
String Ascii = "";

LiquidCrystal_I2C lcd(0x27,16,2); //Inicializa o display no endereço 0x27;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   //LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("Inicializando..."); 
  delay(1000);
  lcd.clear();
}

void loop() {
 
 estado = analogRead(analogInPin);
 
  if(estado < 1010.00){
  // while (carac >= 0){ 
    for(cont = 0; cont <= 6; cont++){
      delay(10);
      LDR_Sensor();
      
      delay(700);  
    }
    Serial.println("");
    x = 1; 
    //Serial.println(value);
    }    
    
    if(x > 0){ 
       Pala += Ascii;
       if (Pala.length()>96){
       Pala ="";
       Pala+=Ascii;
       lcd.clear();
      }
    
    conversorPalavra(Pala);
       
    }
    
    value = 0;
    Ascii = ""; 
    //cont = 0;
    //x = 0;
    //t = 6;
    //y = 0;
    //z = 0; 
    //lcd.clear();
}

void LDR_Sensor() {
  estado = analogRead(analogInPin);
  if (estado >= 1022.00){
    Serial.print("0");
    Ascii += 0;
  }
  else if(estado < 1022.00) {
    Serial.print("1");
    Ascii += 1;   
   
    }
}
void conversorPalavra(String p){
  
  int tam,vezes,pos1=0,pos2=7;
  tam=p.length();
  vezes=tam/7;
  String letras;
 
  for(int i=0;i<vezes;i++){
    letras=letras+conversorBinDec(p.substring(pos1,pos2));
  
    pos1=pos1+7;
    pos2=pos1+7;
    
  }
  //Serial.println(letras);
  writeLcd("Palavra:",letras);
  }
String conversorBinDec(String c){
double tam,dec=0,j=0;
int decp;
String palavra;
tam=c.length();
//Serial.print("Carroça: ");
for(int i=tam-1;i>=0;i--){
    if(c[i]=='1'){
    dec=dec+pow(2,j);    
    }
  j=j+1;
 
  }
  decp=(int)dec+1;
  
  palavra=(char)decp;
  //Serial.println("");
  //Serial.println(palavra);
  return palavra;
}
void writeLcd(String frase,String frase2){
  delay(50);
  Serial.print(frase2);
  lcd.setCursor(0,0);
  lcd.print(frase); 
  lcd.setCursor(0,1);
  lcd.print(frase2); 
  
}

