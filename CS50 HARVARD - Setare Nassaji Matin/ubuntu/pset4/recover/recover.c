#include<stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
int main(int argc, char *argv[])
{
    //check if input is valid
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
// open input file
    FILE *file=fopen(argv[1],"r");
    if(file == NULL)
    {
       printf("can not open\n");
    }

//creat buffer with 512 bytes.
    unsigned char buffer[BUFFER_SIZE];
// set filecount
    int filecount=0;
// set jpg count
    int jpg_found=0;
// define file for images
    FILE *img=NULL;
// set filename
    char filename[8];

// read file
//Repeat until end of card
    while (fread(buffer, BUFFER_SIZE, 1, file)== 1)

// check start of a new JPEG:
    {
       if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
//if JPEG has been found,close it
         if( jpg_found==1)
            {
              fclose(img);
            }
          else // if not then you found a JPEG
            {
               jpg_found=1;
            }

            sprintf(filename,"%03i.jpg",filecount);
            img=fopen(filename,"w");
            filecount++;
           }
        if (jpg_found == 1) //  found jpeg write from buffer to img file
         {
              fwrite(&buffer,BUFFER_SIZE,1,img);
         }
    }
fclose(file); // close file
   fclose(img);
   return 0;

}