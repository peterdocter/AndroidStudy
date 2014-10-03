#include <stdio.h>
main()
{ 
    int i = 3;  //天津 解放路 33号  
    int j = 5;   // 北京 东北旺 9号 
    
    int* p = &i;
    int* q = &j;
    
    
    //p-q; 单纯的指针相加减 是没有任何的意义的.
    
    //指针的运算只有在连续的内存空间里面(数组)  才有意义. 
      
      
    system("pause"); 
}
