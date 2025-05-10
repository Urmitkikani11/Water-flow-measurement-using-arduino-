#include <LiquidCrystal.h>

volatile int flow_frequency; // Measures flow sensor pulses
// Calculated litres/hour
float vol = 0.0, l_minute;
unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;

LiquidCrystal lcd(12, 11, 5, 4, 3, 9);

void flow() { // Interrupt function
  flow_frequency++;
}

void setup() {
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Flow Meter");
  lcd.setCursor(0, 1);
  lcd.print("MCI PROJECT :)");
  currentTime = millis();
  cloopTime = currentTime;
}

void loop() {
  currentTime = millis();
  // Every second, calculate and print litres/hour
  if (currentTime >= (cloopTime + 1000)) {
    cloopTime = currentTime; // Updates cloopTime

    if (flow_frequency != 0) {
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in l/hour

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Rate: ");
      lcd.print(l_minute);
      lcd.print(" L/m");

      l_minute = l_minute * 60;
      vol += (l_minute / 60);

      lcd.setCursor(0, 1);
      lcd.print("Vol: ");
      lcd.print(vol);
      lcd.print(" L");

      flow_frequency = 0; // Reset Counter
      Serial.print(l_minute, DEC); // Print litres/hour
      Serial.println(" L/sec");
    } else {
      Serial.println("Water flow rate = 0 ");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Rate: ");
      lcd.print(flow_frequency);
      lcd.print(" L/m");

      lcd.setCursor(0, 1);
      lcd.print("Vol: ");
      lcd.print(vol);
      lcd.print(" L");
    }
  }
}
