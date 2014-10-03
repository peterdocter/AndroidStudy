#include <stdio.h>
 main()
{ 
       
       /**
       一般情况下 不同类型数据的指针不能相互转化. 

       **/
       unsigned short i = 666; 
       
       int* p = &i;
       
       short*  sp = &i;
       //printf("*sp=%hd\n",*sp);
       printf("*p=%d\n",*p); 
                     
       system("pause"); 
}
