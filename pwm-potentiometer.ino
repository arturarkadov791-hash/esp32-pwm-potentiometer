const int potPin = 34;     // ADC pin connected to potentiometer
const int led = 5;         // PWM output pin connected to LED

int dutyCycle = 0;         // PWM duty cycle (0–255)
int potValue = 0;          // Raw analog value from potentiometer

const int freq = 1000;     // PWM frequency in Hz
const int resolution = 8;   // PWM resolution (8-bit = 0–255)

void setup() {
  Serial.begin(115200);    // Initialize serial communication for debugging

  pinMode(led, OUTPUT);    // Set LED pin as output

  // Attach PWM channel to LED pin with defined frequency and resolution
  ledcAttach(led, freq, resolution);
}

void loop() {
  // Read raw ADC value from potentiometer (0–4095 on ESP32)
  potValue = analogRead(potPin);

  // Map ADC range (0–4095) to PWM range (0–255)
  dutyCycle = map(potValue, 0, 4095, 0, 255);

  // Write PWM signal to LED pin
  ledcWrite(led, dutyCycle);

  // Print raw potentiometer value for debugging
  Serial.println(potValue);

  delay(15); // Small delay to stabilize readings
}