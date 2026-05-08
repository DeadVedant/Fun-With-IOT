/*Experiment No. 2
Title: Write a Program using Arduino to Control LED or Blinking
Objective

To understand how to control an LED by turning it ON and OFF using Arduino programming and to learn about digital output pins.

Materials Required
- Arduino Uno Board
- LED (Light Emitting Diode)
- Connecting Wires
- USB Cable*/

void setup() {

    pinMode(13, OUTPUT);
}

void loop() {

    digitalWrite(13, HIGH);

    delay(1000);

    digitalWrite(13, LOW);

    delay(1000);
}

/*Circuit Connection
Component	   Arduino Connection
LED Anode	   Pin 13
LED Cathode	 GND*/
