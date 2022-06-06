#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define B begin()
#define ss setprecision
#define E end()
#define F first
#define S second
#define ll long long
#define pb push_back
#define fp(i,a,n) for(i=a;i<n;i++)
#define vii vector<pair<ll,ll>> 
#define dbg(x) cout<<#x<<" = "<<x<<"\n";
#define yn(f) (f)?cout<<"Y\n":cout<<"N\n";
ll mod=1e9+7;
void init_kode(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//bool prime[10000001];
// void SieveOfEratosthenes()
// {   ll i;
//     ll n=1e7+1;
//     memset(prime, true, sizeof(prime));
//     for (ll p = 2; p * p <= n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (ll i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// } 
// ll binexp(ll a,ll b)
// {
//     ll ans=1;
//     while(b)
//     {
//         if(b%2)
//         { ans=(ans*a)%mod;
//         }
//     a=(a*a)%mod;
//     b/=2;
//     }
//     return ans;
// }   
ll inf=1e16;
using ii=pair<ll,ll>;
int board[9][9];
bool ispossible=false;
bool check(ll i,ll j,ll val)
{
    for(int k=0;k<9;k++)
    {
        if(board[i][k]==val || board[k][j]==val)return 0;
    }
    ll bx=(i/3)*3,by=(j/3)*3;
    for(int dx=0;dx<3;dx++)
    {
        for(int dy=0;dy<3;dy++)
        {
            if(board[bx+dx][by+dy]==val) return 0;
        }
    }
    return 1;
}
void rec(int i,int j)
{
    if(i==9){
        ispossible=true;
        fp(i,0,9)
    {
        fp(j,0,9)cout<<board[i][j];
        cout<<'\n';
    }
        return;
    }
    if(j==9){
        rec(i+1,0);
    }
    if(board[i][j]!=0) rec(i,j+1);
    else
    {
        for(int k=1;k<10;k++)
        { 
           if(check(i,j,k)){
            board[i][j]=k;
            rec(i,j+1);
            board[i][j]=0;
           }  
        }
    }
}

int main()
{   init_kode(); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    ll tc=1; 
    //cin>>tc;   
    while(tc--){
    ll i,j,n,m; 
    fp(i,0,9)
    {
        string s; cin>>s;
        fp(j,0,9){
            if(s[j]=='.')board[i][j]=0;
            else board[i][j]=s[j]-'0';
        }
    }
    rec(0,0);

    // cout<<'\n';
    } 
    return 0;
}