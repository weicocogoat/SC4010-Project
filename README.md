# NTU SC4010 Applied Cryptography Project - Simple Power Analysis
In this repository, we will be attempting to retrive RSA decryption keys from an Arduino running the RSA algorithm using Simple Power Analysis.
We will also be referencing a study done by Xunyue He, et al - Blind-Folded: Simple Power Analysis Attacks using Data with a Single Trace and no Training.

## Arduino files
1) Basic operations
   - Runs a few basic mathematical operations to observe the difference in traces
2) receive_RSA
   - Running a traditional RSA algorithm
   - Simulates that it has received an encrypted message
   - Running modular exponentiation to decrypt message
3) receive_RSA_libgcrypt_implementation
   - Traditional RSA algo, but with masking of the square & multiply operation
4) receive_RSA_ECC
   - not completed

## SPA_on_RSA_Arduino
1) processing.ipynb
   - Code to process the traces obtained from the oscilloscope, obtaining the decryption key

## libgcrypt_RSA
1) libgcrypt_processing
   - Code and Pseudocode for processing the traces obtained from libgcrypt's implementation of traditional RSA
