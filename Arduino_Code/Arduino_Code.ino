#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int humidite_sol_Pin = A0;
int LDR_Pin = A1;
int LM35_Pin = A2;
const int Lamp = 6;
const int pompe = 5;
const int buzzer = 3;
const int pluie_Pin = 7;
int Flame_Pin = 4;

void setup() {
  lcd.begin(20, 4);
  pinMode(Lamp ,OUTPUT);
  pinMode(pompe,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Temp= ");
  lcd.setCursor(0,1);
  lcd.print("luminosite: ");
  lcd.setCursor(0,2);
  lcd.print("Hum Value: ");
  lcd.setCursor(0,3);
  lcd.print("flame value: ");}
 
  

void loop() {
  int LDRValue = analogRead(LDR_Pin);   
  int humidite_Value = analogRead(A0);  
  int Valeur=analogRead(LM35_Pin);
  int Vout=Valeur*5.0/1023*1000;
  int temp=Vout/10;
  int pluie_val = digitalRead(pluie_Pin); 
 
 
   if(humidite_Value > 700 )
   {digitalWrite(pompe, HIGH); }
   else
   {digitalWrite(pompe, LOW); }
   
  int flame_val = digitalRead(Flame_Pin); 
  if(flame_val == true )
  { tone(buzzer, 1000);  // Activer le buzzer avec une fréquence de 1000 Hz
  delay(1000);  
  noTone(buzzer);  
  delay(1000); } 
  else
  {noTone(buzzer); }
    
  float SensorVolts = analogRead(humidite_sol_Pin)*0.0048828125;   
  if(LDRValue<=200){digitalWrite(Lamp,HIGH);}
  else{digitalWrite(Lamp,LOW);}
  lcd.setCursor(7,0);
  lcd.print(temp);
  lcd.setCursor(12, 1);  
  lcd.print(LDRValue);
  lcd.setCursor(14, 2);  
  lcd.print(humidite_Value);
  lcd.setCursor(14, 3);  
  lcd.print(flame_val); 
  delay(10);
}
