

#include <stdio.h>
#define PI 3.1415
void f(int** paddress){
    int i = 3; 
    *paddress  = &i; 
    printf("子函数i的地址为%#x\n",&i); 
} 


main()
{            //需求: 在主函数里面 获取到子函数 i变量的地址. 
      int* p ;//用来存放 i变量的地址的. 
      f(&p); 
    //printf("主函数 p =%#x\n",p); //放开这句，*p为-1；注释这句为3.  可见系统是会回收函数中的i变量的，但是系统回收也是有时间的。 
      
      printf("*p=%d\n",*p); 
      system("pause"); 
}
