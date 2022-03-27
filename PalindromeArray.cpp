#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
int findCost(vector<int>& arr, int n) {
    unordered_map<int,int> freq;
    int N=n/2;
    for(int i=0;i<N;i++) {
        freq[arr[i]]++;
        freq[arr[i+N]]--;
    }
    if(freq.size()>N)
    	return -1;
    double cost=0;
    for(auto el: freq) {
        if(el.second&1)
            return -1;
        cost+=abs(el.second)/4.0;
    }
    return (int)cost;
}
int main(void) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        int temp;
        for(int i=0;i<n;i++) {
            cin>>temp;
            arr[i]=temp;
        }
        int res=findCost(arr,n);
        cout<<res<<endl;
    }
    return 0;
}