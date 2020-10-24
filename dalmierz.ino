#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define trigPin 11
#define echoPin 10

void setup() {
  Serial.begin (9600);
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  lcd.begin(16, 2);
  lcd.clear();
 
}

void loop() {
  int odleglosc=dystans_SR04();
  lcd_wyswietl(odleglosc);
  delay(1000);
}
  int dystans_SR04() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  //przeliczenie czasu trwania impulsu - nota katalogowa
  dystans = czas / 58;
 
  return dystans;
}

void lcd_wyswietl(int odleglosc )
{
  lcd.setCursor(0,0);
  lcd.print("Dystans od celu:");
  lcd.setCursor(0,1);
  lcd.print(odleglosc);
  lcd.setCursor(7,1);
  lcd.print("cm");
  }
