
#define pin1 2 //motor 1/L +
#define pin2 3 //motor 1/L -
#define pw1 9 //motor 1/L pwm
#define pin3 4 //motor 2/R +
#define pin4 5 //motor 2/R -
#define pw2 6 //motor 2/R pwm



void setup() {
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pw1, OUTPUT);
pinMode(pw2, OUTPUT);
Serial.begin(9600);
digitalWrite(pin1, LOW);
digitalWrite(pin2, LOW);
digitalWrite(pin3, LOW);
digitalWrite(pin4, LOW);
analogWrite(pw1, 10);
analogWrite(pw2, 10);

}

void loop() {
  if (Serial.available() >=2 )
  {
    unsigned int a = Serial.read();
    unsigned int b = Serial.read();
    unsigned int val = (b * 256) + a;

    if (val == 100) // Reverse_L
    {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);

    }
    else if (val == 300) // Forward_L
    {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    }
    else if (val == 400) // Reverse_R
    {
     digitalWrite(pin3, LOW);
     digitalWrite(pin4, HIGH);
    }
    else if (val == 600) // Forward_R
    {
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
    }
    else if (val >= 1000 && val <=1255) // Slider_L
    {
      analogWrite (pw1, val - 1000);
    }
    else if (val >= 2000 && val <= 2255) // Slider_R
    {
      analogWrite (pw2, val - 2000);
    }
    }
  }


