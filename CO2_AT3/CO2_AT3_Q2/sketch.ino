/*
---------------------------------------
GPIO Bit Manipulation Demo
Embedded C Assignment
---------------------------------------
Button  -> D2
LED1    -> D8
LED2    -> D9
LED3    -> D10
---------------------------------------
*/

#define BUTTON 2

void setup()
{
  DDRB |= (1 << PB0);   // D8 Output
  DDRB |= (1 << PB1);   // D9 Output
  DDRB |= (1 << PB2);   // D10 Output

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("GPIO Bit Manipulation Demo");
}

void loop()
{

  // LED1 ON
  PORTB |= (1 << PB0);

  delay(500);

  // LED2 ON
  PORTB |= (1 << PB1);

  delay(500);

  // LED3 ON
  PORTB |= (1 << PB2);

  delay(500);

  // Toggle LED1
  PORTB ^= (1 << PB0);

  delay(500);

  // Turn OFF LED2
  PORTB &= ~(1 << PB1);

  delay(500);

  // Button Check
  if (!(PIND & (1 << PD2)))
  {
    Serial.println("Button Pressed");

    // Toggle all LEDs
    PORTB ^= (1 << PB0);
    PORTB ^= (1 << PB1);
    PORTB ^= (1 << PB2);

    delay(300);
  }
}