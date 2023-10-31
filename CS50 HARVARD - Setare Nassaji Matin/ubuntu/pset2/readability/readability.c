#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(void)
{
    string text = get_string("Text: ");
    int letters = 0;
    // put words = 1 because of counting the last word.
    int words = 1;
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        //check if it's alphabet or not with "isalpha" and != , means not being equal with 0 .
        if (isalpha(text[i]) != 0)
        letters++;
        else if (text[i] == ' ')
        words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        sentences++;
    }
  float  L = ((float)letters / (float)words) * 100;
  float s = ((float)sentences / (float)words) * 100;
  float grade = 0.0588 * L - 0.296 * s - 15.8;
  if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
  else if(grade<1)
    {
        printf("Before Grade 1\n");
    }
   else
    {
        printf("Grade %i\n", (int) round(grade));
    }
}