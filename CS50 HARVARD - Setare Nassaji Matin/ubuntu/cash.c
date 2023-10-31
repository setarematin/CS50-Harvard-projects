#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int count = 0;
    float change;
    //get change from user and be sure that is not under 0
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    //------------------
    int cent = round(change * 100);
    while (cent >= 25)
    {
        cent = cent - 25; //the maximum
        count++;  //count number of 25 cent coins
    }
    while (cent >= 10)
    {
        cent = cent - 10;
        count++;       //count number of 10 cent coins
    }
    while (cent >= 5)
    {
        cent = cent - 5;
        count++;  //count number of 5 cent coins
    }
    while (cent >= 1)
    {
        cent = cent - 1;
        count++;     //count number of 1 cent coins
    }
    printf("%i\n", count);
}