struct Led
{
  int pin;
  int state;
  unsigned long previousMicros;
  unsigned long interval;
};


const int ledsCount = 5;
struct Led leds[] = {
  11, LOW, 0, 201000,
  10, LOW, 0, 21000,
  9, LOW, 0, 2100,
  6, LOW, 0, 210,
  5, LOW, 0, 21
};

void setup() {
  for (int i = 0; i < ledsCount; i++)
  {
    pinMode(leds[i].pin, OUTPUT);
  }
}

void loop()
{
  unsigned long currentMicros = micros();

  for (int i = 0; i < ledsCount; i++)
  {
    if (currentMicros - leds[i].previousMicros > leds[i].interval)
    {
      leds[i].previousMicros = currentMicros;

      if (leds[i].state == LOW)
        leds[i].state = HIGH;
      else
        leds[i].state = LOW;

      digitalWrite(leds[i].pin, leds[i].state);
    }
  }
}
