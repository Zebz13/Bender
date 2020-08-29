#define force_input A2

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop()
{
  int force = analogRead(force_input);
  Serial.print("Analog reading = ");
  Serial.print(force);

  if (force < 10) {
    Serial.println(" - No pressure");
  } else if (force < 200) {
    Serial.println(" - Light touch");
  } else if (force < 500) {
    Serial.println(" - Light press");
  } else if (force < 800) {
    Serial.println(" - Medium press");
  } else {
    Serial.println(" - Big press");
  }

  delay(500)
}
