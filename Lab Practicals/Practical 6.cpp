/*Experiment No. 6
Title: Connect a Microcontroller to an IoT Cloud Platform and Send Sensor Data to the Cloud
Objective

To connect an ESP32 microcontroller with an LM35 temperature sensor and send real-time temperature data to the ThingSpeak IoT cloud platform.

Materials Required
- ESP32 Development Board
- LM35 Temperature Sensor
- Jumper Wires
- Breadboard
- Micro-USB Cable
- Computer with Arduino IDE
- WiFi Network*/

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

String apiKey = "YOUR_THINGSPEAK_API_KEY";

const char* server = "http://api.thingspeak.com/update";

int lm35Pin = 34;

void setup() {

    Serial.begin(115200);

    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi");

    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected");
}

void loop() {

    int sensorValue = analogRead(lm35Pin);

    float voltage = sensorValue * (3.3 / 4095.0);

    float temperature = voltage * 100;

    Serial.print("Temperature: ");
    Serial.println(temperature);

    if(WiFi.status() == WL_CONNECTED) {

        HTTPClient http;

        String url = server;
        url += "?api_key=" + apiKey;
        url += "&field1=" + String(temperature);

        http.begin(url);

        int httpResponseCode = http.GET();

        Serial.print("HTTP Response Code: ");
        Serial.println(httpResponseCode);

        http.end();
    }

    delay(15000);
}

/*Circuit Connections
Connections Between LM35 and ESP32
LM35 Pin	 ESP32 Connection
VCC	       3.3V
GND	       GND
OUT	       GPIO 34*/
