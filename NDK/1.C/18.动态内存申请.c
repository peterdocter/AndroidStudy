#include <stdio.h>
//malloc 动态内存申请.
#include<malloc.h> 
main()
{   
   int* p =  malloc(sizeof(int)); //接受一个int类型的参数 ,参数的意义是 申请多少个byte空间的内存 
                         //方法的返回值 是这一块内存空间的首地址. 
                         // int* p;  p =  malloc(sizeof(int));
                         
   *p = 4;
   printf("*p=%d\n",*p); 
   free(p); 
   printf("*p=%d\n",*p); 
    system("pause"); 
}

