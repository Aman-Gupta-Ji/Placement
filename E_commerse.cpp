#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int findmin(vector<vector<int> >& prod, int row, int last,int m) {
    int min=0;
    while(min==last) {
        min=(min+1)%m;
    }
    if(row>=prod.size())
        return 0;
    for(int i=0;i<m;i++) {
        if(i!=last&&prod[row][min]>prod[row][i]) {
            min=i;
        }
    }
    int ans=prod[row][min]+findmin(prod,row+1,min,m);
    int min2=0;
    if(m==2)
        return ans;
    while(min2==last||min==min2) {
        min2=(min2+1)%m;
    }
    for(int i=0;i<m;i++) {
        if(i!=min&&i!=last&&prod[row][min2]>prod[row][i]) {
            min2=i;
        }
    }
    int ans2=prod[row][min2]+findmin(prod,row+1,min2,m);
    return (ans<ans2)?ans:ans2;
}
int main(void) {
    int n, m;
    cin>>n>>m;
    int min=0;
    vector<vector<int> > prod(n,vector<int> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cin>>prod[i][j];
    }
    min=findmin(prod,0,-1,m);
    cout<<min<<endl;
}