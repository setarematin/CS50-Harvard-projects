#include<stdio.h>
#include<cs50.h>
int main(void)
{
    //: get the name
    string name = get_string("whats your name?\n"); 
    // print the name with hello!
    printf("hello, %s\n", name) ;
}