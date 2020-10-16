
int Led = 8;
int cont = 0;
int botao = 2;

boolean novaMenssagem=false;
const int analogInPin = A0; // Porta analógica utilizada pelo LDR; 
float estado = 0;           // Estado do LDR;
String lido,palavra; 
String Palavra;
String Ascii;
int estadobotao
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led,OUTPUT);
  pinMode(botao,INPUT);
  digitalWrite(Led,LOW);
  
} 

void loop() {
  if(Serial.available()){
  lido=Serial.readString();
  novaMensagem=true;
  String palavra2;
  Teste=lido.substring(0,(lido.length()-1));  
  }
   estadobotao = digitalRead(botao);
  //Serial.println(estadobotao);
  
  if(estadobotao == 1 && novaMenssagem==true){
  for (int J=0; J < Teste.length(); J++){ 
  //digitalWrite(Led,HIGH);
  
  Palavra = String(Teste[J],BIN); 
  Serial.println(Palavra);
  
  if (cont == 0){
    for (cont = 0; cont <= 6; cont++){
      if(Palavra[cont] == '0'){
        
        digitalWrite(Led,LOW);
        delay(700);
       // LDR_Sensor();
      }
      else if (Palavra[cont] == '1'){
        digitalWrite(Led,HIGH);
        delay(700);
        digitalWrite(Led,LOW);
       // LDR_Sensor();
      }
       else{
        Serial.println("Não fiz nada!");
       }
      }
    }
  digitalWrite(Led,LOW);
  delay(1000);
  cont = 0;
  }
 }
novaMenssagem=false;
}

