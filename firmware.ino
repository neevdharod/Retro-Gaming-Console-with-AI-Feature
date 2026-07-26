

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OLED_SDA 0
#define OLED_SCL 1

#define BTN_UP 5
#define BTN_DOWN 6
#define BTN_LEFT 13
#define BTN_RIGHT 16

#define BTN_A 12
#define BTN_B 21
#define BTN_X 22
#define BTN_Y 23

#define BTN_START 24
#define BTN_SELECT 25
#define BTN_AI 26
#define BTN_MENU 27

#define BUZZER_PIN 15

struct Button {
  const char* name;
  int pin;
  int lastState;
};

Button buttons[] = {
  {"UP", BTN_UP, HIGH},
  {"DOWN", BTN_DOWN, HIGH},
  {"LEFT", BTN_LEFT, HIGH},
  {"RIGHT", BTN_RIGHT, HIGH},
  {"A", BTN_A, HIGH},
  {"B", BTN_B, HIGH},
  {"X", BTN_X, HIGH},
  {"Y", BTN_Y, HIGH},
  {"START", BTN_START, HIGH},
  {"SELECT", BTN_SELECT, HIGH},
  {"AI", BTN_AI, HIGH},
  {"MENU", BTN_MENU, HIGH}
};

const int buttonCount = sizeof(buttons) / sizeof(buttons[0]);

bool aiRecording = false;
unsigned long aiStartTime = 0;

void beep(int freq, int durationMs) {
  tone(BUZZER_PIN, freq);
  delay(durationMs);
  noTone(BUZZER_PIN);
}

void drawHome() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(32, 0);
  display.println("RETRO AI");

  display.setCursor(36, 12);
  display.println("CONSOLE");

  display.setCursor(0, 30);
  display.println("> Play Games");

  display.setCursor(0, 42);
  display.println("  AI Create");

  display.setCursor(0, 56);
  display.println("Hold AI to talk");

  display.display();
}

void drawButton(const char* name) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(18, 0);
  display.println("BUTTON TEST");

  display.setCursor(0, 24);
  display.println("Pressed:");

  display.setCursor(0, 38);
  display.println(name);

  display.display();
}

void drawAIListening() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(36, 0);
  display.println("AI MODE");

  display.setCursor(18, 24);
  display.println("Listening...");

  display.setCursor(12, 40);
  display.println("Speak prompt");

  display.display();
}

void drawAIDone(float seconds) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(28, 0);
  display.println("AI PROMPT");

  display.setCursor(0, 24);
  display.println("Recorded:");

  display.setCursor(0, 38);
  display.print(seconds, 1);
  display.println(" sec");

  display.setCursor(0, 54);
  display.println("Sending to AI");

  display.display();
}

void drawMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(46, 0);
  display.println("MENU");

  display.setCursor(0, 20);
  display.println("1 Save Game");

  display.setCursor(0, 34);
  display.println("2 Settings");

  display.setCursor(0, 48);
  display.println("3 Exit");

  display.display();
}

void setup() {
  Serial.begin(115200);

  Wire.setSDA(OLED_SDA);
  Wire.setSCL(OLED_SCL);
  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true) {
      delay(100);
    }
  }

  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }

  pinMode(BUZZER_PIN, OUTPUT);

  drawHome();

  Serial.println("Retro AI Console Wokwi firmware started");
  Serial.println("Press buttons in Wokwi.");
  Serial.println("Hold AI button to simulate voice recording.");
}

void loop() {
  for (int i = 0; i < buttonCount; i++) {
    int currentState = digitalRead(buttons[i].pin);

    // Button pressed
    if (buttons[i].lastState == HIGH && currentState == LOW) {
      Serial.print(buttons[i].name);
      Serial.println(" pressed");

      if (strcmp(buttons[i].name, "AI") == 0) {
        aiRecording = true;
        aiStartTime = millis();
        drawAIListening();
        beep(1200, 60);
      }
      else if (strcmp(buttons[i].name, "MENU") == 0) {
        drawMenu();
        beep(700, 60);
      }
      else {
        drawButton(buttons[i].name);
        beep(1000, 40);
      }
    }

    // Button released
    if (buttons[i].lastState == LOW && currentState == HIGH) {
      Serial.print(buttons[i].name);
      Serial.println(" released");

      if (strcmp(buttons[i].name, "AI") == 0 && aiRecording) {
        float holdTime = (millis() - aiStartTime) / 1000.0;

        Serial.print("AI prompt length: ");
        Serial.print(holdTime, 1);
        Serial.println(" seconds");

        drawAIDone(holdTime);
        beep(500, 100);

        aiRecording = false;

        delay(1200);
        drawHome();
      }
    }

    buttons[i].lastState = currentState;
  }

  delay(30);
}
