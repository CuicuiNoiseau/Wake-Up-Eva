#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
const int BUZZ_PIN = 10;
ezButton buttonw(0);
ezButton buttonr(1);
int buttonwstate = 3;
int buttonrstate = 3;
int compteur = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
//LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup() {
  Serial.begin(9600);
  pinMode(BUZZ_PIN, OUTPUT);
  buttonw.setDebounceTime(50);
  buttonr.setDebounceTime(50);

}

void loop() {
  buttonw.loop();
  buttonr.loop();
  Menu();
}

void Menu(){
  buttonw.loop();
  buttonr.loop();

 lcd.init(); 
 lcd.backlight();
  lcd.setCursor(2, 0);            
  lcd.print("Wake Up Eva");          
  lcd.setCursor(0, 1);            
  lcd.print("Normal:Bl Sbs:Ro"); 
  while ((buttonrstate != 0 ) && (buttonwstate != 0)){
      buttonw.loop();
      buttonr.loop();
      buttonrstate = buttonr.getState();
      buttonwstate = buttonw.getState();

  }
   if(buttonw.isPressed()){
      ProgSimple();
   }

   if(buttonr.isPressed()){
   ProgL1();
   }
}

void ProgL1(){ 
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();      
  lcd.setCursor(0, 0);            
  lcd.print("Etape 1"); 
  lcd.setCursor(0, 1);            
  lcd.print("Deshabille Toi");         
  delay(120000);
  retour_choix = choix();
  }
ProgL2();

}

void ProgL2(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();         
  lcd.setCursor(0, 0);            
  lcd.print("Etape 2"); 
  lcd.setCursor(0, 1);            
  lcd.print("Lave Toi");         
  delay(120000);
  retour_choix = choix();
  }
ProgL3();
}

void ProgL3(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();         
  lcd.setCursor(0, 0);            
  lcd.print("Etape 3"); 
  lcd.setCursor(0, 1);            
  lcd.print("Essuie Toi");         
  delay(120000);
  retour_choix = choix();
  }
ProgL4();
}

void ProgL4(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();          
  lcd.setCursor(0, 0);            
  lcd.print("Etape 4"); 
  lcd.setCursor(0, 1);            
  lcd.print("Mets ta culotte");
  delay(120000);
  retour_choix = choix();
  }
ProgL5();
}

void ProgL5(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();        
  lcd.setCursor(0, 0);            
  lcd.print("Etape 5"); 
  lcd.setCursor(0, 1);            
  lcd.print("Mets ton Tee-Shirt");         
  delay(120000);
  retour_choix = choix();
  }
ProgL6();
}

void ProgL6(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();       
  lcd.setCursor(0, 0);            
  lcd.print("Etape 6"); 
  lcd.setCursor(0, 1);            
  lcd.print("Mets tes chaussettes");         
  delay(120000);
  retour_choix = choix();
  }
ProgL7();
}

void ProgL7(){
  buttonw.loop();
  buttonr.loop();
  int retour_choix = 0;
while ( retour_choix != 1 ){
  lcd.clear();
  lcd.backlight();         
  lcd.setCursor(0, 0);            
  lcd.print("Etape 7"); 
  lcd.setCursor(4, 1);            
  lcd.print("Mets ton bas");         
  delay(120000);
  retour_choix = choix();
  }
ProgFin();
}

void ProgFin(){
  lcd.clear();
  lcd.backlight();       
  lcd.setCursor(0, 0);            
  lcd.print("YOUPI"); 
  lcd.setCursor(4, 1);            
  lcd.print("Tu as fini !");         
  while(1);
}

int choix(){
  buttonw.loop();
  buttonr.loop();
  buttonrstate = 3;
  buttonwstate = 3;
  int valeur_choix = 0 ;
  lcd.backlight();
  lcd.clear();          
  lcd.setCursor(0, 0);            
  lcd.print("As-tu Fini ?"); 
  lcd.setCursor(0, 2);            
  lcd.print("Oui:Bl Non:Ro");          
  while ((buttonrstate != 0 ) && (buttonwstate != 0)){
  lcd.backlight();
  digitalWrite(BUZZ_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZ_PIN, LOW);
  delay(250);
  digitalWrite(BUZZ_PIN, HIGH);
  delay(75);
  digitalWrite(BUZZ_PIN, LOW);
  delay(750);
  lcd.noBacklight();
  delay (500);
  buttonw.loop();
  buttonr.loop();
  buttonrstate = buttonr.getState();
  buttonwstate = buttonw.getState();
  }
  
  if(buttonw.isPressed()){
   valeur_choix = 1 ;
  }
  if(buttonr.isPressed()){
   valeur_choix = 2 ;
  }
  return (valeur_choix);
}

void ProgSimple(){
buttonw.loop();
  buttonr.loop();
  lcd.clear();
  lcd.setCursor(0, 0);           
  lcd.print("Eva ne te"); 
  lcd.setCursor(4, 1);
  lcd.print("Perd PAS !");
  delay(5000);
  lcd.noBacklight();
  delay (60000);
  
  do {
  lcd.backlight();
  digitalWrite(BUZZ_PIN, HIGH);
  delay(200);
  buttonwstate = buttonw.getState();
  digitalWrite(BUZZ_PIN, LOW);
  delay(250);
  buttonwstate = buttonw.getState();
  digitalWrite(BUZZ_PIN, HIGH);
  delay(75);
  buttonwstate = buttonw.getState();
  digitalWrite(BUZZ_PIN, LOW);
  delay(750);
  buttonwstate = buttonw.getState();
  lcd.noBacklight();
  delay (500);
  buttonwstate = buttonw.getState();
  }
  while (buttonwstate == 1);
}
