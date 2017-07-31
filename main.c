/**
* @brief IIR Filter Test
* @fn main.c
* @author shenxfs 380406785@@qq.com
* @date 2017-07-31
* @version V1.1.0
*/
#include <stdio.h>
#include <stdint.h>
#include "iirfilter.h"
int main(void)
 {
   int i,j;
   double y;
   for(i=0;i<300;i++)
   {
     printf("%3i#\n",i);
     printf("filter=%f\n",iir_filter(1.0,&fd));
   }
   printf("\n\n");
   for(i=0;i<400;i++)
   {
     printf("%3i#\n",i);
     printf("filter=%08X\n",fixiir_filter(0x10000L,&fx));
   }
   return 0;
 }
