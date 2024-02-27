#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node *left;
    node *right;
    node(){
        left = NULL;
        right = NULL;
    }
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

void insert_node(int x,node* &root){
    node* newp=new node(x);
    if(root==NULL){
        root=newp;
        return;
    }
    char choice;
    node* temp=root;
    while(true)  {
        cout<<"Move left(l) or right(r) of"<<temp->val<<endl;
        cin>>choice;
        if(choice=='l'){
            if(temp->left==NULL){
                temp->left=newp;
                return;
            }
            else temp=temp->left;
        }
        else if(choice=='r'){
            if(temp->right==NULL){
                temp->right=newp;
                return;
            }
            else temp=temp->right;
        }
    }
}

void insertBST(node* &root,int key){
   node* newp=new node(key);
   if(root==NULL){
     root=newp;
     return;
   }
   node* temp=root;
   while(true){
        if(temp->val > key){
            if(temp->left == NULL){
                temp->left=newp;
                return;
            }
            else temp=temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right=newp;
                return;
            }
            else temp=temp->right;
        }
    }
}

node* deleteNode(node* root, int k){
    if (root == NULL)
        return root;

    if (root->val > k){
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->val < k){
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == NULL){
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL){
        node* temp = root->left;
        delete root;
        return temp;
    }
    else{
        node* succParent = root;
        node* succ = root->right;
        while (succ->left != NULL){
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->val= succ->val;
 
        delete succ;
        return root;
    }
}

int search(vector<int>arr, int strt, int end, int value){  
    for (int i = strt; i <= end; i++){ 
        if (arr[i] == value) 
            return i; 
    }
    return -1;
}

node* buildTree(vector<int>in,vector<int>pre, int inStrt, int inEnd) { 
    static int preIndex = 0; 
    if (inStrt > inEnd) 
        return NULL; 

    node* tNode = new node(pre[preIndex++]); 

    if (inStrt == inEnd) 
        return tNode; 

    int inIndex = search(in, inStrt, inEnd, tNode->val); 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd); 
    return tNode; 
}

void mirrorImage(node* root,node* & image){
    if(root==NULL)return;
    else if(root)image=new node(root->val);
    mirrorImage(root->left , image->right);
    mirrorImage(root->right , image->left);
}

void cloning(node* root, node* &cloned){
    if(root==NULL)return;
    cloned=new node(root->val);
    cloning(root->left,cloned->left);
    cloning(root->right,cloned->right);
}

void levelOrder(node *root){
    node *temp = root;
    vector<int> v;
    queue<node *> q;
    q.push(root);
    cout << "Level order traversal: ";
    while (!q.empty()){
        node *curr = q.front();
        cout << curr->val << " ";
        v.push_back(curr->val);
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}

void preOrder(node *root){
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root){
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(node *root){
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

vector<int> IterativePreOrder(node* root){
    vector<int>v;
    node* temp=root;
    stack<node*>s;
    if(root==NULL)return v;
    else s.push(root);
    while(!s.empty()){
        node* curr=s.top();
        v.push_back(curr->val);
        s.pop();
        if(curr->right!=NULL)s.push(curr->right);
        if(curr->left!=NULL) s.push(curr->left);
    }
    cout<<"Iterative preOrder traversal: ";
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    return v;
}

vector<int> IterativeInOrder(node* root){
    vector<int>v;
    node* temp=root;
    stack<node*>s;
    while(true){
        if(temp!=NULL){
           s.push(temp);
           temp=temp->left;
        }
        else{
            if(s.empty())break;
            temp=s.top();
            v.push_back(temp->val);
            s.pop();
            temp=temp->right;
        }
    }
    cout<<"Iterative inOrder traversl: ";
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    return v;
}

void IterativePostOrder(node* root){
    stack<node*>first;
    stack<node*>second;
    node* temp=root;
    if(root==NULL)return;
    first.push(root);
    while(!first.empty()){
        temp=first.top();
        first.pop();
        second.push(temp);
        if(temp->left)first.push(temp->left);
        if(temp->right)first.push(temp->right);
    }
    cout<<"Iterative postOrder traversal: ";
    while(!second.empty()){
        temp=second.top();
        cout<<temp->val<<" ";
        second.pop();
    }
    cout<<endl;
}

int height(node* root){
    if(root==NULL)return 0;
    int lht=height(root->left);
    int rht=height(root->right);
    return 1+max(lht,rht);
}

int main(){
    node *root=NULL;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    root->right->right = new node(7);

    // char ch='y';
    // while(ch=='y')
    // {
    //   int x;
    //   cout<<"Enter the value to be inserted : "<<endl;
    //   cin>>x;
    //   insert_node(x,root);
    //   cout<<"Press y to continue: ";
    //   cin>>ch;
    // }

    node* bst=NULL;
    insertBST(bst,1);     
    insertBST(bst,2);
    insertBST(bst,3);
    insertBST(bst,4);
    insertBST(bst,5);
    insertBST(bst,6);
    levelOrder(bst);
    cout<<endl;

    node* mirror=NULL;
    mirrorImage(bst,mirror);
    cout<<"Mirror image for above bst"<<endl;
    levelOrder(mirror);
    cout<<endl;

    node* copyTree=NULL;
    cloning(bst,copyTree);
    cout<<"Clone of given bst"<<endl;
    levelOrder(copyTree);
    cout<<endl;

    // levelOrder(root);
    vector<int>pre=IterativePreOrder(root);
    vector<int>in=IterativeInOrder(root);
    IterativePostOrder(root);
    int lenIn=in.size() - 1;
    cout<<endl;

    cout<<"Tree builded using preOrder and inOrder traversal"<<endl;
    node* formed=buildTree(in,pre,0,lenIn);
    IterativeInOrder(formed);
    IterativePreOrder(formed);
    cout<<endl;

    cout << "InOrder traversal: ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder traversal: ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder traversal: ";
    postOrder(root);
    cout<<endl;

    cout<<"Height of the given tree is: "<<height(root)<<endl;
}
