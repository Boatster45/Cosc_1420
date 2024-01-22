#include <stdio.h>
// Declare the structure Person 
struct Person
{
    char name[20], country[20], occupation[20];
    int age;
};
int main()
{
    // Create structure variable array of size 3
    struct Person p[3];
    int i;
    // Loop 3 times to gather inputs
    for (i = 0; i < 3; i++)
    {

        printf("\nEnter the name of person %d: ", i + 1);
        // replaced 'gets' with safer 'fgets'
        fgets(p[i].name, 20, stdin);
        printf("\nEnter the country of person %d: ", i + 1);
        fgets(p[i].country, 20, stdin);
        printf("\nEnter the occupation of person %d: ", i + 1);
        fgets(p[i].occupation, 20, stdin);
        printf("\nEnter the age of person %d: ", i + 1);
        scanf("%d", &p[i].age);
        // Use fflush(stdin) to clear any stale input buffer
        // This is useful when reading multiple inputs
        fflush(stdin);
    }
    // Loop 3 times to display
    for (i = 0; i < 3; i++)
    {
        printf("\nPerson %d:\n\n", i + 1);
        printf("\nName: ");
        puts(p[i].name);
        printf("\nCountry: ");
        puts(p[i].country);
        printf("\nOccupation: ");
        puts(p[i].occupation);
        printf("\nAge: %d \n", p[i].age);
    }
    return 0;
}
