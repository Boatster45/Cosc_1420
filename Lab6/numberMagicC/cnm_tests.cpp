#include <iostream>
#include <fstream>
#include <cmath>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "numberMagic.h"

using namespace std;

SCENARIO("Number Magic")
{
    GIVEN("Necessary Data Items")
    {
        // input file reads only 2 numbers for 'GCD' and 'Prime Factors' tests:
        char inputFileName[] = "numberMagic.txt";

        // Array variable to receive data to be used for 'GCD' and 'Prime Factors' processing
        int inputData[2];

        WHEN("Reading Data File")
        {
            // ********************************************
            // TODO # 1: write function 'openInputDataFile'
            // the array 'inputData' passes its data by reference instead of by value
            openInputDataFile(inputFileName, inputData);

            // * 'GCD' test:
            // * number1 = range limit of numbers starting at 2 for 'GCD' test
            // * number2 = a second fixed number for 'GCD' test
            //
            // * 'Prime Factors' test:
            // * number1 = the upper limit of prime factors beginning with 2
            int number1 = inputData[0];
            int number2 = inputData[1];

            THEN("Testing Data Read from File")
            {
                // NUMBERS TO BE CHANGED FOR GRADING PURPOSES
                // Array of limit tests values
                int numbers[2] = {10, 20};

                // test range limit and second value
                CHECK(number1 == numbers[0]);
                cout << "Range of GCD first number, from 2 to: " << number1 << endl;
                CHECK(number2 == numbers[1]);
                cout << "Second GCD number: " << number2 << endl;
            }
            GIVEN("GCD: name & format of GCD output file")
            {
                // name & format of output file to receive 'GCD' values
                // * line 1: 'number2'
                // * line 2: 2 followed by the value of 'GCD(2, number2)'
                // * line 3: 3 followed by the value of 'GCD(3, number2)'
                // * line 4: 4 followed by the value of 'GCD(4, number2)'
                // * line 5: 5 followed by the value of 'GCD(5, number2)'
                // * . . .
                // * line 'number1': 'number1' followed by the value of 'GCD(number1, number2)'
                // NOTE: separate all values in each line by a space character [' ']
                char gcdFileName[] = "nm_gcd.txt";

                WHEN("Calculating GCD and output results file")
                {
                    // ********************************************
                    // TODO # 2: write function 'greatestCommonDivisor'
                    // Call GCD function to output GCD data to file
                    // -1 means that no answer was given for that particular test

                    greatestCommonDivisor(number1, number2, gcdFileName);

                    THEN("Check GCD file of values generated")
                    {
                        ifstream gcdStudentFile("nm_gcd.txt");
                        int studentValue;
                        ifstream gcdSolutionFile("nm_gcd_solutions.txt");
                        int solutionValue;
                        while (gcdSolutionFile >> solutionValue)
                        {
                            if (!(gcdStudentFile >> studentValue))
                            {
                                CHECK(solutionValue == -1);
                                break;
                            }
                            CHECK(solutionValue == studentValue);
                        }
                        // Automatic test failures if
                        // more SOLUTION values than STUDENT values
                        while (gcdSolutionFile >> solutionValue)
                        {
                            CHECK(solutionValue == -1);
                        }
                        // Automatic test failures if
                        // more STUDENT values than SOLUTION values
                        while (gcdStudentFile >> studentValue)
                        {
                            CHECK(studentValue == -1);
                        }
                        gcdSolutionFile.close();
                        gcdStudentFile.close();
                    }
                }
            }
            GIVEN("Prime Factorization: name & format of PF output file")
            {
                // 'Prime Factors' ['PF'] output file
                // name & format of output file to receive 'PF' values
                // * line 1: 2 followed by all prime factors of 2
                // * line 2: 3 followed by all prime factors of 3
                // * line 3: 4 followed by all prime factors of 4
                // * line 4: 5 followed by all prime factors of 5
                // * . . .
                // * line 'number1': 'number1' followed by all prime factors of 'number1'
                // NOTE: separate all values in each line by a space character [' ']
                // NOTE: 1 is not a prime number

                char pfFileName[] = "nm_pf.txt";

                WHEN("PF: generate range numbers and their prime factors then output results to file")
                {
                    // ********************************************
                    // TODO # 3: write function 'primeFactors'
                    // Call PF function to output PF data to file
                    // -1 means that no answer was given for that particular test

                    primeFactors(number1, pfFileName);

                    THEN("Check PF file of values generated")
                    {
                        ifstream pfStudentFile("nm_pf.txt");
                        int studentValue;
                        ifstream pfSolutionFile("nm_pf_solutions.txt");
                        int solutionValue;
                        while (pfSolutionFile >> solutionValue)
                        {
                            if (!(pfStudentFile >> studentValue))
                            {
                                CHECK(solutionValue == -1);
                                break;
                            }
                            CHECK(solutionValue == studentValue);
                        }
                        // Automatic test failures if
                        // more SOLUTION values than STUDENT values
                        while (pfSolutionFile >> solutionValue)
                        {
                            CHECK(solutionValue == -1);
                        }
                        // Automatic test failures if
                        // more STUDENT values than SOLUTION values
                        while (pfStudentFile >> studentValue)
                        {
                            CHECK(studentValue == -1);
                        }
                        pfSolutionFile.close();
                        pfStudentFile.close();
                    }
                }
            }
        }
    }
}