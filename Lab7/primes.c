#include <stdio.h>
#include <math.h>
#include "primes.h"
// function definition
void generatePrimes(struct Primes p[], int SIZE){
    // define 1st prime number
    p[0].prime=2;
    //find remaining prime numbers
    int counter = 1;
    // for loop stop when counter = SIZE
    // only prime numbers used for testing for efficiency
    for (int number =3; counter < SIZE; number +=2)  {
        // if number prime, add to primes array & increase counter value
        if (isPrime(p, number) == number) {
            p[counter].prime = number;
            counter++;       
        }
    }
}

int isPrime(struct Primes p[], int number)
{
    double root = sqrt(number);
    for (int i = 0; p[i].prime <= root; i++){
        if (number % p[i].prime == 0) return p[i].prime;
    }
    return number;
}

void primeNumberOrSmallestFactor(struct Primes p[], int numbers[], int sz){
    for (int i = 0; i<sz; i++){
        int result = isPrime(p, numbers[i]);
        if (result == numbers[i]){
            printf("%d is a prime number.\n", numbers[i]);
        } else {
            printf("%d has a prime factor of %d.\n", numbers[i], result);
        }
    }
}
