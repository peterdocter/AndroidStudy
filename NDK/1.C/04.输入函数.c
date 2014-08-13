#include <stdio.h>
main()
{
      printf("请输入int类型的数据:");
      int i;
      //&i 把i变量的地址取出来。 
      scanf("%d", &i);//从键盘接收一个数据，然后把数据放在一块内存空间里面
      printf("i = %d\n", i);
      
      char arr[] ={' ',' ',' ',' ',' '}; 
      scanf("%s",arr); 
      
      printf("arr=%s",arr); 
          
      system("pause"); 
} 
