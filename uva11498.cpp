#include <iostream>
using namespace std;
int main(void)
{
	int q,koor1,koor2,x0,y0;
	while (1)
	{
		cin >> q;
		if (q==0)
			break;
		else
		{
			for(int i=0;i<=q;i++)
			{
				cin >> koor1 >> koor2;
				if (i==0)
				{
					x0=koor1;
					y0=koor2;
				}
				else
				{
					if (x0==koor1 || y0== koor2)
					{
						cout << "divisa" << endl;
					}
					else
					{
						if(koor1 > x0)
						{
							if(koor2 > y0)
								cout << "NE" << endl;
							else
								cout << "SE" << endl;
						}
						else
						{
							if(koor2 > y0)
								cout << "NO" << endl;
							else
								cout << "SO" << endl;
						}
						
					}
				}
		}
	}
	}
	return 0;
}
