#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>



void main()
{



int i;

//二位数组a[m][n]


 int c = 1;
 int r = 100*pow(2.0, (double)20); // 10GB;
 char **arr;

 arr = (char **) malloc(r * sizeof(char *));

for(i=0; i<r; ++i)
{
    arr[i] = (char *) malloc(c * sizeof(char));
    memset(arr[i], 'A', c*sizeof(char));
}
 
    // Fill whole array with 100.

    printf("Array after memset()\n");
    for (int i=0; i<r; )
    {
      arr[i++];
   
    }

    for(int i=0;i<r;i++)
      free(arr[i]);


  
  // int c = 1048576;
  // int r = 3, i, j, count;
  // char randomletter;
  // char *temp[r];
  // char * name = "Robert";
 
  // char **arr;

  // memset(arr, 'A', sizeof(int) * r*c);
    // for (i=0; i<r; i++)
    // {
    //     memset(&arr[i], 'A', c * sizeof(char));
    //     printf("%s memory allocate \n",arr[i]);
        

    //     if(arr[i]!=NULL)
    //     {
    //       printf("memory successful\n");
          
    //     }
    //     else
    //     {
    //       printf("memory_fail\n");

    //       //return NULL;

    //     }
    // }
 
    // Note that arr[i][j] is same as *(*(arr+i)+j
    // count = 0;
    // //temp = arr;
    // for (i = 0; i <  r; i++)
    // {
    //   for (j = 0; j < c; j++)
    //   {
    //      randomletter = 'A' + (random() % 26);
    //    // printf("%c random num\n",randomletter);
    //     strcpy(&arr[i][j], &randomletter);
    //     //&arr[i][j]  = randomletter;

    //   }
    // }
    //arr = temp;
 
    // for (i = 0; i <  r; i++)
    // {
    //   printf("%d i %s \n",i, &arr[i][0]); 

      
    // }
    // for(int i=0;i<r;i++)
    //   free(arr[i]);

  // for(i=0;i < 10;i++)
  // {
  //   char randomletter = 'A' + (random() % 26);
  //   printf("%c random num\n",randomletter);
  //   *ptr  = randomletter;
  //   ptr++;          // New Location i.e increment Pointer
  // }
  // //strcpy

  //  ptr = temp;// 歸零
  //  printf("\nptr : %s\n",ptr);
  //  // pointer = ptr+2;
  //  // printf("\npointer : %s\n",pointer);
  //  //diff = ptr-pointer;

  // // printf("\ndiff : %s\n",ptr);

  // for(i=0;i < 10;i++)
  // {
  //   printf("\nNumber(%d) : %c\n",i,*ptr);
  //   *ptr++;
  //   printf("\naNumber(%d) : %c\n",i,*ptr++);
  //   printf("\nNumber(%d) : %s\n",i,ptr);
  //   ptr++;
  // }

}