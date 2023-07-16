#include<iostream>
#include<vector>
#include<string>
using namespace std;
class node{
    public:
    vector<*node>children;
    string name;
    node(string name){
        this->name=name;
    }
};
void print(node* root,int depth){
    if(root==NULL)return;
    for(int i=0;i<depth;i++){
        cout<<" ";
    }
    cout<<"-"<<root->data<<endl;
    for(node* child:root->children){
        print(child,depth+1);
    }
}
int main(){
    node* book=new node("a");
    node* sec2=new node("seca2");
    node* sec1=new node("seca1");
    book.push_back(sec1);
    book.push_back(sec2);
    node* subsec2=new node("subseca2");
    node* subsec1=new node("subseca1");
    book.push_back(subsec1);
    book.push_back(subsec2);
    print(book,0);
}