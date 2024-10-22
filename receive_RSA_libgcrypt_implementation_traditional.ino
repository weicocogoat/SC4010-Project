// RSA variables
uint64_t n, p, q, e, d, M, received_encrypted_message, temp;

// SetCond Variables
uint64_t xp;            // Squared and Multiplied value
uint64_t rp;            // Squared only value
uint64_t wzero = 0;     // Variable containing 64 0 bits
uint64_t wone = 1;      // Variable containing 63 0 bits and 1 1 bit at the LSB. 000.....01
uint64_t mask0, mask1;  // Bit masking

uint64_t result;

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

// Simplified version of libgcrypt implementation
uint64_t SetCond(uint64_t square_only, uint64_t square_and_multiply, uint64_t exponent){
  /*
  Depending on the exponent value, mask0 and mask1 values can either be 1111....111 or 000....000
  If the exponent is 0, only squaring is done, mask0 = 0...0 and mask1 = 1...1.
  If the exponent is 1, square and multiply is done, mask0 = 1...1 and mask1 = 0...0.
  */
  mask0 = wzero - exponent;
  mask1 = exponent - wone;

  /*
  If the exponent is 0, only squaring was done. Return the squaring value.
  If the exponent is 1, square and multiply was done. Return square and multiply value.

  The bitwise and(&) sets the wrong value to 0 and retains the correct value.
  */

  /*
  // Debugging stuff
  result = (mask0 & square_and_multiply) | (mask1 & square_only);
  Serial.print("Result: ");
  Serial.print((int) result);
  Serial.print(". Exponent: ");
  Serial.println((int) exponent);
  */

  return (mask0 & square_and_multiply) | (mask1 & square_only);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(11, LOW);
  temp = received_encrypted_message;
  M = 1;

  Serial.println("Running RSA...");

  // Libgcrypt implementation of the traditional exponentiation function, simplified
  while (d > 0)
  {
    // Do the square and multiply function
    rp = (M * M) % n;       // rp contains the squared only value
    xp = (rp * temp) % n;      // xp contains the squared and multiplied value
    
    // Determine which one to take
    M = SetCond(rp, xp, (d & 1) );

    // Logical Shift right of d by 1 bit
    d = d >> 1;

    // Checking the output of the RSA algorithm
    Serial.print("M: ");
    Serial.println((int) M);

    Serial.print("d (binary): ");
    Serial.println((int) d, BIN);
    
  }

  digitalWrite(11, HIGH);

  // Force a stop to the program. For testing purposes
  while(1);
}