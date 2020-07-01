#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
 
typedef unsigned long long  ll;
const int S = 20;
ll mult_mod(ll a, ll b, ll c)
{
	a %= c;
	b %= c;
	ll ret = 0, tmp = a;
	while(b){
		if(b & 1){
			ret += tmp;
			if(ret > c)	ret -= c;
		}
		tmp <<= 1;
		if(tmp > c)	tmp -= c;
		b >>= 1;
	}
	return ret;
}
 
ll pow_mod(ll a, ll n, ll mod)
{
	ll ret = 1, tmp = a % mod;
	while(n){
		if(n & 1)	ret = mult_mod(ret, tmp, mod);
		tmp = mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}
 
bool check(ll a, ll n, ll x, ll t)
{
	ll ret = pow_mod(a, x, n);
	ll last = ret;
	for(int i = 1; i <= t; i++){
		ret = mult_mod(ret, ret, n);
		if(ret == 1 && last != 1 && last != n-1)	return true;
		last = ret;
	}
	if(ret != 1)	return true;
	else	return false;
}
 
bool Miller_Rabin(ll n)
{
	if(n < 2)	return false;
	if(n == 2)	return true;
	if((n & 1) == 0)	return false;
	ll x = n-1, t = 0;
	while((x & 1) == 0){
		x >>= 1;
		t++;
	}
	srand(time(NULL));
	for(int i = 0; i < S; i++){
		ll a = rand()%(n-1) + 1;
		if(check(a, n, x, t))	return false;
	}
	return true;
}
int main()
{
	ll n;
	cin >> n;
	if(Miller_Rabin(n))	cout << "Yes" << endl;
	else	cout << "No" << endl;
	return 0;
}

