#include <stdio.h>

int main()
{
    // Set Pi as a Double constant
    const double PI = 3.1415926535898;
    // Declare Variables for Circumference, Surface Area, Volume, and the Polar Radius as a Double to allow for more precision
    double C, SA, V, PolR;
    // User input Radius Number
    scanf("%lf", &PolR);
 
    // Calculate the Circumference using Polar Radius inputted by user using PolarRadius * PI * 2
    C = PolR * PI * 2.000000;

    // Calculate the Surface Area using Polar Radius inputted by user using (PolarRadius *) * (PolarRadius^2)
    SA = (4.00000 * PI) * (PolR * PolR);

    // Calculate the Surface Area using Polar Radius inputted by user using ((4.0/3.0) * PI) * (PolarRadius^3)
    V = ((4.00000/3.00000) * PI) * (PolR * PolR * PolR);

    // Print Name and all other data points using decimal precision of 0.5 and the calcluations from above
    printf("Johnathan");
    printf("\nKissee");
    printf("\njohnathan.kissee84");
    printf("\n1420");
    printf("\nN01");
    printf("\nThe Blue Marble");
    printf("\n%.5lf", PolR);
    printf("\n%.5lf", C);
    printf("\n%.5lf", SA);
    printf("\n%.5lf", V);
    printf("\nFurey, Edward \"Circle Calculator\" at https://www.calculatorsoup.com/calculators/geometry-plane/circle.php from CalculatorSoup, https://www.calculatorsoup.com - Online Calculators");
    printf("\nFurey, Edward \"Sphere Calculator\" at https://www.calculatorsoup.com/calculators/geometry-solids/sphere.php from CalculatorSoup, https://www.calculatorsoup.com - Online Calculators");
    return 0;
}

