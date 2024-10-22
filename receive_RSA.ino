uint64_t n, p, q, e, d, M, received_encrypted_message, temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);

  // RSA Parameters
  // To the attacker, p, q, d are unknown. n & e make up the public key
  p = 5; q = 11; e = 33; d = 17;
  n = p * q;  // the mod value
  M = 2;      // the message
  received_encrypted_message = 52;   // 2^33 mod 55
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(11, LOW);
  temp = received_encrypted_message;
  M = 1;

  Serial.println("Running RSA...");

  // Modular Exponentiation
  while (d > 0)
  {
    // Do the squaring first
    M = (M * M) % n;

    // If the bit is a 1, then an additional multiplication should be done
    if (d % 2)
    {
      M = (M * temp) % n;
    }

    // Logical Shift right of d by 1 bit
    d = d >> 1;

    
    // Checking the output of the RSA algorithm
    Serial.print("M: ");
    Serial.println((int) M);

    Serial.print("d: ");
    Serial.println((int) d);
    
  }

  digitalWrite(11, HIGH);

  // Force a stop to the program. For testing purposes
  while(1);
}
