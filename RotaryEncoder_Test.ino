
const int encoderPinA = D2;
const int encoderPinB = D3;

int lastStateA;
int counter = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  lastStateA = digitalRead(encoderPinA);
}

void loop() 
{
  int stateA = digitalRead(encoderPinA);

  if (stateA != lastStateA) 
  {
    if (digitalRead(encoderPinB) == stateA) 
    {
      counter += 5; // Ändert den Wert in Fünferschritten nach rechts
    } 
    else 
    {
      counter -= 5; // Ändert den Wert in Fünferschritten nach links
    }

    Serial.println(counter);
    delay(20); // Entprellung und verkürzte Verzögerung
  }

  lastStateA = stateA;
}
