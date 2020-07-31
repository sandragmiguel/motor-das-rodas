#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int const trigPin = 10;
int const echoPin = 9;
int ledVerde = 6;
int ledAmarelo= 7;
int ledvermelho = 13;
int motorPin = A1; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(motorPin, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration / 2) / 29.1;
if (distance > 0 && distance <=10) {
  Serial.println(distance);
  lcd.noAutoscroll();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA: ");
  lcd.print(distance);
  digitalWrite(ledvermelho, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(motorPin, HIGH);
  delay(1000);
}
else if(distance > 10 && distance <=20){
  Serial.println(distance);
  lcd.noAutoscroll();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA: ");
  lcd.print(distance);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledVerde, LOW);
  delay(1000);
}
else if(distance > 20 && distance <=30){
  Serial.println(distance);
  lcd.noAutoscroll();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA: ");
  lcd.print(distance);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  delay(1000);
}
else {
  Serial.println(distance);
  lcd.noAutoscroll();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA: ");
  lcd.print(distance);
  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  delay(1000);
}
delay(1000);
}
