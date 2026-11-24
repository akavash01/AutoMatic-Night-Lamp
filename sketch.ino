 // Define the pin numbers for the LED and LDR (Light Dependent Resistor)
#define led 12
#define light A0

// Set the darkness threshold to determine when to turn on the LED
int darknessThreshold = 10;

void setup() {
  // Set the pin modes for the LED and LDR
  pinMode(light, INPUT);
  pinMode(led, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Print a message to the serial monitor
  Serial.println("Night Lamp");
}

void loop() {
  // Read the analog value from the LDR (Light Dependent Resistor)
  int LDR_status = analogRead(light);

  // Check if the LDR value is above the darkness threshold
  if (LDR_status > darknessThreshold) {
    // If it is bright, turn on the LED
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
  } else {
    // If it is dark, turn off the LED
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
  }

  // Delay for a short period to avoid rapid changes in LED state
  delay(1000);
}