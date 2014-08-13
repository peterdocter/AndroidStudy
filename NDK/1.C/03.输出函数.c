#include <stdio.h>
/*
占位符： 
%d  -  int
%ld – long int
%c  - char
%f -  float
%u – 无符号数
%hd – 短整型
%lf – double
%x – 十六进制输出 int 或者long int 或者short int
%o -  八进制输出
%s – 字符串

*/
main()
{
      int i = 3;
      double d = 3.1415926;
      char c = 'a';
      short s = 28;
      
      //注意一个原则，数据的类型一定要相互对应。 
      printf("i=%d\n", i);
      printf("d=%lf\n", d);
      printf("c=%c\n", c);
      printf("s=%hd\n", s);
      system("pause");
      
      
}      
