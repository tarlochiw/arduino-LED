#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int analogpin = 36;
int mem = 0;
int med = 0;
int sw1 = 27;
int sw2 = 16;
int sw3 = 26;
int led1 = 25;
int led2 = 18;
int led3 = 19;
int led4 = 23;
char menu[1][16] = {"Select Up/Down "};
char menu2[4][16] = {"#1 PROG <1> ", "#2 PROG <2> ", "#3 PROG <3> ", "#4 PROG <4> "};
int potValue = 0 ;
int outputvalue = 0;

void setup()

{
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  lcd.begin();
  lcd.backlight();
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(1, 0);
    lcd.print("               ");
    lcd.setCursor(5, 0);
    lcd.print("APISIT       ");
    lcd.setCursor(4, 1);
    lcd.print("PHIMSAN");
    delay(1000);
    lcd.print("               ");
    lcd.setCursor(1, 0);
    lcd.print("*** TEST ***");
    lcd.setCursor(4, 1);
    lcd.print("ARDUINO");
    delay(1000);
  }
  lcd.setCursor(1, 0); lcd.print(menu[med]);
  lcd.setCursor(3, 1); lcd.print(menu2[mem]);
}

void loop()
{
  if (!digitalRead(sw1)) {
    while (!digitalRead(sw1)) {
      delay(2);
    }
    if (mem < 3) mem++;
    lcd.setCursor(1, 0); lcd.print(menu[med]);
    lcd.setCursor(3, 1); lcd.print(menu2[mem]);
    delay(200);
  }
  else if (!digitalRead(sw2)) {
    while (!digitalRead(sw2)) {
      delay(2);
    }
    if (mem > 0) mem--;
    lcd.setCursor(1, 0); lcd.print(menu[med]);
    lcd.setCursor(3, 1); lcd.print(menu2[mem]);
    delay(200);
  }
  else if (!digitalRead(sw3)) {
    while (!digitalRead(sw3)) {
      delay(2);
    }
    if (mem == 0) {
      lcd.setCursor(1, 1);
      delay(300); show_RUN();
    }
    else if (mem == 1) {
      lcd.setCursor(3, 1); lcd.print("Running...   ");
      delay(300); show_LED();
    }
    else if (mem == 2) {
      lcd.setCursor(1, 1);
      delay(300); show_numcount();
    }
    else if (mem == 3) {
      lcd.setCursor(1, 1);
      delay(300); show_analogh();
    }

    delay(500);
    lcd.setCursor(0, 1);
    lcd.print("                "); // clear row 2
    lcd.setCursor(1, 0); lcd.print(menu[med]);
    lcd.setCursor(3, 1); lcd.print(menu2[mem]);
  }

}

void show_RUN(void)
{
  for (int i = 0; i < 4; i++)
  {
    lcd.setCursor(0, 1);
    lcd.print("               ");
    delay(300);
    lcd.setCursor(2, 1);
    lcd.print(" LED Blink! ");
    delay(300);

  }
}
void show_LED(void)
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led4, HIGH);
    delay(300);

    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    delay(300);
  }
}
void show_numcount(void) {
  lcd.setCursor(1, 1);
  lcd.print("Time Count : ");
  for (int a = 0; a <= 59; a++) {
    lcd.setCursor(13, 1);
    lcd.print(a);
    delay(200);
  }
}
void show_analogh(void) {
  while(digitalRead(sw1)) {
  potValue = analogRead(analogpin);
    outputvalue = map(potValue, 0, 4095, 0, 80);
    lcd.setCursor(1, 1);
    lcd.print("Heat :   %      ");
    lcd.setCursor(8, 1);
    lcd.print(outputvalue);
    delay(100);
  }
}
