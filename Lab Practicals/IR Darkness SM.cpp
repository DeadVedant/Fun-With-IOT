//4. IR Sensor Darkness/Object Detection
#define IR_SENSOR 2
#define LED_PIN 13

void setup() {

  pinMode(IR_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("IR Sensor Ready");
}

void loop() {

  int sensorValue = digitalRead(IR_SENSOR);

  if (sensorValue == LOW) {

    digitalWrite(LED_PIN, HIGH);

    Serial.println("Darkness/Object Detected");

  } else {

    digitalWrite(LED_PIN, LOW);

    Serial.println("No Darkness/Object");
  }

  delay(1000);
}
/*Connections
IR Sensor	Arduino
VCC	5V
GND	GND
OUT	D2*/
