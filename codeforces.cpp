/*___JAI SHREE RAM!___*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#define f for(ll i=0;i<n;i++)
#define D ios_base::sync_with_stdio(false);
#define H cin.tie(NULL);
#define R cout.tie(NULL);
#define tc ll T;cin>>T;while(T--)
#define ll long long int
#define vecin vector<ll> v; for(ll i=0;i<n;i++) {ll x; cin>>x; v.push_back(x);}
using namespace std;

int sumofD(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif
    D H R
    tc
    {
        int n,m;
        cin>>n>>m;
        while(sumofD(n)%m!=0){
            n++;
        }
        cout<<n<<endl;
        
    }
    return 0;
}