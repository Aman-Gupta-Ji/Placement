#include<iostream>
#include<limits.h>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
// #include<bits/stdc++.h>
using namespace std;
int calculateCost(string S, vector<int>& C) {
    int sum=0;
    unordered_set<char> ocr;
    int n=S.length();
    for(int i=0;i<n;i++) {
        ocr.insert(S[i]);
    }
    for(char ch:ocr) {
        sum+=C[ch-'a'];
    }
    return sum;
}
int memoisation(int K, string S, vector<int>& C, unordered_map<string, int>& memo) {
    string key=S+":"+to_string(K);
    if(K==0)
        return calculateCost(S,C);
    if(memo.find(key)!=memo.end())
        return memo[key];
    int n=S.length();
    int mina=INT_MAX;
    int cost;
    for(int i=1;i<=n-K+1;i++) {
        cost=calculateCost(S.substr(0,i),C)+memoisation(K-1,S.substr(i),C,memo);
        mina=min(mina,cost);
    }
    return memo[key]=mina;
}
int MinSplit(int K, int L, string S, vector<int>& C) {
    unordered_map<string,int> memo;
    return memoisation(K,S,C,memo);
}
int main(void) {
    string inputline;
    getline(cin,inputline);
    int K=stoi(inputline);
    getline(cin,inputline);
    int L=stoi(inputline);
    getline(cin,inputline);
    string S=inputline;
    vector<int> C(L);
    for(int j=0;j<L;j++) {
        getline(cin,inputline);
        C[j]=stoi(inputline);
    }
    int result=MinSplit(K,L,S,C);
    cout<<result<<endl;
    return 0;
}