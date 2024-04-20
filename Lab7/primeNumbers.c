/* PERSONALIZE FILE
Johnathan Kissee
johnathan.kissee84
"Programming Lab 7: Struct Array of Prime Numbers"
April 23, 2024
Course: COSC 1420
Section: N01 or N02
*/

#include <stdio.h>
#include <assert.h>
#include "primes.h"

/*
INSTRUCTIONS (complete assignment based 'on video'):
1. Tasks:
   1) Write function files:
      -- function headers ('primes.h', prototypes) &
      -- function definitions ('primes.c', implementation)
   2) Make an array of structs containing the first 1,230 prime numbers
      (starting with 2 and ending with 10,007)
      --the Primes struct has only one member: 'prime'
   3) Create two functions: 'generatePrimes' & 'isPrime' (using an efficient algorithm,
      for example, the Sieve of Erastosthenes)
   4) Create a third function, 'primeNumberOrSmallestFactor': for value <= 100,000,000, print out if number is prime or prime factor
   5) Personalize lines 2, 3 and 7
2. NOTE: all user-defined functions must be
   -- declared (prototypes) in 'primes.h' &
   -- implemented (definitions) in 'primes.c'
3. NOTE: My lab grader can use a different size array & a different final prime number
4. Compile with terminal command: gcc primeNumbers.c primes.c -o primes
5. Submit 'primes.h' and 'primes.c' in Dropbox
 */

int main(int argc, char const *argv[])
{
   const int SIZE = 1230;
   struct Primes p[SIZE];
   generatePrimes(p, SIZE);

   // last prime number is 10007
   assert(p[SIZE - 1].prime == 10007);
   // struct array has 1230 elements
   assert(sizeof(p) / sizeof(p[0]) == 1230);
   printf("The %dth prime number is %d.\n", SIZE, p[SIZE - 1].prime);

   //               p, p, p, prime,  prime,   prime, 9973 factor,
   int numbers[] = {2, 3, 4, 10007, 99999989, 10009, 99460729,};
   int sz = sizeof(numbers) / sizeof(numbers[0]);
   primeNumberOrSmallestFactor(p, numbers, sz);

   // printf("Original number: %d; prime or factor: %d\n", 47, isPrime(p, 47));
   return 0;
}
