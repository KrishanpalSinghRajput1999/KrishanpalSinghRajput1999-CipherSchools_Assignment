#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class fib{
public:
int fib(int n)
{
	int f[n + 2]; 
	int i;
	f[0] = 0;
	f[1] = 1;

	for(i = 2; i <= n; i++)
	{
	f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
	}
};

int main ()
{
	fib g;
	int n;
    cin>>n;
	cout << g.fib(n);
	return 0;
}
