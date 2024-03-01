/**********************************************************
EDIT ONLY THIS FILE & SUBMIT TO DROPBOX
Use '**** INSERT CODE HERE ****' to guide edit placements

PERSONALIZE your source code (place inside the <angle> brackets)
Blinn Username: <johnathan.kissee84>
Assignment: "Lab 4 How Large Is the U.S. Capitol Building?"
Course: COSC 1420
Section: <N02> (N01 or N02)
Due Date: Friday, March 1, 2024
**********************************************************/

#include <stdio.h>
#include <string.h>

// Function 'readData':
// 1. use 'str' for input prompt
// 2. read data from 'file'
// 3. return read 'value'
double readData(char *str, FILE *file)
{
    double value = 1;

    // Input prompt
    // **** INSERT CODE HERE ****
    printf("%s", str);

    // Input value
    // **** INSERT CODE HERE ****
    fscanf(file, "%lf", &value);

    // Output string value (without newline)
    // Set for fixed decimal, four (4) decimal places
    // **** INSERT CODE HERE ****
    printf("%.4lf", value);

    return value;
}

// Function 'inputline': read a line into 'str', return length
// Note: Value of string 'str' will be passed to 'monument' variable
// Note: Remove newline ('\n') from file input stream
void readName(char *str, int SIZE, FILE *file)
{
    // Input prompt
    printf("The NAME of the Federal Monument: ");

    // 1. Remove newline ('\n') from file input stream
    // 2. Input string value (may be multiple words)
    // **** INSERT CODE HERE ****
    fgets(str, SIZE, file);
    size_t len = strlen(str);
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
    }
    // Output inputted string value
    printf("%s\n", str);
}

// converts the distance to inches
// 1 m = 39.3700787 in
double total_in_inches(double size_in_meters)
{
    double total_in_inches = 39.3700787 * size_in_meters;
    // **** INSERT CODE HERE ****

    return total_in_inches;
}

// 'size':  height or diameter in inches
// 'scale': factor for reducing 'size'
double scale_inches(double size, double scale)
{
    double scaled_size = size / scale;
    // **** INSERT CODE HERE ****

    return scaled_size;
}

// find number of whole feet from inches
// use: 2.54 centimeters per inch for conversion factor
int find_feet(double inches)
{
    double feet = inches / 12;

    // **** INSERT CODE HERE ****

    return feet;
}

// find extra number of inches after number of feet deducted
double find_inches(double inches)
{
    double remaining_inches = inches - (find_feet(inches) * 12);
    // **** INSERT CODE HERE ****
    
    return remaining_inches;
}
