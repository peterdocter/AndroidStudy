/**1.定义int　(*pf)(int x,　int y);
2.赋值 pf = add;
3.引用 pf(3,5);
*/
#include <stdio.h>

int add(int x,int y){ 
    return x+y; 
}
main()
{ 
     int (*pf)(int x, int y); //定义一个函数的指针 
      
     pf = add; 
      
      
   printf("result=%d\n",  pf(3,5)); 
      
   system("pause"); 
}

