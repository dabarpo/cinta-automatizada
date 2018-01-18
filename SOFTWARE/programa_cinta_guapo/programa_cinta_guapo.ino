#include <Stepper.h>
#include <LiquidCrystal.h>
#define STEPS 200
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
Stepper steper(STEPS, 30, 31, 32, 33); //Stepper nombre motor (número de pasos por vuelta, pins de control)
int a=2;
int b=0; 
void setup()
{
  lcd.begin(16, 2);
 Serial.begin(9600); // Velocidad del motor en RPM
  steper.setSpeed(100);//cinta
  pinMode(51,INPUT);//sensor
  pinMode(34,INPUT);//pulsador
  pinMode(13,OUTPUT);//rojo
  pinMode(44,OUTPUT);//verde
  while(digitalRead(34)==0){//marcha
    if(a==2){
      digitalWrite(13,1);
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Pulse para");
       lcd.setCursor(0, 1);
       lcd.print("continuar");
    }
    a=3;
    
  }
  digitalWrite(13,0);
  digitalWrite(44,1);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(b);
  lcd.print(" objetos");
}
 
void loop()
{
  
  while(digitalRead(51)==1){
  steper.step(1);
  delay(5);
}
b++;
lcd.clear();
lcd.setCursor(0, 0);
lcd.print(b);
lcd.print(" objetos");
 for(a=0;a<700;a++){
  steper.step(1);
  delay(5);
 }
}
