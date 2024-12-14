#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define led1 4
#define led2 6
#define led3 5
#define RX 2
#define TX 3
#define rs A0
#define en A1
#define d5 A2
#define d6 A3
#define d7 A4
#define d8 A5
#define relay1 7
#define relay2 8
#define relay3 9
String comp1 = "Coffee";
String comp2 = "Mix Juice";
String comp3 = "Cocktail";
LiquidCrystal lcd(rs , en , d5 , d6 , d7 , d8);
SoftwareSerial myserial (RX , TX);

void setup()
{
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(relay1 , OUTPUT);
  pinMode(relay2 , OUTPUT);
  pinMode(relay3 , OUTPUT);
  myserial.begin(9600);
  Serial.begin(9600);
  lcd.begin(20 , 4);
}

void loop()
{
  lcd.setCursor(0 ,0);
  lcd.print("Please choose a drink :");
  lcd.setCursor(0 , 1);
  lcd.print("1 Coffee"); 
  lcd.setCursor(0 , 2);
  lcd.print("2 Mix Juice");
  lcd.setCursor(0 , 3);
  lcd.print("3 Cocktail");
  digitalWrite(1 , HIGH);
  if (myserial.available() > 0)
  {
    String val =  myserial.readStringUntil('\n');   
    val.trim();//We trim this user input to remove extra or blank spaces
    if (val == comp1)
    {
      digitalWrite(led1 , LOW);
      Coffee();
    }
    if (val == comp2)
    {
      digitalWrite(led1 , LOW);
      MixJuice();
    }
    if (val == comp3)
    {
      digitalWrite(led1 , LOW);
      Cocktail();
    }
  }
}

void Coffee()
{
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print("COFFEE PRO START");
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , HIGH);
  digitalWrite(relay1 , HIGH);
  delay(2000);
  digitalWrite(relay1 , LOW);
  digitalWrite(relay2 , HIGH);
  delay(3000);
  digitalWrite(relay2 , LOW);
  digitalWrite(relay3 , HIGH);
  delay(5000);
  digitalWrite(relay3 , LOW);
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , HIGH);
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print("Coffee is Ready");
  delay(2000);
  digitalWrite(led3 , LOW);
}

void MixJuice()
{
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print("JUICE PRO START");
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , HIGH);
  digitalWrite(relay1 , HIGH);
  delay(5000);
  digitalWrite(relay1 , LOW);
  digitalWrite(relay2 , HIGH);
  delay(7000);
  digitalWrite(relay2 , LOW);
  digitalWrite(relay3 , HIGH);
  delay(9000);
  digitalWrite(relay3 , LOW);
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , HIGH)
  lcd.clear()
  lcd.setCursor(0 , 0);
  lcd.print("Juice is Ready");
  delay(2000);
  digitalWrite(led3 , LOW);
}

void Cocktail()
{
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print("COCKTAIL PRO START");
  digitalWrite(led1 , LOW);
  digitalWrite(led2 , HIGH);
  digitalWrite(relay1 , HIGH);
  delay(3000);
  digitalWrite(relay1 , LOW);
  digitalWrite(relay2 , HIGH);
  delay(6000);
  digitalWrite(relay2 , LOW);
  digitalWrite(relay3 , HIGH);
  delay(8000);
  digitalWrite(relay3 , LOW);
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , HIGH);
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print("Cocktail is Ready");
  delay(2000);
  digitalWrite(led2 , LOW);
}