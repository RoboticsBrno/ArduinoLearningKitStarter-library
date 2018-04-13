// Board tester firmare, remake by CornyjK.

#include <ALKS.h>
#include <DHT.h>

#define DHTTYPE  DHT11

DHT dht(DHT_PIN, DHTTYPE);

/*int freq = 2000;
  int channel = 0;
  int resolution = 8;*/

unsigned long t_inc = 0;
unsigned long t_meas = 0;
uint8_t cnt = 0;

void setup() {
  setupAll();
  Serial.begin(DEFAULT_SERIAL_SPEED);
  dht.begin();
  /*ledcSetup(channel, freq, resolution);
    ledcAttachPin(19, channel);*/
  Serial.print("Arduino learning kit starter hardware test firmware\n");
}

void loop() {
  if ((millis() - t_inc) >= 500)
  {
    t_inc = millis();
    ++cnt;
    digitalWrite(L_R, cnt & 1 ? HIGH : LOW);
    digitalWrite(L_Y, cnt & 2 ? HIGH : LOW);
    digitalWrite(L_G, cnt & 4 ? HIGH : LOW);
    digitalWrite(L_B, cnt & 8 ? HIGH : LOW);
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
  digitalWrite(L_RGB_B, digitalRead(SW1)  == HIGH ? LOW : HIGH);

  /*if (digitalRead(SW1) == LOW && digitalRead(SW2) == LOW)
    {
    digitalWrite(18, LOW);
    Serial.write('PIEZO TEST! Alpha release, removed');
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
