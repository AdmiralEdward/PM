#include <Servo.h>
Servo servo;

#define BUTTON_UP 2

#define BUTTON_RIGHT 3

#define BUTTON_DOWN  4

#define BUTTON_LEFT 5

#define BUTTON_E 6

#define BUTTON_F  7

#define BUTTON_K 8

#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y  1

#define DELAY 500

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 9     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {

  servo.attach(10);  // attaches the servo on pin 9 to the servo object

  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;



 // to enable pull up resistors first write pin  mode

 // and then make that pin HIGH

 pinMode(BUTTON_UP, INPUT);

  digitalWrite(BUTTON_UP, HIGH);



 pinMode(BUTTON_RIGHT, INPUT);

  digitalWrite(BUTTON_RIGHT, HIGH);



 pinMode(BUTTON_DOWN, INPUT);

  digitalWrite(BUTTON_DOWN, HIGH);



 pinMode(BUTTON_LEFT, INPUT);

  digitalWrite(BUTTON_LEFT, HIGH);



 pinMode(BUTTON_E, INPUT);

  digitalWrite(BUTTON_E, HIGH);



 pinMode(BUTTON_F, INPUT);

  digitalWrite(BUTTON_F, HIGH);


  pinMode(BUTTON_K, INPUT);

 digitalWrite(BUTTON_K,  HIGH);

}



void loop() {

 if(digitalRead(BUTTON_UP) ==  LOW) {

    Serial.println("Button Y is pressed");
   
   delay(DELAY);

  servo.write(180);          
  }

 else if(digitalRead(BUTTON_RIGHT) == LOW) {
  servo.write(90);

   Serial.println("Button B is pressed");

   delay(DELAY);

 }

 else if(digitalRead(BUTTON_DOWN)  == LOW) {
  servo.write(90);

   Serial.println("Button A is pressed");

   delay(DELAY);

      // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }

  }

 else if(digitalRead(BUTTON_LEFT) == LOW) {
  servo.write(90);

   Serial.println("Button X is pressed");

   delay(DELAY);

  }

 else if(digitalRead(BUTTON_E) == LOW) {
  servo.write(90);

   Serial.println("Button  E is pressed");

   delay(DELAY);

 }

 else if(digitalRead(BUTTON_F)  == LOW) {
  servo.write(90);

   Serial.println("Button F is pressed");

    Serial.print("x:  ");

 Serial.println(512 - analogRead(PIN_ANALOG_X));

 // Print y axis values

  Serial.print("y: ");

 Serial.println(-506 + analogRead(PIN_ANALOG_Y));



  // Some delay to clearly observe your values on serial monitor.

 delay(500);


   delay(DELAY);

 }

 if(digitalRead(BUTTON_K) == LOW) {

    Serial.println("Button  k  is pressed");


   delay(DELAY);

 }
}