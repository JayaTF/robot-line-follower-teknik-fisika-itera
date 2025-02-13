#define SENSOR_IR_KANAN 12
#define SENSOR_IR_KIRI 11
#define KECEPATAN_MOTOR 100

// Motor Kanan
int enableMotorKanan = 9;
int motorKananPin1 = 8;
int motorKananPin2 = 7;

// Motor Kiri
int enableMotorKiri = 3;
int motorKiriPin1 = 4;
int motorKiriPin2 = 5;

void setup()
{
  TCCR0B = TCCR0B & B11111000 | B00000010;
  
  pinMode(enableMotorKanan, OUTPUT);
  pinMode(motorKananPin1, OUTPUT);
  pinMode(motorKananPin2, OUTPUT);
  
  pinMode(enableMotorKiri, OUTPUT);
  pinMode(motorKiriPin1, OUTPUT);
  pinMode(motorKiriPin2, OUTPUT);

  pinMode(SENSOR_IR_KANAN, INPUT);
  pinMode(SENSOR_IR_KIRI, INPUT);
  putarMotor(0, 0);   
}

void loop()
{
  int nilaiSensorKanan = digitalRead(SENSOR_IR_KANAN);
  int nilaiSensorKiri = digitalRead(SENSOR_IR_KIRI);

  // Jika tidak ada sensor yang mendeteksi garis hitam, maka maju
  if (nilaiSensorKanan == LOW && nilaiSensorKiri == LOW)
  {
    putarMotor(KECEPATAN_MOTOR, KECEPATAN_MOTOR);
  }
  // Jika sensor kanan mendeteksi garis hitam, maka belok kanan
  else if (nilaiSensorKanan == HIGH && nilaiSensorKiri == LOW)
  {
      putarMotor(-KECEPATAN_MOTOR, KECEPATAN_MOTOR); 
  }
  // Jika sensor kiri mendeteksi garis hitam, maka belok kiri  
  else if (nilaiSensorKanan == LOW && nilaiSensorKiri == HIGH)
  {
      putarMotor(KECEPATAN_MOTOR, -KECEPATAN_MOTOR); 
  } 
  // Jika kedua sensor mendeteksi garis hitam, maka berhenti 
  else 
  {
    putarMotor(0, 0);
  }
}

void putarMotor(int kecepatanMotorKanan, int kecepatanMotorKiri)
{
  if (kecepatanMotorKanan < 0)
  {
    digitalWrite(motorKananPin1, LOW);
    digitalWrite(motorKananPin2, HIGH);    
  }
  else if (kecepatanMotorKanan > 0)
  {
    digitalWrite(motorKananPin1, HIGH);
    digitalWrite(motorKananPin2, LOW);      
  }
  else
  {
    digitalWrite(motorKananPin1, LOW);
    digitalWrite(motorKananPin2, LOW);      
  }

  if (kecepatanMotorKiri < 0)
  {
    digitalWrite(motorKiriPin1, LOW);
    digitalWrite(motorKiriPin2, HIGH);    
  }
  else if (kecepatanMotorKiri > 0)
  {
    digitalWrite(motorKiriPin1, HIGH);
    digitalWrite(motorKiriPin2, LOW);      
  }
  else 
  {
    digitalWrite(motorKiriPin1, LOW);
    digitalWrite(motorKiriPin2, LOW);      
  }
  analogWrite(enableMotorKanan, abs(kecepatanMotorKanan));
  analogWrite(enableMotorKiri, abs(kecepatanMotorKiri));    
}
