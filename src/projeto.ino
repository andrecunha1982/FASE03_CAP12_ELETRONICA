#include <DHTesp.h> // Incluindo a Biblioteca do ESP32 para Controlar o sensor de Temperatura e Humidade
#include <LiquidCrystal_I2C.h> // Incluindo Biblioteca para Incluir um LCD no Projeto
#include <WiFi.h>

#define I2C_ADDR    0x27 // Definindo o endereço para a tela de LCD
#define LCD_COLUMNS 20 // Quantidade de Colunas do LCD
#define LCD_LINES   4 // Quantidade de Linhas do LCD

const int DHT_PIN = 15; // Definindo pino do Sensor DHT22
int Trig_pin = 5; // Definindo pino de TRIG do Sensor HC-SR04
int Echo_pin = 18; // Definindo pino ECHO do Sensor HC-SR04
int IRSensor = 27; // Definindo pino Sensor PIR
int LDRSensor = 33; // Definindo pino Sensor LDR

long duration; // Definindo tipo para duração (variavel para calculo da distancia)
float Speed_of_sound =0.034; // Definindo tipo e valor da velocidade do som (variavel para calculo da distancia)
float dist_in_cm; // Definindo tipo da variavel final da distancia calculada 

DHTesp dhtSensor; // Definindo objeto para o Sensor DHT22

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES); // Configuração do LCD do Diagrama

void setup() { // Setup inicial da placa ativando sensores, wifi, entre outros

  Serial.begin(115200);
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Conectado! IP: " + WiFi.localIP());
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  lcd.init();
  lcd.backlight();
  pinMode(Trig_pin, OUTPUT);
  pinMode(Echo_pin,INPUT);
  pinMode(IRSensor, INPUT);
  pinMode(LDRSensor,INPUT);
}

void loop() { // Configuração do Loop de informações para monitorar constantemente o resultado dos sensores e jogar informações para o LCD do projeto
  // Valores do Sensor DHT22 de Temperatura e Humidade
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();

  // Valores do Sensor HC-SR04 de Distancia
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin,LOW);
  duration =pulseIn(Echo_pin,HIGH);
  dist_in_cm=duration*Speed_of_sound/2;

  // Valores do Sensor LDR de Luminosidade
  int a=analogRead(LDRSensor);

  //Valores do Sensor PIR para Detecção de Movimento e unificação de valores em um vetor
  int IR1 = digitalRead(IRSensor);
  if (IR1 == 0)
  {
    Serial.println("["+String(data.temperature,1)+","+String(data.humidity,1)+","+String(dist_in_cm)+","+String(a)+","+"1"+"]");
  }
  else
  {
    Serial.println("["+String(data.temperature,1)+","+String(data.humidity,1)+","+String(dist_in_cm)+","+String(a)+","+"0"+"]");
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


  delay(250);
}
