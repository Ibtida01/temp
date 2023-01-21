#include<bits/stdc++.h>
using namespace std;
void solve(int t)
{
    map <int,int> m;
    map <int,int>::iterator it;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        it=m.find(x);
        if(it!=m.end())
        {
            //found
            ++m[x];
        }
        else {
            m[x]=1;
        }
    }
    int popu=0;
    for(it=m.begin();it!=m.end();it++)
    {
        int s=(it->second)+1;
        popu+=(it->second)/s+(it->second)%s *s;
    }
    printf("Case %d: %d",t,popu);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        solve(t);
    return 0;

}
