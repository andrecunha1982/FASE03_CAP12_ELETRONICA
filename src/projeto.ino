#include "DHTesp.h" // Incluindo a Biblioteca do ESP32 para Controlar o sensor de Temperatura e Humidade
#include <LiquidCrystal_I2C.h> // Incluindo Biblioteca para Incluir um LCD no Projeto
#define I2C_ADDR    0x27 // Definindo o endereço para a tela de LCD
#define LCD_COLUMNS 20 // Quantidade de Colunas do LCD
#define LCD_LINES   4 // Quantidade de Linhas do LCD

const int DHT_PIN = 15; // Definindo pino do Sensor DHT22
int Trig_pin = 5; // Definindo pino de TRIG do Sensor HC-SR04
int Echo_pin = 18; // Definindo pino ECHO do Sensor HC-SR04
int IRSensor = 27; // Definindo pino Sensor PIR
int LDRSensor = 33; // Definindo pino Sensor LDR

long duration;
float Speed_of_sound =0.034;
float dist_in_cm;

DHTesp dhtSensor; // Definindo objeto para o Sensor DHT22

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {

  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  lcd.init();
  lcd.backlight();
  pinMode(Trig_pin, OUTPUT);
  pinMode(Echo_pin,INPUT);
  Serial.println("Serial Working:");
  pinMode(IRSensor, INPUT);
  Serial.println("LDR readings...");
  pinMode(LDRSensor,INPUT);
}

void loop() {
  //Sensor DHT22 de Temperatura e Humidade
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  Serial.println("Temperatura: " + String(data.temperature, 1) + "°C" + " | " + "Humidade: " + String(data.humidity, 1) + "%");

  // Sensor HC-SR04 de Distancia
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin,LOW);
  duration =pulseIn(Echo_pin,HIGH);
  dist_in_cm=duration*Speed_of_sound/2;
  Serial.print("Distancia em cm: " + String(dist_in_cm));

  //Sensor LDR de Luminosidade
  int a=analogRead(LDRSensor);
  Serial.println("\nLuminosidade: " + String(a) + " LUX");

  //Sensor PIR para Detecção de Movimento
  int IR1 = digitalRead(IRSensor);
  if (IR1 == 0)
  {
    Serial.println("Movimento Detectado!");
  }
  else
  {
    Serial.println("Movimento Encerrado!");
  }
  Serial.println("---");

  // Configuração do display do LCD
  lcd.setCursor(0, 0);
  lcd.print("T: " + String(data.temperature, 1) + "\xDF"+"C" + " | " + "H: " + String(data.humidity, 1) + "%");
  lcd.setCursor(0, 1);
  lcd.print("Distancia: " + String(dist_in_cm, 1) + "cm ");
  lcd.setCursor(0, 2);
  lcd.print("LX: " + String(a) + " LUX");
  if (IR1 == 0)
  {
    lcd.setCursor(0, 3);
    lcd.print("Movimento Detectado!");
  }
  else
  {
    lcd.setCursor(0, 3);
    lcd.print("Movimento Encerrado!");
  }


  delay(500);
}
