#include <stdio.h>
typedef int haha;  //定义数据类型的别名. 
enum WeekDay
{
Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};

int main(void)
{
  //int day;
  haha i = 3;
  printf("i=%d\n",i); 
  enum WeekDay day = Sunday;
  printf("%d\n",day);
  system("pause");
  return 0;
}
