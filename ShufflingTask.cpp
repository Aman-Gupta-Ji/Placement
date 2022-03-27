#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> workdone(vector<vector<int> >& people, int n, int q) {
    vector<int> done(n,0);
    int s, e, x;
    for(vector<int> qu: people) {
        s=qu[0], e=qu[1], x=qu[2];
        done[s]+=x;
        if(e+1<n)
            done[e+1]-=x;
    }
    for(int i=1;i<n;i++)
        done[i]+=done[i-1];
    return done;
}
int main(void) {
    int n, q;
    cin>>n;
    vector<int> task(n);
    int i;
    for(i=0;i<n;i++)
        cin>>task[i];
    cin>>q;
    vector<vector<int> > people(q);
    int s, e, x;
    for(i=0;i<n;i++) {
        cin>>s>>e>>x;
        people[i]={s,e,x};
    }
    vector<int> done = workdone(people,n,q);
    for(int d : done)
        cout<<d<<" ";
    cout<<endl;
    int res;
    cout<<res;
    return 0;
}