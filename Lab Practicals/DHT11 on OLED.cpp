/*Experiment No. 3
Title: Program an Arduino to Read Data from a Temperature Sensor and Display the Output on OLED Display + Serial Monitor

Objective:
Interface a DHT11 temperature sensor with Arduino and display
temperature readings on an OLED (AMOLED-like) display and Serial Monitor.

Materials Required:
- Arduino Uno
- DHT11 Temperature Sensor
- OLED Display (SSD1306 128x64 I2C)
- Jumper Wires
- Breadboard
- Arduino IDE
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED reset pin
#define OLED_RESET -1

// Initialize OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT11 setup
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

    Serial.begin(9600);

    // Start DHT sensor
    dht.begin();

    // Initialize OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED not found!");
        while (true);
    }

    // Clear screen
    display.clearDisplay();

    // Text settings
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Startup message
    display.setCursor(10, 20);
    display.println("DHT11 Initialized");
    display.display();

    Serial.println("DHT11 Sensor Initialized");

    delay(2000);
}

void loop() {

    float temp = dht.readTemperature();

    // Check if reading failed
    if (isnan(temp)) {
        Serial.println("Failed to read from DHT sensor!");

        display.clearDisplay();
        display.setCursor(0, 20);
        display.println("Sensor Error!");
        display.display();

        delay(2000);
        return;
    }

    // Serial Monitor Output
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");

    // OLED Display Output
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(10, 10);
    display.println("TEMP");

    display.setTextSize(3);
    display.setCursor(15, 35);
    display.print(temp);
    display.print("C");

    display.display();

    delay(2000);
}

/*Circuit Connections

DHT11 Connections:
DHT11 Pin    Arduino Uno
VCC          5V
GND          GND
DATA         D2

OLED SSD1306 I2C Connections:
OLED Pin     Arduino Uno
VCC          5V
GND          GND
SCL          A5
SDA          A4
*/
