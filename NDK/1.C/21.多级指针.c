#include <stdio.h>
main()
{ 
    int i = 88;
    int* p = &i; 
    int** q = &p;
    int*** r = &q; 
      
    
    printf("i=%d\n",***r); 
      
      
      
    system("pause"); 
}
