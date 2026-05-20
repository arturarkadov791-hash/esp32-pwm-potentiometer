# ESP32 PWM Potentiometer

Project for controlling LED brightness using a potentiometer on ESP32.

## Hardware
- ESP32
- Potentiometer (GPIO34)
- LED (GPIO5)

## Principle
Analog input → mapping → PWM output

## Code flow
analogRead → map(0–4095 → 0–255) → ledcWrite
