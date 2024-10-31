uint64_t x1_recv, y1_recv, B, x1, y1, x2, y2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  // RSA ECC Parameters, based on slide 87: y^2 = x^3 + 7x + 3
  // Bob receives point P(7, 32). His private key is B=7;
  x1_recv = 2;
  y1_recv = 5;

  B = 7;
}



void Double(uint64_t *x_ref, uint64_t *y_ref){
  uint64_t x = *x_ref;
  uint64_t y = *y_ref;
  uint64_t new_x, new_y, m;

  // Gradient
  m = (3*(x*x) + 7) / (2*y);
  m = m % 37;

  new_x = (m*m) - x - x;
  new_x = new_x % 37;
  *x_ref = new_x;

  new_y = m*(x-new_x) - y;
  *y_ref = new_y % 37;
}

void Add(uint64_t *x1_ref, uint64_t *y1_ref, uint64_t *x2_ref, uint64_t *y2_ref){
  uint64_t x1 = *x1_ref;
  uint64_t y1 = *y1_ref;

  uint64_t x2 = *x2_ref;
  uint64_t y2 = *y2_ref;
  
  uint64_t new_x, new_y, m;

  // Gradient
  m = (y2 - y1) / (x2 - x1);
  m = m % 37;

  new_x = (m*m) - x1 - x2;
  new_x = new_x % 37;
  *x1_ref = new_x;

  new_y = m*(x1 - new_x) - y1;
  *y1_ref = new_y % 37;
}

void loop() {
  // put your main code here, to run repeatedly:

  x1 = x1_recv;
  y1 = y1_recv;

  x2 = x1_recv;
  y2 = y1_recv;
  // First bit in double and add is always ignored
  B = B>>1;


  digitalWrite(11,LOW);
  // Double and Add
  while (B>0){
    digitalWrite(12, LOW);

    // Always do Doubling first
    Double(&x1, &y1);

    if (B%2){
      Add(&x1, &y1, &x2, &y2);
    }

    B = B >> 1;
    digitalWrite(12, HIGH);
  }
  digitalWrite(11, HIGH);
  // B = 7;

  Serial.print("x = ");
  Serial.println((int)x1);

  Serial.print("y = ");
  Serial.println((int)y1);

  // Forced stop
  while(1);

}
