/*
    **** Edit only earth_dimensions.c & submit in Dropbox ****

    DO NOT EDIT these two files:
    >  test_dimensions_c.cpp <--------------------------------
    >  doctest.h             <--------------------------------

    COMPILE ONLY ONCE:
    >  g++ -std=c++11 -Wall -Werror test_dimensions_c.cpp -o lab3test
    EXECUTE AS OFTEN AS earth_dimensions.c is edited:
    >  ./lab3test -s
        'lab3test' compiles & executes 'earth_dimensions.c'
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const double rad = 3949.903;          // in mi;        polar radius
const double circ = 24817.9725;       // in mi;        polar-based circumference
const double surfA = 196057168.0190;  // in square mi; polar-based surface area
const double vol = 258135598709.8839; // in cubic km;  polar-based volume

TEST_CASE("Test for student & lab info, POLAR earth radiius, circumference, surface area & volume")
{

    const int LN = 12; // number of items in 'earth_dimensions.c' output
    const int SZ = 256;
    char ch[LN][SZ]; // individual items in 'earth_dimensions.c' output

    // EXECUTE 'prog' with 'test.dat' (3949.903 mi)
    MESSAGE("\nEnter RADIUS here:");

    // COMPILE & TEST compile success
    int s = system("gcc -Wall -Werror earth_dimensions.c -o prog");
    if (s)
    {
        printf("Unable to COMPILE program: 'earth_dimensions.c' <%d>\n", s);
        FAIL("noCOMPILE");
        exit(1);
    }

    // EXECUTE 'prog' with 'test.dat' (3949.903 mi)
    FILE *file;

#if defined(_WIN64) || defined(_WIN32) || defined(WIN32) /*  Windows systems */
#define OS_Windows 1
    file = popen(".\\prog", "r");
#else
#define OS_Windows 0
    file = popen("./prog", "r");
#endif

    if (file == NULL)
    {
        puts("Unable to EXECUTE 'prog'");
        exit(1);
    }

    // read lines of output & place as items of 'ch'
    int line_no = 0;
    while (fgets(ch[line_no], SZ, file))
    {
        ch[line_no][strcspn(ch[line_no], "\n\r")] = '\0';

        printf("%s\n", ch[line_no]);
        size_t k;
        for (k = 0; k < strlen(ch[line_no]) - 1; k++)
        {
            // convert each character to lowercase
            // consequently ALL OUTPUT will be in LOWERCASE
            ch[line_no][k] = tolower(ch[line_no][k]);
        }

        line_no++;
        if (line_no >= LN)
        {
            break;
        }
    }
    printf("--------------------\n");

    pclose(file);

    // TEST 0
    REQUIRE_MESSAGE(ch[0] != NULL, "Test for successful compile, that is, 'file' is exists");

    // ALL OUTPUT DATA from 'earth_dimensions.c' must be on separate lines of text
    if (strlen(ch[0]) < 1 || strlen(ch[1]) < 1 || strlen(ch[2]) < 1)
    {
        // TEST 1: must include 3 name items
        printf("Tests exited without completing; correct your code and retest\n");
        FAIL("Error: 'First Name', 'Last Name' or 'Blinn Username' is empty.");
    }

    // TEST 2
    printf("'%s' contains '%s'? %s\n", ch[2], ch[0], strlen(ch[0]) > 0 ? "True" : "False");
    CHECK_MESSAGE(strstr(ch[2], ch[0]) - ch[2] >= 0, "Test that Blinn username contains First Name");
    // TEST 3
    printf("'%s' contains '%s'? %s\n", ch[2], ch[1], strlen(ch[1]) > 0 ? "True" : "False");
    CHECK_MESSAGE(strstr(ch[2], ch[1]) - ch[2] >= 0, "Test that Blinn username contains Last Name");

    // TEST 4
    printf("\nCourse  : '%s'\n", ch[3]);
    printf("Expected: '1420'\n\n");
    CHECK_MESSAGE(strstr(ch[3], "1420") - ch[3] == 0, "Test for Course number");
    // TEST 4
    printf("Section : '%s'\n", ch[4]);
    printf("Expected: 'N01'\n\n");
    CHECK_MESSAGE(strstr(ch[4], "n01") - ch[4] == 0, "Test for Section");
    // TEST 5
    printf("Lab name: '%s'\n", ch[5]);
    printf("Expected: 'the blue marble'\n\n");
    CHECK_MESSAGE(strcmp(ch[5], "the blue marble") == 0, "Test for Lab name");

    // Accuracy check within 1/1000 %
    // TEST 6
    printf("Inputted RADIUS of the earth in MILES: %s\n", ch[6]);
    printf("Expected: '%f'\n\n", rad);
    CHECK_MESSAGE(abs(atof(ch[6]) - rad) / rad < 0.00001, "Test for radius of the earth");
    // TEST 7
    printf("Calculated CIRCUMFERENCE of the earth in MILES: %s\n", ch[7]);
    printf("Expected: '%f'\n\n", circ);
    CHECK_MESSAGE(abs(atof(ch[7]) - circ) / circ < 0.00001, "Check for circumference of the earth");
    // TEST 8
    printf("Calculated SURFACE AREA of the earth in square MILES: %s\n", ch[8]);
    printf("Expected: '%f'\n\n", surfA);
    CHECK_MESSAGE(abs(atof(ch[8]) - surfA) / surfA < 0.00001, "Test for volume of the earth");
    // TEST 9
    printf("Calculated VOLUME of the earth in cubic MILES: %s\n", ch[9]);
    printf("Expected: '%f'\n\n", vol);
    CHECK_MESSAGE(abs(atof(ch[9]) - vol) / vol < 0.00001, "Test for volume of the earth");
    // TEST 10
    printf("Circle URL: '%s'\n", ch[10]);
    char circleURL[] = "furey, edward \"circle calculator\" at https://www.calculatorsoup.com/calculators/geometry-plane/circle.php from calculatorsoup, https://www.calculatorsoup.com - online calculators";
    printf("Expected  : '%s'\n\n", circleURL);
    CHECK_MESSAGE(strstr(ch[10], circleURL) - ch[10] == 0, "Test for Circle Formulas URL");
    // TEST 11
    printf("Sphere URL: '%s'\n", ch[11]);
    char sphereURL[] = "furey, edward \"sphere calculator\" at https://www.calculatorsoup.com/calculators/geometry-solids/sphere.php from calculatorsoup, https://www.calculatorsoup.com - online calculators";
    printf("Expected  : '%s'\n", sphereURL);
    CHECK_MESSAGE(strstr(ch[11], sphereURL) - ch[11] == 0, "Test for Sphere Formulas URL");
    // end all tests

    // delete executable file named 'prog'
    if (OS_Windows)
    {
        system("del prog.exe");
    }
    else
    {
        system("rm prog");
    }
    // rs/geometry-solids/sphere.php from calculatorsoup, https://www.calculatorsoup.com - online calculators
}
