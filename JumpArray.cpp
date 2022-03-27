#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int mod=1000000007;
int cal(vector<int>& dp, int n) {
    dp[1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(i%(i-j)==0)
                dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    return dp[n];
}
int main(void) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> dp(n+1,0);
        int res=cal(dp,n);
        cout<<res<<endl;
    }
    return 0;
}