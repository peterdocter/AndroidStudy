#include <stdio.h>
main()
{ 
        int  intarr[] ={1,3,4,5,6,7,9}; 
        char chararr[] ={'1','b','d','5'}; 
      
        printf("数组第一个元素值:%d\n",intarr[0]); 
        printf("数组第二个元素值:%d\n",intarr[1]); 
        
        printf("第一个元素的地址为%#x\n" ,&intarr[0]);
        printf("第二个元素的地址为%#x\n" ,&intarr[1]);
        printf("第三个元素的地址为%#x\n" ,&intarr[2]);
        
        printf("chararr第一个元素的地址为%#x\n" ,&chararr[0]);
        printf("chararr第二个元素的地址为%#x\n" ,&chararr[1]);
        
        
        printf("intarr变量名 = %#x\n",intarr);
        printf("chararr变量名 = %#x\n",chararr);
         
        //其实数组的变量名 代表的就是 数组里面第一个元素的地址. 
      
        system("pause"); 
}
