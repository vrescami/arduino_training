#define TRIG 2             // ultrasonic sensor, trigger pin
#define ECHO 3             // ultrasonic sensor, trigger echo
#define RED_LED 4
#define BUZZER 5
#define DATA 6             // shift register 74HC595, data pin
#define LATCH 7            // shift register 74HC595, latch pin
#define CLK 8              // shift register 74HC595, clock pin
#define GREEN_LEED 13
#define CALIBRATION_PIN A0 // potentiometer
#define SOUND_SPEED 0.034

// 4-digit 7 segments display
const int digitsDistance[] = {9, 10}; // two digits for distance (0 - 99)
const int digitsLimit[] = {11, 12};   // two digits for limit (0 - 99)

// I used a common anode display, so it lights with 0
#define DIGIT_TABLE_SIZE 10
const byte digitTable[] = {
  0b11000000,  // 0
  0b11111001,  // 1
  0b10100100,  // 2
  0b10110000,  // ...
  0b10011001,
  0b10010010,
  0b10000010,
  0b11111000,
  0b10000000,
  0b10010000,
};


void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LEED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(CALIBRATION_PIN, INPUT);
  digitalWrite(TRIG, LOW);

  for (int i = 0; i < 2; i++) {
    pinMode(digitsLimit[i], OUTPUT);
    digitalWrite(digitsLimit[i], LOW);
    pinMode(digitsDistance[i], OUTPUT);
    digitalWrite(digitsDistance[i], LOW);
  }

  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(DATA, LOW);
  digitalWrite(LATCH, LOW);
  digitalWrite(CLK, LOW);
}


void displayDigit(int n) {
  for (int i = 0; i < DIGIT_TABLE_SIZE; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, digitTable[n]);
    digitalWrite(LATCH, HIGH);
  }
}


void displayValue(int digits[], int d) {
  int res = d;
  for (int i = 1; i >= 0; i--) {
    int num = res / int(pow(10, i));
    res = res % int(pow(10, i));
    if (num > 0 || i == 0) {
      digitalWrite(digits[i], HIGH);
      displayDigit(num);
      delay(3); // wait a little time for sharper digits
      digitalWrite(digits[i], LOW);
    }
  }
}


// non-blocking delay implementation
void updateLEDsWithDelay(int delay_ms) {
  static unsigned long previousMillis = 0;
  static int ledState = LOW;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= delay_ms) {
    previousMillis = currentMillis;
    ledState = ledState == HIGH ? LOW : HIGH;
    digitalWrite(RED_LED, ledState);
    digitalWrite(GREEN_LEED, LOW);
  }
}


void loop()
{
  static int numberToDisplay = 0;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  /*
   * distance = speed * time
   *  - actual distance is 2*distance, since the signal bounces on the subject
   *  - speed of sound (ultrasonic sensor) is 340 m/s -> 0.034 cm/us
   *  - distance = (0.034*time)/2
   */
  long distance = (SOUND_SPEED * pulseIn(ECHO, HIGH))/2.0;
  int limit = map(analogRead(CALIBRATION_PIN), 0, 1023, 0, 99);

  numberToDisplay = distance;
  if (distance < limit / 4) {
    updateLEDsWithDelay(10);
  } else if (distance < limit / 2) {
    updateLEDsWithDelay(50);
  } else if (distance < 3*limit / 4) {
    updateLEDsWithDelay(100);
  } else if (distance <= limit) {
    updateLEDsWithDelay(250);
  } else if (distance > limit) {
    numberToDisplay = 0;
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LEED, HIGH);
  }

  displayValue(digitsDistance, numberToDisplay);
  displayValue(digitsLimit, limit);
}
