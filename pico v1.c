#include "DHT.h"

#define DHTPIN 16             // Pin connected to the DHT sensor
#define DHTTYPE DHT11         // DHT sensor type
#define LED_PIN_TEMP 21       // Green LED for temperature
#define LED_PIN_HUM 22        // Red LED for humidity
#define BUTTON_PIN_TEMP 19    // Button for temperature
#define BUTTON_PIN_HUM 12     // Button for humidity
#define MEASURE_INTERVAL 3000 // Interval between measurements in milliseconds

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastMeasureTime = 0;
int lastTemp = 0; // Last measured temperature value
int lastHum = 0;  // Last measured humidity value

void setup()
{
  pinMode(LED_PIN_TEMP, OUTPUT);
  pinMode(LED_PIN_HUM, OUTPUT);
  pinMode(BUTTON_PIN_TEMP, INPUT_PULLUP);
  pinMode(BUTTON_PIN_HUM, INPUT_PULLUP);
  dht.begin();
  Serial.begin(9600);
  Serial.println("System Initialized");
}

void loop()
{
  unsigned long currentTime = millis();
  if (currentTime - lastMeasureTime >= MEASURE_INTERVAL)
  {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    // If reading errors occur due to the sensor being unreadable, we check for NAN
    if (isnan(temp) || isnan(hum))
    {
      Serial.println("Failed to read from DHT sensor!");
    }
    else
    {
      lastTemp = (int)round(temp);
      lastHum = (int)round(hum);

      lastMeasureTime = currentTime;

      // Print measured values to the console
      Serial.print("Temperature: ");
      Serial.print(lastTemp);
      Serial.print("°C, Humidity: ");
      Serial.print(lastHum);
      Serial.println("%");
    }
  }

  if (digitalRead(BUTTON_PIN_TEMP) == LOW)
  {
    blinkLed(LED_PIN_TEMP, lastTemp / 10); // Blink for temperature tens
    delay(500);                            // Pause between tens and ones
    blinkLed(LED_PIN_TEMP, lastTemp % 10); // Blink for temperature ones
  }

  if (digitalRead(BUTTON_PIN_HUM) == LOW)
  {
    blinkLed(LED_PIN_HUM, lastHum / 10); // Blink for humidity tens
    delay(500);                          // Pause between tens and ones
    blinkLed(LED_PIN_HUM, lastHum % 10); // Blink for humidity ones
  }
}

void blinkLed(int pin, int count)
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(pin, HIGH);
    delay(250); // Blink duration
    digitalWrite(pin, LOW);
    delay(250); // Pause between blinks
  }
  delay(500); // Additional pause after a series of blinks
}
