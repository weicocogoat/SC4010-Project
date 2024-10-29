uint64_t n, p, q, e, d, M, received_encrypted_message, temp;

int intarr[64];   // Array of bits of decryption key, d
int index = 0;    // Length (in bits) of decryption key, d

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  // RSA Parameters
  // To the attacker, p, q, d are unknown. n & e make up the public key
  //p = 5; q = 11; e = 33; d = 17;
  p = 11; q = 13; e = 13; d = 277;
  //p = 5; q = 23; e = 5; d = 53;

  n = p * q;  // the mod value

  // Message 
  // M = 2;      
  M = 69;
  // M = 2;

  // Simulate receiving of encrypted msg
  //received_encrypted_message = 52;   // 2^33 mod 55
  received_encrypted_message = 82;
  //received_encrypted_message = 32;


  // Calculate d in binary form and throw its value into an array
  while (d>0){
    intarr[index] = d % 2;
    d = d >> 1;
    index = index + 1;
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  temp = received_encrypted_message;
  M = 1;
  d = 53;

  Serial.println("Running RSA...");

  
  // Check array
  for (int i = index - 1; i >= 0; i--){
    Serial.print(intarr[i]);
  }
  Serial.println();
  

  digitalWrite(11, LOW);
  // Modular Exponentiation
  for (int i = index - 1; i >= 0; i--)
  {
    digitalWrite(12, LOW);
    // Do the squaring first
    M = (M * M) % n;

    // If the bit is a 1, then an additional multiplication should be done
    if (intarr[i]){
      M = (M * temp) % n;
    }

    // Logical Shift right of d by 1 bit (not needed now since bits are stored in array)
    d = d >> 1;
    digitalWrite(12, HIGH);

  
    // Checking the output of the RSA algorithm
    Serial.print("M: ");
    Serial.println((int) M);

    Serial.print("d: ");
    Serial.println((int) d);
  
  }
  digitalWrite(11, HIGH);

  // Force a stop to the program. For testing purposes
  Serial.println("End of RSA");
  while(1);
}
