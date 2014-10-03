//思考 为什么指针这么聪明 不同的指针类型 ,他知道移动对应的内存长度.
// 不同的指针变量 在加减的时候 移动的内存的长度是不相同的,所以 不同的指针类型知道自己内存需要移动(偏移)多少个字节. 

#include <stdio.h>
main()
{ 
         int i =3;
         double d = 3.1416;
         float f = 6.28;
         short s = 55;
         
         int*  ip = &i; 
         double* dp =&d;
         float* fp = &f;
         short* sp = &s;
         
         printf("ip的长度为%d\n",sizeof(ip));
         printf("dp的长度为%d\n",sizeof(dp));
         printf("fp的长度为%d\n",sizeof(fp));
         printf("sp的长度为%d\n",sizeof(sp));
          
      
      
          system("pause"); 
}
 
