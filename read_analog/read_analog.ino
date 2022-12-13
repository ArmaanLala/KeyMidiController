#define RED 5V
#define BLACK GND
#define BROWN A0
#define ORANGE 37
#define YELLOW 41
#define GREEN 45
#define BLUE 49
#define PURPLE 53

int val = 0;

void setup() {

  pinMode(ORANGE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(PURPLE, OUTPUT);
  pinMode(BROWN, INPUT);

  digitalWrite(ORANGE,LOW);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(PURPLE,HIGH);
  digitalWrite(BLUE,LOW);

  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(BROWN);
	  Serial.println(val);
    delay(1000);
}
