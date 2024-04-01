/*
Johnathan Kissee
johnathan.kissee84
Lab6: Number Magic
04/01/24  
COSC 1420 Section N01
*/

#include <stdio.h>
#include <stdlib.h>

// Function to open the input data file and read the data to an array
void openInputDataFile(const char *fileName, int inputData[]) {
    FILE *file = fopen(fileName, "r");
    fscanf(file, "%d %d", &inputData[0], &inputData[1]); // Read two integers from the file
    fclose(file);
}

// Function to find the greatest common divisor
int findGCD(int a, int b) {
    while (b != 0) {
        int x = b; //let temp int x be equal to b
        b = a % b; //find modulus/remainder of a/b
        a = x; //modify temp int x to equal a
    }
    return a;
}

// Function to find prime factors of a number and write them to a file
void primeFactors(int num, const char *fileName) {
    FILE *file = fopen(fileName, "w"); //Open File
    // Iterate over numbers from 2 to num 
    for (int i = 2; i <= num; i++) {
        fprintf(file, "%d ", i); // Printf number followed by prime numbers
        int x = i; //int temp int x to i
        for (int j = 2; j <= x; j++) {
            while (x % j == 0) { //Check if remainder is 0
                fprintf(file, "%d ", j); // if so, Write each prime factor of the number
                x /= j;
            }
        }
        fprintf(file, "\n"); // Move to the next line 
    }
    fclose(file);
}


// Function to find/write the greatest common divisor to a file
void greatestCommonDivisor(int number1, int number2, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%d\n", number2); // Write  value of number2 to first line of the output file
    for (int i = 2; i <= number1; i++) {     // Calculate and write the GCD values for each number from 2 to number1
        fprintf(file, "%d %d\n", i, findGCD(i, number2));
    }

    fclose(file);
}