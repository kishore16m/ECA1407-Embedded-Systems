#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int heartPin = A0;
const int tempPin = A1;
const int buttonPin = 2;

int steps = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  int heart = map(analogRead(heartPin), 0, 1023, 60, 120);
  float temp = map(analogRead(tempPin), 0, 1023, 350, 400) / 10.0;
  float calories = steps * 0.04;

  bool currentButton = digitalRead(buttonPin);

  if (lastButton == HIGH && currentButton == LOW) {
    steps++;
    delay(200);
  }

  lastButton = currentButton;

  display.clearDisplay();

  display.setCursor(0,0);
  display.print("Heart:");
  display.print(heart);
  display.println(" BPM");

  display.print("Temp:");
  display.print(temp);
  display.println(" C");

  display.print("Steps:");
  display.println(steps);

  display.print("Cal:");
  display.print(calories);
  display.println(" kcal");

  display.display();

  delay(200);
}