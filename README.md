# NTU SC4010 Applied Cryptography Project - Simple Power Analysis
In this repository, we will be attempting to conduct a side channel attack, Simple Power Analysis, on an Arduino Uno running the RSA algorithm. In this project, we will be attempting to retrieve the decryption key via the power trace. We will also be referencing a study done by Xunyue He, et al - Blind-Folded: Simple Power Analysis Attacks using Data with a Single Trace and no Training.
This project is done as part of NTU CCDS module, SC4010 Applied Cryptography

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
   - not completed/used

## Project_code
1) processing.ipynb
   - Code to process the traces obtained from the oscilloscope, obtaining the decryption key
2) big_d_attempt.ipynb
   - Attempting SPA on a relatively larger decryption key
   - Does not work due to several hardware limitations
3) Other files containing images or oscilloscope readings for power and timing trace

## libgcrypt_RSA
1) libgcrypt_processing
   - Code and Pseudocode for processing the traces obtained from libgcrypt's implementation of traditional RSA
   - Sample traces are taken from https://github.com/huxunyue/spa_data/tree/main

## Side Channel Attack - Simple Power Analysis on Arduino.pdf
- Slides used for the presentation
