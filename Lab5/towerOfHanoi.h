/*
Johnathan Kissee
johnathan.kissee84
Lab 5: Calculate Size of Tower of Hanoi Disks
04/01/24  
COSC 1420 Section N01
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void read_colors(const char *fileName, char *colors_string, int SIZE) {
    FILE *file = fopen(fileName, "r"); // Open file
    char color[100]; //char buffer array
    colors_string[0] = '\0'; // Initialize colors string
    //while loop to read each line, strconcatenate the color, and add space to the end of each
    while (fscanf(file, "%s", color) != EOF) {
        strcat(colors_string, color);
        strcat(colors_string, " ");
    }

    fclose(file); //Close file
}
// Function to calculate the diameter of a disk
double calc_diameter(double radius);

//Calculate diameter using given radius
double calc_diameter(double radius) {
    return 2 * radius;
}

//Caclulate Circumference using given radius and M_PI
double calc_circumference(double radius) {
    return 2 * M_PI * radius;
}

////Caclulate Total Surface Area of the Cylinder(s)
double calc_total_surface_area(double radius, double height) {
    return (2 * M_PI * radius) * (radius + height); //Utilizes the formula: total_area = 2 × π × r × (r + h).
}

//Caclulate Volume by multiply π by radius^2 and height.
double calc_volume(double radius, double height) {
    return M_PI * radius * radius * height;
}

//Failed due to not understanding the best way to ignore the "hole"
double calc_toh_disk_surface_area(double radius, double height) {
    return (2 * M_PI * radius) * (radius + height);
}

//Failed due to not understanding the best way to ignore the "hole"
double calc_toh_disk_volume(double radius, double height) {
    return M_PI * radius * radius * height;
}
