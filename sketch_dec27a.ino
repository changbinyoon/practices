int L_button = 2;
int R_button = 3;
int L_led = 10;
int R_led = 11;

int L_ledState = HIGH;
int R_ledState = HIGH;
int L_buttonState = HIGH;
int R_buttonState = HIGH;
int L_lastButtonState = LOW;
int R_lastButtonState = LOW;

unsigned long L_lastDebounceTime = 0;
unsigned long R_lastDebounceTime = 0;
unsigned long debounceDelay = 80;

void setup() 
{
  pinMode(L_button, INPUT_PULLUP);
  pinMode(R_button, INPUT_PULLUP);
  digitalWrite(L_led, L_ledState);
  digitalWrite(R_led, R_ledState);

  Serial.begin(115200);
}

void loop() 
{
  int L_reading = digitalRead(L_button);
  int R_reading = digitalRead(R_button);

  if (L_reading != L_lastButtonState)
  {
    L_lastDebounceTime = millis();
  }

  if (R_reading != R_lastButtonState)
  {
    R_lastDebounceTime = millis();
  }

  if((millis() - L_lastDebounceTime) > debounceDelay)
  {
    if(L_reading != L_buttonState)
    {
      L_buttonState = L_reading;
      if(L_buttonState == LOW)
      {
        L_ledState = !L_ledState;
        Serial.println("L_Button");
      }
    }
  }
  if((millis() - R_lastDebounceTime) > debounceDelay)
  {
    if(R_reading != R_buttonState)
    {
      R_buttonState = R_reading;
      if(R_buttonState == LOW)
      {
        R_ledState = !R_ledState;
        Serial.println("R_Button");
      }
    }
  }

  digitalWrite(L_led, L_ledState);
  digitalWrite(R_led, R_ledState);
  L_lastButtonState = L_reading;
  R_lastButtonState = R_reading;
}
