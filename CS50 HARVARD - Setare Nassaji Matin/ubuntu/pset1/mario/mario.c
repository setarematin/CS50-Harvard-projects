#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int height;
    //height between 1 and 8
    do
    {
        height = get_int("height: ");
    }
    while (height <= 0 || height > 8 );
    //lets draw 
 for (int row = 0; row < height; row++)
{
    for (int spaces = row + 1; spaces < height; spaces++)
    {
        printf(" ");
    }

    for (int hashes = height + row + 1; hashes > height; hashes--)
    {
        printf("#");
    }
    printf("\n");
}                                                           ;
                                                                              }