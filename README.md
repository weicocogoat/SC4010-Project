# NTU SC4010 Applied Cryptography Project - Simple Power Analysis
In this repository, we will be attempting to retrive RSA decryption keys from an Arduino running the RSA algorithm using Simple Power Analysis.
We will also be referencing a study done by Xunyue He, et al - Blind-Folded: Simple Power Analysis Attacks using Data with a Single Trace and no Training.

## Navigation
### Basic_Operations.ino 
File containing the 4 different operations that can be run on the Arduino. This is used initially to observe the difference in power trace when different operations are performed.

### receive_RSA.ino
This file simulates the Arduino receiving the encrypted message and is attempting to decrypt the message with its private key, d. Observing the power trace should reveal the difference between square and square&multiply operations. This is due to the implementation of modular exponentiation

### receive_RSA_libgcrypt_implementation_traditional.ino
This file contains a simplified version of how libgcrypt does the traditional exponentiation method for RSA. Observing its power trace should not immediately reveal any information.  
