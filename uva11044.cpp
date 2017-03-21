#include <cstdio>
int main(void)
{
	int testcases,h,w,i;
	scanf("%d",&testcases);
	for(i=0;i<testcases;++i)
	{
		scanf("%d %d",&h,&w);
		printf("%d\n",(h/3)*(w/3));
	}
	return 0;
}
