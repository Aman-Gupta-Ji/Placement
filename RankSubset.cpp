#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
vector<string> ofRank(vector<string>& ord, int r) {
    if(r==1)
        return {};
    int n=ceil(log2(r));
    if(pow(2,ord.size())==r)
        return ord;
    vector<string> res;
    
    return res;
}
int main(void) {
    vector<string> ord;
    ord.push_back("aa");
    ord.push_back("bb");
    vector<string> res=ofRank(ord,4);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" , ";
    cout<<endl;
    return 0;
}