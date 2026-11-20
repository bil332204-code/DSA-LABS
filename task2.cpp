//name: Bilal Ahmed
//reg no: 573512
//section: BSCS-15D
//this is lab 10 task 2 where we doing avl insertion and rotations
#include <iostream>
using namespace std;



//same node struct like task 1 but now height is actually use
struct Node {
    int data;
    Node *left, *right;
    int height;
};
//this func make a new node, left right is null and height is 1 bcz it is leaf
Node* newNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}
//height of null is 0, otherwise just give the height which store in node
int height(Node* root){
    if(root==nullptr) return 0;
    return root->height;
}
//this just give bigger number from two
int maxOf(int a,int b){
    if(a>b) return a;
    return b;
}
//update height of node, its 1 plus the bigger height from left or right
void updateHeight(Node* root){
    root->height=1+maxOf(height(root->left),height(root->right));
}
//balance factor is left height minus right height, if it is -1 0 or 1 then node is ok
int getBalance(Node* root){
    if(root==nullptr) return 0;
    return height(root->left)-height(root->right);
}
//right rotate, left child go up and root come down to right side
Node* rightRotate(Node* root){
    Node* newRoot=root->left;
    Node* temp=newRoot->right;

    newRoot->right=root;
    root->left=temp;

    //first update old root bcz now it is below, then new root
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
//left rotate is just opposite, right child go up and root come down to left
Node* leftRotate(Node* root){
    Node* newRoot=root->right;
    Node* temp=newRoot->left;

    newRoot->left=root;
    root->right=temp;

    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
//insert like normal bst then while coming back from recursion we fix balance
Node* insertAVL(Node* root,int value){

    //empty place found so make node here
    if(root==nullptr) return newNode(value);

    if(value<root->data)
    {
        root->left=insertAVL(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insertAVL(root->right,value);
    }
    else{
        //same value we ignore it, no duplicate allow
        return root;
    }

    //now update height of this node bcz something is insert below it
    updateHeight(root);
    int bal=getBalance(root);

    //this is LL case, left side is heavy and value went in left of left
    if(bal>1&&value<root->left->data){
        cout<<"  imbalance at "<<root->data<<" -> LL case -> right rotate"<<endl;
        return rightRotate(root);
    }
    //this is RR case, right side heavy and value went in right of right
    if(bal<-1&&value>root->right->data){
        cout<<"  imbalance at "<<root->data<<" -> RR case -> left rotate"<<endl;
        return leftRotate(root);
    }
    //this is LR case, left heavy but value went in right of left, so two rotation need
    if(bal>1&&value>root->left->data){
        cout<<"  imbalance at "<<root->data<<" -> LR case -> left rotate then right rotate"<<endl;
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //this is RL case, right heavy but value went in left of right, also two rotation
    if(bal<-1&&value<root->right->data){
        cout<<"  imbalance at "<<root->data<<" -> RL case -> right rotate then left rotate"<<endl;
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    //if no problem then just return root as it is
    return root;
}
//preorder is root then left then right
void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//inorder is left root right, in bst it come sorted
void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//this check every node and see if balance factor is between -1 and 1
bool isBalanced(Node* root){
    if(root==nullptr) return true;
    int bal=getBalance(root);
    if(bal>1||bal<-1) return false;
    return isBalanced(root->left)&&isBalanced(root->right);
}
//print every node with its height and balance factor so we can check
void printNodes(Node* root){
    if(root==nullptr) return;
    cout<<"  key: "<<root->data<<"  height: "<<root->height<<"  bf: "<<getBalance(root)<<endl;
    printNodes(root->left);
    printNodes(root->right);
}
//delete all node at end so no memory leak
void freeTree(Node* root){
    if(root==nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
//this run one sequence on a new empty tree and print everything
void runSequence(string name,int arr[],int n){
    cout<<"Sequence "<<name<<": ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    //every sequence get its own empty tree
    Node* root=nullptr;
    for(int i=0;i<n;i++){
        root=insertAVL(root,arr[i]);
    }

    cout<<"  root: "<<root->data<<endl;
    cout<<"  preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"  inorder: ";
    inorder(root);
    cout<<endl;
    printNodes(root);
    cout<<"  all node balanced: "<<(isBalanced(root)?"yes":"no")<<endl;
    cout<<endl;

    freeTree(root);
}
int main(){

    //these 4 sequence given in lab, each one make different rotation
    int a[]={30,20,10};
    int b[]={10,20,30};
    int c[]={30,10,20};
    int d[]={10,30,20};

    runSequence("(a)",a,3);
    runSequence("(b)",b,3);
    runSequence("(c)",c,3);
    runSequence("(d)",d,3);

    return 0;
}
