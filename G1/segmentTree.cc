#include<iostream>
#include<cmath>
using namespace std;
int* newSegmentArray(int n) {
    size_t k=ceil(log2(n))+1;
    k=pow(2,k)-1;
    int *temp=(int*)malloc(sizeof(int)*k);
    return temp;
}
int rangeSum(int* seg, int ql, int qr, int sl, int sr, int i) {
    if(qr<sl||ql>sr)
        return 0;
    else if(ql<=sl&&qr>=sr)
        return seg[i];
    else {
        int mid=(sl+sr)/2;
        int sum=rangeSum(seg,ql,qr,sl,mid,2*i+1)+rangeSum(seg,ql,qr,mid+1,sr,2*i+2);
        return sum;
    }
}
void buidTree(int * seg, int *arr, int l, int r, int p) {
    if(l==r) {
        seg[p]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buidTree(seg,arr,l,mid,2*p+1);
    buidTree(seg,arr,mid+1,r,2*p+2);
    seg[p]=seg[2*p+1]+seg[2*p+2];
}
void update(int* seg,int diff, int ai, int sl, int sr, int i) {
    if(ai<sl||ai>sr)
        return;
    if(sl==ai&&sr==ai) {
        seg[ai]+=diff;
        return;
    }
    seg[i]+=diff;
    int mid=(sl+sr)/2;
    update(seg,diff,ai,sl,mid,2*i+1);
    update(seg,diff,ai,mid+1,sr,2*i+2);
}
int main() {
    int n;
    cin>>n;
    int *arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    size_t s=ceil(log2(n))+1;
    s=pow(2,s)-1;
    int *seg=newSegmentArray(n);
    buidTree(seg,arr,0,n-1,0);
    int Q, ch, l, r;
    cin>>Q;
    int i, key, diff;
    while(Q--) {
        cin>>ch;
        switch (ch)
        {
            case 1:
                cin>>l>>r;
                cout<<rangeSum(seg,l,r,0,n-1,0)<<endl;
                break;
            case 2:
                cin>>i>>key;
                diff=key-arr[i];
                arr[i]=key;
                update(seg,diff,i,0,n-1,0);
                break;
            default:
                break;
        }
    }
}