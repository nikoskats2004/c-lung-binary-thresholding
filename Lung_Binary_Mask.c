/*
  ------------------------------------------------------------
  ANSI C IMAGE PROCESSING TEMPLATE USING DIP LIBRARY
  by D.K. Iakovidis 
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dip.h"			

unsigned char **processImage(unsigned char **inputImage, int rows, int columns);
unsigned char **processImageFusion(unsigned char **inputImage,unsigned char **inputImage2, int rows, int columns);
unsigned char **processImageThreshold(unsigned char **inputImage,int t, int rows, int columns);

int main(void)
{
     unsigned char *inputFilename = "chest339x339.raw",
                    *inputFilename2 = "petGrey221x279.raw",
                   *outputFilename = "mask.raw";
                   
     int rows = 339, 
         columns = 339;
        int t = 170; 
     unsigned char **inputImage, **inputImage2,**outputImage;

     inputImage = allocateImage(rows, columns);     
     inputImage = loadImage(inputFilename, rows, columns);
     inputImage2 =  allocateImage(rows, columns);  
     inputImage2 = loadImage(inputFilename2, rows, columns);
     outputImage=processImageThreshold(inputImage,t,rows,columns);
	 //outputImage=processImageFusion(inputImage,inputImage2,rows,columns);
     //outputImage = processImage(inputImage, rows, columns);
     saveImage(outputFilename, outputImage, rows, columns);    
     deallocateImage(inputImage, rows);
     deallocateImage(outputImage, rows);      

     return 0;
}


unsigned char **processImage(unsigned char **inputImage, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = inputImage[i][j];
         }
     }
     return outputImage;
}

unsigned char **processImageFusion(unsigned char **inputImage,unsigned char **inputImage2, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
             outputImage[i][j] = (inputImage[i][j] + inputImage2[i][j])/2;
             
         }
     }
     return outputImage;
}

unsigned char **processImageThreshold(unsigned char **inputImage,int t, int rows, int columns)
{
     int i,j;
     unsigned char **outputImage = allocateImage(rows, columns);
     
     for (i = 0; i < rows; i++)
     {
         for (j = 0; j < columns; j++)
         {
            // outputImage[i][j] = inputImage[i][j];
         if(inputImage[i][j] > t )  outputImage[i][j] = 255;
         else outputImage[i][j] = 0;
		 }
     }
     return outputImage;
}
