#define RED GND
#define BLACK 5V
#define BROWN A0
#define ORANGE 37
#define YELLOW 41
#define GREEN 45
#define BLUE 49
#define PURPLE 53

int val = 0;
int sliders[8];
int knobs[8];

void setup() {
    pinMode(ORANGE, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(PURPLE, OUTPUT);
    pinMode(BROWN, INPUT);

    digitalWrite(ORANGE, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    digitalWrite(PURPLE, HIGH);
    digitalWrite(BLUE, LOW);

    Serial.begin(9600);

    // put your setup code here, to run once:
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(BLUE, LOW);
    digitalWrite(PURPLE, HIGH);
    // Slider
    for (int i = 0; i < 8; i++) {
        if (i % 2 > 0) {
            digitalWrite(ORANGE, HIGH);
        } else {
            digitalWrite(ORANGE, LOW);
        }
        if (i % 4 > 1) {
            digitalWrite(YELLOW, HIGH);
        } else {
            digitalWrite(YELLOW, LOW);
        }
        if (i % 8 > 3) {
            digitalWrite(GREEN, HIGH);
        } else {
            digitalWrite(GREEN, LOW);
        }
        val = analogRead(BROWN);
        if (abs(knobs[i] - val) > 5) {
            knobs[i] = val;
            Serial.print("Slider ");
            Serial.print(i);
            Serial.print(" changed to ");
            Serial.println(val);
        }
        // delay(10);
    }
    // delay(10);
    digitalWrite(PURPLE, LOW);
    digitalWrite(BLUE, HIGH);

    // Knobs
    for (int i = 0; i < 8; i++) {
        if (i % 2 > 0) {
            digitalWrite(ORANGE, HIGH);
        } else {
            digitalWrite(ORANGE, LOW);
        }
        if (i % 4 > 1) {
            digitalWrite(YELLOW, HIGH);
        } else {
            digitalWrite(YELLOW, LOW);
        }
        if (i % 8 > 3) {
            digitalWrite(GREEN, HIGH);
        } else {
            digitalWrite(GREEN, LOW);
        }
        val = analogRead(BROWN);
        val = analogRead(BROWN);
        if (abs(sliders[i] - val) > 5) {
            sliders[i] = val;
            Serial.print("Rotary Knob ");
            Serial.print(i);
            Serial.print(" changed to ");
            Serial.println(val);
        }
        // delay(10);
    }

    // val = analogRead(BROWN);
    // Serial.println(val);
    // delay(100);
}
