/*
   Project name: ESP32 Rotary Encoder
   Modified Date: 25-06-2024
   Code by: Projectslearner
   Website: https://projectslearner.com/learn/esp32-rotary-encoder
*/

// Define the pins connected to the rotary encoder
#define CLK_PIN 23   // GPIO 23 for CLK (Clock) pin
#define DT_PIN 22    // GPIO 22 for DT (Data) pin
#define SW_PIN 21    // GPIO 21 for SW (Switch) pin

// Variables to store encoder state
volatile int encoderPos = 0;
volatile int lastEncoderPos = 0;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(CLK_PIN, INPUT_PULLUP);  // CLK pin as input with internal pullup resistor
  pinMode(DT_PIN, INPUT_PULLUP);   // DT pin as input with internal pullup resistor
  pinMode(SW_PIN, INPUT_PULLUP);   // SW pin as input with internal pullup resistor

  // Attach interrupts for CLK pin
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), handleEncoder, CHANGE);
}

void loop() {
  // Read the current position of the encoder
  if (encoderPos != lastEncoderPos) {
    Serial.print("Encoder Position: ");
    Serial.println(encoderPos);
    lastEncoderPos = encoderPos;
  }

  // Check the state of the switch (optional)
  int switchState = digitalRead(SW_PIN);
  if (switchState == LOW) {
    Serial.println("Button pressed!");
    delay(500); // Debounce delay
  }
}

// Interrupt service routine for the encoder
void handleEncoder() {
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  
  // Ignore bounces and wait for debounce timeout
  if (interruptTime - lastInterruptTime > 5) {
    // Read the DT pin to determine direction
    int DT_state = digitalRead(DT_PIN);
    if (DT_state == HIGH) {
      encoderPos++;
    } else {
      encoderPos--;
    }
    lastInterruptTime = interruptTime;
  }
}
