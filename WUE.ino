#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Wire.h>
#include <DFRobotDFPlayerMini.h> 



#define TFT_CS   7
#define TFT_DC   1
#define TFT_RST  0  

DFRobotDFPlayerMini myDFPlayer ; 
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int buttonwstate = 3;
int buttonrstate = 3;
int compteur = 0;
int mp3Busy = 3;
int choixMenu = 0;

void IRAM_ATTR boutonB() {
    ets_printf("Boutton Bl pressé\n");
    buttonwstate = 0;

    // Code de la fonction
}
void IRAM_ATTR boutonR() {
    ets_printf("Boutton Ro pressé\n");
    buttonrstate = 0;
    // Code de la fonction
}

void setup() {
Serial.begin(115200);
    Serial1.begin(9600,SERIAL_8N1, 3,2);
    pinMode(9, INPUT);
    pinMode(5, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    attachInterrupt(5, boutonB, FALLING);
    attachInterrupt(10, boutonR, FALLING);
    myDFPlayer.begin(Serial1) ;
    printf("DFRobot DFPlayer Mini Demo\n");
    printf("Initializing DFPlayer ... (May take 3~5 seconds)\n");
    delay(5000);
    printf("DFPlayer Mini online.\n");
}

void loop() {
  Menu1();
}

void Menu1(){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(70, 10);
  tft.print("Wake Up Eva");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Toilette Matin: Bt Bl");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Suivant: Bt Ro");
  choixMenu = 1;

while ((buttonrstate != 0 ) && (buttonwstate != 0)){
  delay(100);
  }
   if(buttonwstate == 0){
    buttonrstate = 3;
    buttonwstate = 3;
     ProgL1();
     }
   if(buttonrstate == 0){
   buttonrstate = 3;
   buttonwstate = 3;
   Menu2();
   }
}

void Menu2(){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(70, 10);
  tft.print("Wake Up Eva");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage Dents Bt Bl");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Suivant: Bt Ro");
  choixMenu = 2;

while ((buttonrstate != 0 ) && (buttonwstate != 0)){
  delay(100);
  }
   if(buttonwstate == 0){
      buttonrstate = 3;
      buttonwstate = 3;
     ProgDents1();
     }
   if(buttonrstate == 0){
    buttonrstate = 3;
    buttonwstate = 3;
    Menu1();
   }
}



void ProgL1(){ 

  int retour_choix = 0;
  while ( retour_choix != 1 ){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 1");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Deshabille Toi");
  myDFPlayer.playFolder(2, 1);
  delay(60000);
  retour_choix = choix();
  }
  ProgL2();
}

void ProgL2(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 2");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lave Toi");
  myDFPlayer.playFolder(2, 2);
  delay(60000);
  retour_choix = choix();
  }
ProgL3();
}

void ProgL3(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 3");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Essuie Toi");
  myDFPlayer.playFolder(2, 3);
  delay(30000);
  retour_choix = choix();
  }
ProgL4();
}

void ProgL4(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 4");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Mets ton slip/boxer");
  myDFPlayer.playFolder(2, 4);
  delay(30000);
  retour_choix = choix();
  }
ProgL5();
}

void ProgL5(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 5");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Mets ton haut");
  myDFPlayer.playFolder(2, 5);
  delay(30000);
  retour_choix = choix();
  }
ProgL6();
}

void ProgL6(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 6");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("tes chaussettes");
  myDFPlayer.playFolder(2, 6); 
  delay(30000);
  retour_choix = choix();
  }
ProgL7();
}

void ProgL7(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 7");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Mets ton bas");
  myDFPlayer.playFolder(2, 7);
  delay(30000);
  retour_choix = choix();
  }
  myDFPlayer.playFolder(2, 8);
  mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture\n");
     delay(100);
   }
      printf("Sortie lecture\n");
ProgFin();
}

void ProgDents1(){ 

  int retour_choix = 0;
  while ( retour_choix != 1 ){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 1");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Met le dentifrice");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(5, 50);
  tft.print("Sur ta brosse a dents");
  myDFPlayer.playFolder(3, 1);
  delay(15000);
  retour_choix = choix();
  }
  ProgDents2();
}

void ProgDents2(){
  int retour_choix = 0;
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 2");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Haut en premier");

  myDFPlayer.playFolder(3, 21);
  delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 1\n");
     delay(100);
   }
      printf("Sortie lecture dents 1\n");

  myDFPlayer.playFolder(3, 20);
  delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 2\n");
     delay(100);
   }
     printf("Sortie lecture dents 2\n");

  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 3");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents Haut");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Maintenant Derriere");
  myDFPlayer.playFolder(3, 22);
       delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 1\n");
     delay(100);
   }
      printf("Sortie lecture dents 1\n");

  myDFPlayer.playFolder(3, 20);
  delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 2\n");
     delay(100);
   }
     printf("Sortie lecture dents 2\n");

tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 4");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents Haut");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Les dents du fond");
  myDFPlayer.playFolder(3, 23);
  delay(100);
      mp3Busy = digitalRead(9);

   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture\n");
     delay(100);
   }
      printf("Sortie lecture\n");

  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 5");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Bas avant");
  myDFPlayer.playFolder(3, 24);
    delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 1\n");
     delay(100);
   }
      printf("Sortie lecture dents 1\n");

  myDFPlayer.playFolder(3, 20);
  delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 2\n");
     delay(100);
   }
     printf("Sortie lecture dents 2\n");

  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 6");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents Bas");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Maintenant Derriere");
  myDFPlayer.playFolder(3, 25);
     delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 1\n");
     delay(100);
   }
      printf("Sortie lecture dents 1\n");

  myDFPlayer.playFolder(3, 20);
  delay(100);
     mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture dents 2\n");
     delay(100);
   }
     printf("Sortie lecture dents 2\n");

tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 7");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Lavage dents Bas");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Les dents du fond");
  myDFPlayer.playFolder(3, 23);
  delay(100);
      mp3Busy = digitalRead(9);
   while (mp3Busy == LOW){
     mp3Busy = digitalRead(9);
     printf("lecture\n");
     delay(100);
   }
      printf("Sortie lecture\n");

ProgDents3();
}

void ProgDents3(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284); 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 8");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Crache et");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Rince ta Bouche");
  myDFPlayer.playFolder(3, 3);
  delay(20000);
  retour_choix = choix();
  }
ProgDents4();
}

void ProgDents4(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 9");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Rince ta brosse");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("a dents");
  myDFPlayer.playFolder(3, 4);
  delay(10000);
  retour_choix = choix();
  }
ProgDents5();
}



void ProgDents5(){
  int retour_choix = 0;
while ( retour_choix != 1 ){
  tft.init(76, 284); 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("Etape 10");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Un gant mouille");
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("lave ton visage");
  myDFPlayer.playFolder(3, 5); 
  delay(30000);
  retour_choix = choix();
  }
ProgFin();
}


void ProgFin(){
  tft.init(76, 284); 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("YOUPI !");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Tu as fini !");
  myDFPlayer.playFolder(1, 3);  
  delay(10000);
  buttonrstate = 3;
  buttonwstate = 3;
  Menu1();
}

int choix(){
  buttonrstate = 3;
  buttonwstate = 3;
  int valeur_choix = 0 ;
  tft.init(76, 284);
 
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.print("As-tu Fini ?");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 30);
  tft.print("Oui:Bl Non:Ro");
  myDFPlayer.playFolder(1, 2);  //play specific mp3 in SD Folder Name(1~99); File Name(1~255)
  delay(100);
  mp3Busy = digitalRead(9);
  while (mp3Busy == LOW){
    mp3Busy = digitalRead(9);
    printf("lecture\n");
    delay(100);
  }
      printf("Sortie lecture\n");
  while ((buttonrstate != 0 ) && (buttonwstate != 0)){
  
  myDFPlayer.playFolder(1, 1);
  delay(2500);
  }
  
  if(buttonwstate == 0){
   valeur_choix = 1 ;
  }
  if(buttonrstate == 0){
   valeur_choix = 2 ;
  }
  return (valeur_choix);
}
