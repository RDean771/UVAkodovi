#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,bool> >V;
int main(void)
{
	int vojnici,promjene;
	while(cin >> vojnici >> promjene , vojnici && promjene)
	{
		V.clear();
		for(int i=0;i<vojnici;++i)
			V.push_back(make_pair(i+1,1));
		for (int i = 0; i < promjene; i++)
		{
			int lijevi,desni;
			cin >> lijevi >> desni;
			for (int j=lijevi-1; j < desni;j++)
				V[j].second=0;
			int rj1=0,rj2=0;
			for(unsigned int j=lijevi-1;j>=0;j--)
				if(V[j].second==1){rj1=V[j].first;break;}
			for(unsigned int j=desni;j<V.size();j++)
				if(V[j].second==1){rj2=V[j].first;break;}
			(rj1==0)? cout << '*' : cout << rj1; 
			cout << " ";
			(rj2==0)? cout << '*': cout << rj2 << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
