// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
#include <AFMotor.h>

// Constants
#define DHTTYPE DHT11  // DHT 11
#define DHTPIN 16      // Pin connected to DHT sensor
#define BUZZER_PIN 8   // Pin connected to the signal pin of the buzzer
#define SERVO_PIN 13   // Pin connected to the servo

// Global Variables
Servo myServo;
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// Function Declarations
void setupMotors();
void setupDHTSensor();
void setupBuzzer();
void setupServo();
void controlMotors();
void readDHTSensor();
void buzzBuzzer();
void controlServo();

void setup() {
  Serial.begin(9600);
  Serial.println("Bluetooth Control Started!");

  setupMotors();
  setupDHTSensor();
  setupBuzzer();
  setupServo();
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'k':  // Control Motors
        controlMotors();
        break;
      case 'b':  // Read DHT Sensor
        readDHTSensor();
        break;
      case 'x':  // Buzz Buzzer
        buzzBuzzer();
        break;
      case 'y':  // Control Servo
        controlServo();
        break;
      default:
        Serial.println("Invalid Command!");
        break;
    }
  }
}

void setupMotors() {
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void setupDHTSensor() {
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
}

void setupBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void setupServo() {
  myServo.attach(SERVO_PIN);
}

void controlMotors() {
  Serial.println("Controlling Motors...");
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  for (uint8_t i = 0; i < 255; i++) {
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }

  for (uint8_t i = 255; i != 0; i--) {
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }

  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  for (uint8_t i = 0; i < 255; i++) {
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }

  for (uint8_t i = 255; i != 0; i--) {
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }

  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}

void readDHTSensor() {
  Serial.println("Reading DHT Sensor...");
  sensors_event_t event;

  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  } else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }

  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}

void buzzBuzzer() {
  Serial.println("Buzzing Buzzer...");
  tone(BUZZER_PIN, 1000); // Play a 1000 Hz tone on the buzzer
  delay(1000);            // Wait for 1 second
  noTone(BUZZER_PIN);     // Stop the tone
  delay(1000);
}

void controlServo() {
  Serial.println("Controlling Servo...");
  myServo.write(180); // Move servo to 180 degrees
  delay(15);
  myServo.write(90);  // Move servo to 90 degrees
  delay(15);
}

