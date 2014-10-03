#include <stdio.h>

/**
打印输出数组的每一个元素
*/ 
void printArr(int* arr, int len){ 
     int i; 
     for(i=0;i<len;i++){
        printf("arr[%d]=%d\n",i,*(arr+i));             
      } 
} 

main()
{    printf("请输入数组的长度");
     int  len ;
     scanf("%d", &len); 
     int arr[len]; 
     int i=0;
     for(;i<len;i++){
       printf("请输入第%d个数据\n",i); 
       scanf("%d",&arr[i]);           
     } 
      //打印显示这个数组的元素 
      printArr(arr,len); 
      system("pause"); 
}
