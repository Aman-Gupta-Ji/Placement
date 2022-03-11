#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef struct Node {
    bool isValid;
    Node *next[26];
} Node;
Node* newNode() {
    Node* temp=new Node();
    temp->isValid=false;
    for(int i=0;i<26;i++)
        temp->next[i]=NULL;
    return temp;
}
void insert(Node* head, string key) {
    Node* temp=head;
    int n=key.length();
    int pos;
    for(int i=0;i<n;i++) {
        pos=key[i]-'a';
        if(temp->next[pos]==NULL)
            temp->next[pos]=newNode();
        temp=temp->next[pos];
    }
    temp->isValid=true;
}
bool search(Node* head, string key) {
    Node* temp=head;
    int n=key.length();
    int pos;
    for(int i=0;i<n;i++) {
        pos=key[i]-'a';
        temp=temp->next[pos];
    }
    return temp->isValid;
}
bool check(Node* head) {
    for(int i=0;i<26;i++) {
        if(head->next[i]!=NULL)
            return false;
    }
    return true;
}
Node* deleteNode(Node* head, string key, int i) {
    if(i==key.length()) {
        head->isValid=false;
        if(check(head)) {
            delete(head);
            return NULL;
        }
        return head;
    }
    Node* temp=deleteNode(head->next[key[i]-'a'],key,i+1);
    if(temp==NULL) {
        head->next[key[i]-'a']=NULL;
        if(check(head)) {
            delete(head);
            return NULL;
        }
        return NULL;
    }
    return temp;
}

int main(void) {
    Node* head=newNode();
    string key;
    int ch;
    do{
        cout<<"1.Insert\n2.Search\n3.Delete\n4.Exit\n"<<endl;
        cin>>ch;
        cin>>key;
        for(int i=0;i<key.length();i++)
            key[i]=tolower(key[i]);
        switch (ch)
        {
            case 1:
                insert(head,key);
                break;
            case 2:
                if(search(head,key))
                    cout<<key<<" Found"<<endl;
                else
                    cout<<key<<" Not Found"<<endl;
                break;
            case 3:
                if(search(head,key))
                    deleteNode(head,key,0);
                break;
            default:
                break;
        }
    }while(ch!=4);
    return 0;
}