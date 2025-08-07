#include <stdio.h>
#include <stdlib.h>

int fun(int start,int end)
{

  int i ,w=0;
  for(i=start;i<=end;i++)
  {
      w=w+i;
  }
    return w;

}

int main()
{
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    int res = fun(x,y);
    printf("%d",res);

    return 0;
}
