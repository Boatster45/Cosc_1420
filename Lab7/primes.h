/* PERSONALIZE FILE
Johnathan Kissee
johnathan.kissee84
"Programming Lab 7: Struct Array of Prime Numbers"
April 23, 2024
Course: COSC 1420
Section: N02
*/

struct Primes{
    int prime;
};

// Function prototype
void generatePrimes(struct Primes p[], int SIZE);
int isPrime(struct Primes p[], int number);
void primeNumberOrSmallestFactor(struct Primes p[], int numbers[], int sz);
