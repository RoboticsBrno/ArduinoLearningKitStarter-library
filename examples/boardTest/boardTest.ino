// Board tester firmare, redux by CornyjK.

#include <ALKS.h>

// You must install the DHT library to your Arduino developer tools
// In Arduino IDE - open in Menu "Project" -> "Add library" -> "Library manager" ->
// -> write "DHT" to searching field
// -> and install the DHT library "DHT sensor library by Adafruit..."
// (switch the version from the latest to 1.2.3)
// https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>

// Serial monitor speed (baud rate)
// You must set this baud rate in right corner in the serial monitor (in Arduino IDE)
#define SERIAL_BAUDRATE 57600
#define DHTTYPE  DHT11

DHT dht(DHT_PIN, DHTTYPE);

int freq = 2000;
int channel = 0;
int resolution = 8;

void setup() {
  // RGB led
  pinMode(L_RGB_R, OUTPUT);
  pinMode(L_RGB_G, OUTPUT);
  pinMode(L_RGB_B, OUTPUT);
  pinMode(L_R, OUTPUT);
  pinMode(L_Y, OUTPUT);
  pinMode(L_G, OUTPUT);
  pinMode(L_B, OUTPUT);
  pinMode(PIEZO1, OUTPUT);
  pinMode(PIEZO2, OUTPUT);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  Serial.begin(SERIAL_BAUDRATE);
  dht.begin();
/*  ledcSetup(channel, freq, resolution);
  ledcAttachPin(19, channel);*/
  digitalWrite(18, LOW);
  Serial.print("Arduino learning kit starter hardware test firmware\n");
}

unsigned long t_inc = 0;
unsigned long t_meas = 0;
uint8_t cnt = 0;
bool beeping = false;

void loop() {
  //  digitalWrite(L_RGB_R, HIGH);
  //  delay(500);
  //  digitalWrite(L_RGB_R, LOW);
  //  digitalWrite(L_RGB_G, HIGH);
  //  delay(500);
  //  digitalWrite(L_RGB_G, LOW);
  //  digitalWrite(L_RGB_B, HIGH);
  //  delay(500);
  //  digitalWrite(L_RGB_B, LOW);
  //  delay(500);
  if ((millis() - t_inc) >= 500)
  {
    t_inc = millis();
    ++cnt;
    digitalWrite(L_R , cnt & 1 ? HIGH : LOW);
    digitalWrite(L_Y , cnt & 2 ? HIGH : LOW);
    digitalWrite(L_G , cnt & 4 ? HIGH : LOW);
    digitalWrite(L_B , cnt & 8 ? HIGH : LOW);
  }

  if ((millis() - t_meas) >= 500)
  {
    t_meas = millis();
    float t = dht.readTemperature();
    if (isnan(t))
    {
      Serial.println("TEMPERATURE ERROR");
    }
    else
    {
      Serial.print("Temperature: ");
      Serial.print(int(t));
    }
    Serial.print("\tlight: ");
    Serial.print(analogRead(PHOTO));
    Serial.print("\tleft pot: ");
    Serial.print(analogRead(POT1));
    Serial.print("\tright pot: ");
    Serial.print(analogRead(POT2));
    Serial.print("\n");
  }

  digitalWrite(L_RGB_R, digitalRead(SW3)   == HIGH ? LOW : HIGH);
  digitalWrite(L_RGB_G, digitalRead(SW2) == HIGH ? LOW : HIGH);
  //digitalWrite(L_RGB_G, !beeping ? LOW : HIGH);
  digitalWrite(L_RGB_B, digitalRead(SW1)  == HIGH ? LOW : HIGH);

  /*if (digitalRead(SW1) == LOW && digitalRead(SW2) == LOW)
  {
    Serial.write('PIEZO TEST! Beta version, use at your own risk :P');
    cnt = 0;
    digitalWrite(L_R , LOW);
    digitalWrite(L_Y , LOW);
    digitalWrite(L_G , LOW);
    digitalWrite(L_B , LOW);
    digitalWrite(L_RGB_R, LOW);
    digitalWrite(L_RGB_G, LOW);
    digitalWrite(L_RGB_B, LOW);
    ledcWriteTone(channel, 2000);

    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle = dutyCycle + 10) {

      Serial.println(dutyCycle);

      ledcWrite(channel, dutyCycle);
      delay(1000);
    }

    ledcWrite(channel, 125);

    for (int freq = 255; freq < 10000; freq = freq + 250) {

      Serial.println(freq);

      ledcWriteTone(channel, freq);
      delay(1000);
    }
  }
  ledcWriteTone(channel, 0);*/
  if (Serial.available())
  {
    char c = Serial.read();
    switch (c)
    {
      case '\r':
        Serial.write('\n');
        break;
      default:
        Serial.write(c + 1);
        Serial.write('\n');
        break;
    }
  }




}
