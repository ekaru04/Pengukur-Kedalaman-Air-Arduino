#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int trigPin = 11;
const int echoPin = 12;
const int led1 = 2;  //GREEN LED 
const int led2 = 3;  //YELLOW LED
const int led3 = 4;  //RED LED
const int speaker1 = 8; //BEEP WHEN RED LED TURNS ON
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(speaker1, OUTPUT);
  Serial.begin(9600); 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

if (distance <= 30 and distance > 20){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  noTone(speaker1);
  lcd.setCursor(0,0);
  lcd.print("JARAK AIR:        ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(2,1);
  lcd.print("CM        ");
   
}

else if (distance <= 20 and distance > 9){
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  noTone(speaker1);
  lcd.setCursor(0,0);
  lcd.print("JARAK AIR:        ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(2,1);
  lcd.print("CM        ");
    
}

else if (distance <= 9){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  tone(speaker1,2100);
  lcd.setCursor(0,0);
  lcd.print("JARAK AIR:        ");
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.setCursor(1,1);
  lcd.print(distance);
  lcd.setCursor(2,1);
  lcd.print("CM        ");
   
}

else {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  noTone(speaker1);
    lcd.setCursor(0,0);
  lcd.print("JARAK AIR LEBIH");
  lcd.setCursor(0,1);
  lcd.print("   DARI 30CM   ");

 }

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

}
