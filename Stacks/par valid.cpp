#include<bits/stdc++.h>
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORD(i,a,b) for(i=a-1;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define sf(x) cin>>x
#define pf(x) cout<<x
#define pfS cout<<" "
#define pfN cout<<"\n"
#define mp make_pair
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define MM(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define MM(a,x) memset(a,x,sizeof(a))
typedef long long int lli;

using namespace std;

int main()
{
	int i,l,r=0;
	vector<char> a;
	string s;
	sf(s);
	a.push_back(-1);
	for(i=0;s[i];i++)
	{
		if(s[i]=='(')
			a.push_back(i);
		else
		{
			a.pop_back();
			if(!a.empty())
			{
				l=a.size();
				r=max(r,i-a[l-1]);
			}
			else
				a.push_back(i);
		}
	}
	pf(r);
}
