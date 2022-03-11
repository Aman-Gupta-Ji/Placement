#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int convert(vector<int> a, vector<int> b) {
    int res=0;
    int target=a[0];
    int sa=a.size(), sb=b.size();
    int i, j;
    for(i=0;i<sa;i++) {
        if(a[i]==target)
            res++;
        else
            break;
    }
    
    return res;
}
int findMax(int n, vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<int> odd, even;
    for(int i=0;i<n;i++) {
        if(arr[i]&1)
            odd.push_back(arr[i]);
        else
            even.push_back(arr[i]);
    }
}
int main(void) {
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) {
        cin>>ar[i];
    }
    cout<<findMax(n,ar)<<endl;
    return 0;
}