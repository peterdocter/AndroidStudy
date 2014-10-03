#include <stdio.h>
#include <malloc.h>
void f(int** paddress){
   // int i = 3; 
    int* p = malloc(sizeof(int)*2);//在堆内存申请一块空间 
    *p = 5;                      //给这一个空间赋值 5; 
    *(p+1) = 10; 
    *paddress  = p;             //把空间的首地址 传递给主函数 
    printf("子函数p的值为%#x\n",p); 
    free(p); //通知操作系统 刚才申请的内存空间 可以被重新使用了.  
   
} 


main()
{            //需求: 在主函数里面 获取到子函数 i变量的地址. 
      int* p ;//用来存放 i变量的地址的. 
      f(&p); 
      printf("主函数 p =%#x\n",p); 
      
      printf("*p=%d\n",*p); 
      printf("*(p+1)=%d\n",*(p+1)); 
      
      system("pause"); 
}
