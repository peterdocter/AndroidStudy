#include <stdio.h>
 main()
{ 
         printf("60秒倒计时\n"); 
         int time = 60;
         printf("time 在内存中地址为%#x\n",&time); 
         for(;time>0;){
             time --;  
             printf("剩余时间为:%d\n",time);  
                    
             sleep(4000);//c语言也有sleep 
         }
       
         printf("时间到!!!\n"); 
       
         system("pause"); 
}
