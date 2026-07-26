/*
----------------------------------------------------
Industrial Water Tank Controller using FSM
Embedded C Assignment
----------------------------------------------------
Inputs:
D2 -> Start Button
D3 -> Water Level Sensor

Outputs:
D8 -> Pump (Green LED)
D9 -> Alarm (Red LED)
----------------------------------------------------
*/

const int START_BUTTON = 2;
const int LEVEL_SENSOR = 3;

const int PUMP = 8;
const int ALARM = 9;

// FSM States
enum State {
  IDLE,
  FILLING,
  FULL,
  DRAINING
};

State currentState = IDLE;

unsigned long stateTimer = 0;

void setup() {

  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(LEVEL_SENSOR, INPUT_PULLUP);

  pinMode(PUMP, OUTPUT);
  pinMode(ALARM, OUTPUT);

  digitalWrite(PUMP, LOW);
  digitalWrite(ALARM, LOW);

  Serial.begin(9600);

  Serial.println("Industrial Water Tank Controller");
  Serial.println("--------------------------------");
}

void loop() {

  switch (currentState) {

    //-------------------------------------------------
    case IDLE:

      digitalWrite(PUMP, LOW);
      digitalWrite(ALARM, LOW);

      Serial.println("STATE : IDLE");

      if (digitalRead(START_BUTTON) == LOW) {

        Serial.println("Start Button Pressed");
        currentState = FILLING;

        delay(300);
      }

      break;

    //-------------------------------------------------
    case FILLING:

      Serial.println("STATE : FILLING");

      digitalWrite(PUMP, HIGH);

      if (digitalRead(LEVEL_SENSOR) == LOW) {

        digitalWrite(PUMP, LOW);

        currentState = FULL;

        stateTimer = millis();

        delay(300);
      }

      break;

    //-------------------------------------------------
    case FULL:

      Serial.println("STATE : FULL");

      digitalWrite(PUMP, LOW);
      digitalWrite(ALARM, HIGH);

      if (millis() - stateTimer >= 3000) {

        digitalWrite(ALARM, LOW);

        currentState = DRAINING;

        stateTimer = millis();
      }

      break;

    //-------------------------------------------------
    case DRAINING:

      Serial.println("STATE : DRAINING");

      digitalWrite(PUMP, LOW);

      if (millis() - stateTimer >= 3000) {

        Serial.println("Tank Empty");

        currentState = IDLE;
      }

      break;
  }

  delay(200);
}