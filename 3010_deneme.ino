const int redDS = 11;
const int greenDS = 12;
const int blueDS = 13;
const int clockPin = 9;
const int latchPin = 8;

const int numRegisterGroups = 8;
const int registersPerGroup = 3;
const int ledsPerGroup = 8;
const int totalLeds = numRegisterGroups * ledsPerGroup;

byte ledValues[totalLeds][3];

int colorIndex = 0;
int selectedMode = 0;

void setup() {
  pinMode(redDS, OUTPUT);
  pinMode(greenDS, OUTPUT);
  pinMode(blueDS, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  for (int i = 0; i < totalLeds; i++) {
    ledValues[i][0] = 255; // Set initial red value to 255
    ledValues[i][1] = 255; // Set initial green value to 255
    ledValues[i][2] = 255; // Set initial blue value to 255
  }

  Serial.begin(9600);
  Serial.println("Select a mode:");
  Serial.println("0 - All white LEDs");
  Serial.println("1 - Random rainbow colors");
  Serial.println("2 - All black LEDs");
  Serial.println("3 - All blue LEDs");
}

void loop() {
  if (Serial.available() > 0) {
    selectedMode = Serial.parseInt();
  }

  switch (selectedMode) {
    case 0:
      allWhite();
      break;
    case 1:
      randomRainbow();
      break;
    case 2:
      allBlack();
      break;
    case 3:
      allBlue();
      break;
    default:
      break;
  }

  updateLEDs();

  delay(1000);
}

void shiftOutGroup(int groupIndex, byte redValue, byte greenValue, byte blueValue) {
  for (int i = 0; i < registersPerGroup; i++) {
    for (int j = 0; j < ledsPerGroup; j++) {
      int ledIndex = (groupIndex * ledsPerGroup) + j;

      shiftOut(redDS, clockPin, MSBFIRST, redValue);
      shiftOut(greenDS, clockPin, MSBFIRST, greenValue);
      shiftOut(blueDS, clockPin, MSBFIRST, blueValue);
    }
  }
}

void allWhite() {
  for (int i = 0; i < totalLeds; i++) {
    ledValues[i][0] = 255; // Set red value to 255
    ledValues[i][1] = 255; // Set green value to 255
    ledValues[i][2] = 255; // Set blue value to 255
  }
}

void randomRainbow() {
  const byte rainbowColors[][3] = {
    {255, 0, 0},
    {255, 165, 0},
    {255, 255, 0},
    {0, 255, 0},
    {0, 0, 255},
    {75, 0, 130},
    {238, 130, 238}
  };

  const int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

  for (int i = 0; i < totalLeds; i++) {
    byte* color = rainbowColors[random(0, numColors)];
    ledValues[i][0] = color[0]; // Set red value
    ledValues[i][1] = color[1]; // Set green value
    ledValues[i][2] = color[2]; // Set blue value
  }
}

void allBlack() {
  for (int i = 0; i < totalLeds; i++) {
    ledValues[i][0] = 0; // Set red value to 0
    ledValues[i][1] = 0; // Set green value to 0
    ledValues[i][2] = 0; // Set blue value to 0
  }
}

void allBlue() {
  for (int i = 0; i < totalLeds; i++) {
    ledValues[i][0] = 0; // Set red value to 0
    ledValues[i][1] = 0; // Set green value to 0
    ledValues[i][2] = 255; // Set blue value to 255
  }
}

void updateLEDs() {
  digitalWrite(latchPin, LOW);

  for (int groupIndex = 0; groupIndex < numRegisterGroups; groupIndex++) {
    byte redValue = ledValues[groupIndex * ledsPerGroup][0];
    byte greenValue = ledValues[groupIndex * ledsPerGroup][1];
    byte blueValue = ledValues[groupIndex * ledsPerGroup][2];

    shiftOutGroup(groupIndex, redValue, greenValue, blueValue);
  }

  digitalWrite(latchPin, HIGH);
}
