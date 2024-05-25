#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5
#define BUTTON_E 6
#define BUTTON_F 7
#define BUTTON_K 8
#define PIN_ANALOG_X 0
#define PIN_ANALOG_Y 1

#define DELAY_TIME 500

void setup() {
  Serial.begin(9600);

  // Enable pull-up resistors
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
  digitalWrite(BUTTON_K, HIGH);
}

void loop() {
  if (digitalRead(BUTTON_UP) == LOW) {
    Serial.println("Button Y is pressed");
    Serial.println('y');
    delay(DELAY_TIME);
  }
  else if (digitalRead(BUTTON_RIGHT) == LOW) {
    Serial.println("Button B is pressed");
    Serial.println('b');
    delay(DELAY_TIME);

    // Wait to receive the temperature data from another source
    if (Serial.available() > 0) {
      String temperature = Serial.readStringUntil('\n');
      Serial.print("Received Temperature: ");
      Serial.println(temperature);
    }
  }
  else if (digitalRead(BUTTON_DOWN) == LOW) {
    Serial.println("Button A is pressed");
    Serial.println('a');
    delay(DELAY_TIME);
  }
  else if (digitalRead(BUTTON_LEFT) == LOW) {
    Serial.println("Button X is pressed");
    Serial.println('x');
    delay(DELAY_TIME);
  }
  else if (digitalRead(BUTTON_E) == LOW) {
    Serial.println("Button E is pressed");
    Serial.println('e');
    delay(DELAY_TIME);
  }
  else if (digitalRead(BUTTON_F) == LOW) {
    Serial.println("Button F is pressed");
    Serial.println('f');
    Serial.print("x: ");
    Serial.println(523 - analogRead(PIN_ANALOG_X));
    Serial.print("y: ");
    Serial.println(-506 + analogRead(PIN_ANALOG_Y));
    delay(500);
    delay(DELAY_TIME);
  }
  else if (digitalRead(BUTTON_K) == LOW) {
    Serial.println("Button K is pressed");
    Serial.println('k');
    delay(DELAY_TIME);
  }
}
