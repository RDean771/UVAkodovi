#include <iostream>
#include <bitset>
using namespace std;
int main(void)
{
	int n;
	while(cin >> n)
		cout << n << " converts to " << (int)__builtin_bswap32(n) << '\n';
	return 0;
}
