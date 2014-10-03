#include <stdio.h> 
main()

 { 
      struct date { int year, month, day; }today; 
      union { long i; int k; char ii; double d; } mix; 

      printf("date:%d\n",sizeof(struct date)); 
      printf("mix:%d\n",sizeof(mix)); 
      mix.i = 33;
      mix.ii = 'a'; 
      printf("i=%d\n",mix.i); 
      //110100000101
  
      system("pause"); 
} 
