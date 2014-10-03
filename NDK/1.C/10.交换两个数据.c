#include <stdio.h>

swap(int i, int j){//值传递 
         
       int temp;
       printf("子函数 i的地址%#x\n",&i);
       printf("子函数 j的地址%#x\n",&j);
        
       temp = i;
       i = j;
       j = temp; 
      
         
         
} 


swap2(int* p, int* q){//引用传递 (实质:值的拷贝)
      
       int temp;
       printf("子函数 p的值%#x\n",p);
       printf("子函数 q的值%#x\n",q);
        
       temp = *p; //*p其实就是主函数的i变量 
       *p = *q;   //*q 其实就是主函数的j变量 
       *q = temp; 
      
                 
}


 main()
{ 
       int i = 3;
       int j = 5;
        printf("主函数 i的地址%#x\n",&i);
       printf("主函数 j的地址%#x\n",&j);
       //swap(i,j); 
       swap2(&i,&j); 
       printf("i=%d\n",i);
       printf("j=%d\n",j); 
       system("pause"); 
}

