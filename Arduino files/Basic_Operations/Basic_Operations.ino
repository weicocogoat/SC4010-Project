int a, b, c,d,e, f;
  

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  a = 87;
  b = 56;
  f = 31982;

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= 0x08;
  digitalWrite(12, LOW);

  digitalWrite(11, LOW);
  //PORTB |= 0x10;
  c = (a*b);
  //PORTB &= ~0x10;
  digitalWrite(11, HIGH);


  //PORTB |= 0x10;
  digitalWrite(11, LOW);
  d = c % f;
  //PORTB &= ~0x10;
  digitalWrite(11, HIGH);


  //PORTB |= 0x10;
  digitalWrite(11, LOW);
  e = a + d;
  // PORTB &= ~0x10;
  digitalWrite(11, HIGH);

  digitalWrite(12, HIGH);

/*
  PORTB |= 0x10;
  f = e<< 1;
  PORTB &= ~0x10;  
*/

//Serial.println(c+d+e);
//  Serial.println(d);
//  Serial.println(e);
//  
  PORTB &= ~0x08;  

  
}