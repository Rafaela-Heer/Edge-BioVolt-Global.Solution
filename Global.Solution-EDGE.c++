#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(34, 16, 2);

#define ledG 13
#define ledY 12
#define ledR 11
#define buzzer 9
#define motorPin 10
#define button 2
#define mq135 A0
#define tempPin A2
int limiteGas = 700;
float limiteTemperatura = 100.0;
bool geradorLigado = false;

void setup() {

  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(button, INPUT);

  digitalWrite(motorPin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Gerador");
  lcd.setCursor(4, 1);
  lcd.print("Biomassa");
  delay(2000);
  Serial.begin(9600);

}

void loop() {

  bool botaoPressionado = digitalRead(button) == HIGH;

  int temp = analogRead(tempPin);
  float temperatura = (temp * (5.0 / 1023.0) - 0.5) * 100.0;

  if (temperatura > limiteTemperatura && geradorLigado) {
    
    geradorLigado = false;
    Serial.println("ALERTA: Temperatura alta - Desligando gerador");

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("TEMP ALTA!");
    lcd.setCursor(2, 1);
    lcd.print(temperatura);
    lcd.print("C");

    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(3000);

  }

  else {

    geradorLigado = botaoPressionado;

  }
  
  lcd.clear();
  Serial.print("Estado do Gerador: ");
  Serial.println(geradorLigado ? "Ligado" : "Desligado");

  if (geradorLigado) {

    int nivelGas = analogRead(mq135);
    int velocidadeMotor = map(nivelGas, 0, limiteGas, 255, 0);
    int porcentagemVelocidade = map(nivelGas, 0, limiteGas, 0, 100);

    if (nivelGas < 350) {

      digitalWrite(ledG, HIGH);
      digitalWrite(ledY, LOW);
      digitalWrite(ledR, LOW);

    } 

    else if (nivelGas <= 550) {

      digitalWrite(ledG, LOW);
      digitalWrite(ledY, HIGH);
      digitalWrite(ledR, LOW);

    }

    else {

      digitalWrite(ledG, LOW);
      digitalWrite(ledY, LOW);
      digitalWrite(ledR, HIGH);

    }

    if (nivelGas < 350) {

      Serial.println("ALERTA: Gas baixo - Velocidade minima");
      analogWrite(motorPin, 200);
      digitalWrite(buzzer, LOW);

      lcd.setCursor(4, 0);
      lcd.print("GAS BAIXO");
      lcd.setCursor(4, 1);
      lcd.print("VEL MIN");

    }

    else if (nivelGas >= limiteGas) {

      Serial.println("Gas alto - Velocidade maxima");
      analogWrite(motorPin, 0);
      digitalWrite(buzzer, LOW);

      lcd.setCursor(0, 0);
      lcd.print("T:");
      lcd.print(temperatura, 1);
      lcd.print("C V:MAX");
      lcd.setCursor(0, 1);
      lcd.print("Gas: ");
      lcd.print(nivelGas);

    }

    else {

      Serial.println("Operacao normal");
      analogWrite(motorPin, velocidadeMotor);
      digitalWrite(buzzer, LOW);

      lcd.setCursor(0, 0);
      lcd.print("T:");
      lcd.print(temperatura, 1);
      lcd.print("C V:");
      lcd.print(porcentagemVelocidade);
      lcd.print("%");
      lcd.setCursor(0, 1);
      lcd.print("Gas: ");
      lcd.print(nivelGas);

    }

  } else {

    Serial.println("Gerador desligado - Desligando motor");
    analogWrite(motorPin, 255); // Motor desligado para PNP
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(buzzer, LOW);

    lcd.setCursor(5, 0);
    lcd.print("Gerador");
    lcd.setCursor(4, 1);
    lcd.print("Desligado");

  }

  delay(1000);
  
}
