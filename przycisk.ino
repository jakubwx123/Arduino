int Led = 13;
int Switch = 2;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(Switch, INPUT);
}

void loop() {
  if (digitalRead(Switch) == HIGH)
    digitalWrite(Led, HIGH);
  else
    digitalWrite(Led, LOW);
}
