#include <stdio.h>
/*
java  8大基本数据类型.
byte short int long char float double boolean
1     2    4     8   2    4     8      1

C的基本数据类型,

char, int, float, double, signed, unsigned, long, short and void

sizeof();工具方法。获取某类型占用几个字节 
c语言中float int double short类型与java的长度是一样的。
c语言中char是一个字节。 最初是开发出来老外用的，后来才需要扩展字符。
c99中没有定义byte。 所以我们可以用java中的byte来代替c语言中的char。
c语言表示 boolean值，采用0和非0表示
c语言中long类型是4个字节，java中long类型是8个字节。 c语言中只规定了long >= int，所以c语言中long4个字节，int 4个字节 
*/
main()
{
      printf("char长度为%d\n",sizeof(char)); 
      printf("int长度为%d\n",sizeof(int)); 
      printf("float长度为%d\n",sizeof(float)); 
      printf("double长度为%d\n",sizeof(double)); 
      printf("long长度为%d\n",sizeof(long)); 
      printf("short长度为%d\n",sizeof(short)); 
      
      system("pause");
} 
