#include<iostream>
#include<cmath>
using namespace std;
int* createBlocks(int *arr,int n){
	int block_size = ceil(sqrt(n));
	int *blocks = new int[block_size];
	for(int i = 0;i < n;i++){
		blocks[i/block_size] += arr[i];
	}
	return blocks;
}
void update(int *arr,int *blocks,int n,int index,int key){
	int change = key - arr[index];
	arr[index] = key;
	int block_size = ceil(sqrt(n));
	blocks[index/block_size] += change;
}
int Sumquery(int *arr,int *blocks,int n,int l,int r){
	int block_size = ceil(sqrt(n));
	int start = l/block_size,end = r/block_size;
	int sum = 0;
	for(int i = start + 1;i < end;i++){
		sum += blocks[i];
	}
	int i = l;
	while(i/block_size == start){
		sum += blocks[i++];
	}
	i = r;
	while(i/block_size == r){
		sum += blocks[i--];
	}
	return sum;
}
int main()
{
	int n, *arr,index,key,l,r;
	cin>>n;
	arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	int *blocks = createBlocks(arr,n);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		switch(type){
			case 1: cin>>index>>key;
			        update(arr,blocks,n,index,key);
			    break;
			case 2: cin>>l>>r;
			        cout<<"Sum ="<<Sumquery(arr,blocks,n,l,r)<<endl;
			    break;
		}
	}
    return 0;
}