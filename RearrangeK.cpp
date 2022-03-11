#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int>& arr, int k, int n) {
    for(int i=0;i<n;i++) {
        if((arr[i]+i*k)%n!=i)
            return false;
    }
    return true;
}

bool permute(vector<int>& a, int l, int r, int k, int n)
{
    if (l == r)
        return check(a,k,n);
    for (int i = l; i <= r; i++)
    {
        swap(a[l], a[i]);
        if(permute(a, l+1, r, k, n))
            return true;
        swap(a[l], a[i]);
    }
    return false;
}

int main(void) {
    int n, k;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    bool res=permute(ar,0,n-1,k,n);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}