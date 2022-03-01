volatile float frequency = 1000;
bool pin[] = { 0,0,0,0,0 };
int ledPin[]={4,5,6,7,8};

void setup() {
 Serial.begin(9600);
 pinMode(2, INPUT_PULLUP);
 attachInterrupt(0, frequencyDown, FALLING);
 pinMode(3, INPUT_PULLUP);
 attachInterrupt(1, frequencyUp, FALLING);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
}

//убрать дребезг
void frequencyDown() {
  if (frequency < 16000) { frequency *= 2; }
}
void frequencyUp() {
  if (frequency > 62.5) { frequency /= 2; }
}

void ledControl(int ledID){
  if(pin[ledID]){
    digitalWrite(ledPin[ledID], HIGH);
  }
  else{
    digitalWrite(ledPin[ledID], LOW);
  }
  pin[ledID] = !pin[ledID];
}

//плохой рандом
void loop() {
  Serial.println(frequency);
  //delay (1000);

  int id = random(0,5);
  ledControl(id);
  delay(frequency);
}
