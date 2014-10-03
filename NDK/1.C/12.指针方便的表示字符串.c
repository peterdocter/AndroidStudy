#include <stdio.h>
main()
{ 
       char* str ="hello" ;  //<--> char str[] ={'h','e','l','l','o','\0'};  //内部转化为一个字符串的数组,并且在数组的最后一个元素拼装一个\0. 
      // char str[] ={'h','e','l','l','o','\0','t','o','m'};
       printf("str=%s\n",str); 
       system("pause"); 
}
