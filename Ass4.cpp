#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    node(){
        left=right=NULL;
    }
};
class Bst{
    public:
    node* root;
    Bst(){
        root=NULL;
    }
    void create();
    void insert(node*,node*);
    int height(node*);
    int mini(node*);
    bool search(node* root,int);
    void mirror(node*);
    void inorder(node*);
    //void inorder(node*);
};
void Bst::inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void Bst::create(){
    node* temp=new node();
    int data;
    cin>>data;
    temp->data=data;
    if(root==NULL)root=temp;
    else{
        insert(root,temp);
    }
}
void Bst::insert(node* root,node* temp){
    //if(root==NULL)create(root,data);
    if(temp->data<root->data){
        if(root->left==NULL){
            root->left=temp;
        }
        else{
            insert(root->left,temp);
        }
    }
    else{
        if(root->right==NULL){
            root->right=temp;
        }
        else{
            insert(root->right,temp);
        }
    }
}

int Bst::height(node* root){
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}

int Bst::mini(node* root){
    //if(root==NULL)return 0;
    node* temp=root;
    while(temp->left)
        temp=temp->left;
    return temp->data;
}

bool Bst::search(node* root,int data){
    if(root==NULL)return false;
    if(root->data==data)return true;
    bool ans1=false,ans2=false;
    if(root->data>data){
        ans1=search(root->left,data);
    }
    else{
            ans2=search(root->right,data);
    }
    return ans1||ans2;
}

void Bst::mirror(node* root){
    if(root==NULL)return;
    mirror(root->left);
    mirror(root->right);
    node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    //return root;
}

int main(){
    Bst b;
    b.create();
    int ch=0;
    while(ch!=6){
        cout<<"\nMENU\n";
        cout<<"1.Insert"<<endl;
        cout<<"2.Height"<<endl;
        cout<<"3.Minimum node\n";
        cout<<"4.Mirror\n";
        cout<<"5.Search"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        if(ch==1){
            b.create();
        }
        else if(ch==2){
            int h=b.height(b.root);
            cout<<"Heigth :"<<h<<endl;
        }
        else if(ch==3){
            int m=b.mini(b.root);
            cout<<"Minimum node :"<<m<<endl;
        }
        else if(ch==4){
            b.mirror(b.root);
            b.inorder(b.root);
        }
        else if(ch==5){
            int d;
            cin>>d;
            bool ans=b.search(b.root,d);
            if(ans)cout<<"Key found\n";
            else{
                cout<<"Key not found\n";
            }
        }
        else{
            break;
        }
    }
}