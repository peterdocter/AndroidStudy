#include <stdio.h>
#include <malloc.h>
/**
打印输出数组的每一个元素
*/ 
void printArr(int* arr, int len){ 
     int i; 
     for(i=0;i<len;i++){
        printf("i=%d\n",i); 
        printf("arr[%d]=%d\n",i,*(arr+i)); 
                    
      } 
      printf("end"); 
} 
main()
{       
     printf("请输入数组的长度");
     int  len ;
     scanf("%d", &len); 
    // int arr[len]; 
     
     int* arr =(int* ) malloc(sizeof(int)*len) ; //动态申请的内存 
     int i=0;
     for(;i<len;i++){
       printf("请输入第%d个数据\n",i); 
       scanf("%d",&arr[i]);           
     } 
      //打印显示这个数组的元素 
      printArr(arr,len); 
        
        printf("请输入增加的数组的长度"); 
        int increase;
        scanf("%d", &increase); 
        
        arr = realloc(arr,(len+increase)*sizeof(int));
        i =len; 
       for(;i<len+increase ;i++){
       printf("请输入第%d个数据\n",i); 
       scanf("%d",&arr[i]);           
     } 
     
      //打印显示这个数组的元素 
       printf("新的数组长度为:%d\n",len+increase); 
        printArr(arr,len+increase); 
        
        system("pause"); 
}
