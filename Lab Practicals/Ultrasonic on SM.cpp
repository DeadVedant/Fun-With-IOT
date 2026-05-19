//3. Ultrasonic Sensor Distance Measurement
#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
float distance;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  Serial.println("Ultrasonic Sensor Ready");
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}
/*Connections
HC-SR04	Arduino
VCC	5V
GND	GND
TRIG	D9
ECHO	D10*/
