#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int k=0;
	while(cin >> s)
	{
		k++;
		int n;
		cin >> n;
		cout << "Case " << k << ":" << endl;
		for (int i=0;i<n;i++)
		{
			int ind1,ind2,manji,veci;
			cin >> ind1 >> ind2;
			manji=(ind1 < ind2)? ind1: ind2;
			veci=ind1+ind2-manji;
			bool flag=1;
			if(veci-manji>=1)
			{
				for(int j=manji+1;j<=veci;j++)
				{
					if(s[j-1]!=s[j]) flag=0;
				}
			}
			if(flag) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
