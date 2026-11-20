//name: Bilal Ahmed
//reg no: 573512
//section: BSCS-15D
//this is lab 10 task 3 where we doing avl insertion and also avl deletion
#include <iostream>
using namespace std;



//same node struct like task 1 and 2
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
//height of null is 0, otherwise give height store in node
int height(Node* root){
    if(root==nullptr) return 0;
    return root->height;
}
//this just give bigger number from two
int maxOf(int a,int b){
    if(a>b) return a;
    return b;
}
//update height, its 1 plus bigger height from left or right
void updateHeight(Node* root){
    root->height=1+maxOf(height(root->left),height(root->right));
}
//balance factor is left height minus right height
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

    //old root first bcz now it is below new root
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
//left rotate is opposite, right child go up and root come down to left
Node* leftRotate(Node* root){
    Node* newRoot=root->right;
    Node* temp=newRoot->left;

    newRoot->left=root;
    root->right=temp;

    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
//this fix balance of a node, we check child balance factor not the value
//so it work for both insert and delete
Node* rebalance(Node* root){
    updateHeight(root);
    int bal=getBalance(root);

    //left side heavy
    if(bal>1){
        //left child is not right heavy (bf 0 or more) so one right rotate is enough
        if(getBalance(root->left)>=0){
            cout<<"  node "<<root->data<<" left heavy, left child bf "<<getBalance(root->left)<<" -> right rotate"<<endl;
            return rightRotate(root);
        }
        //left child is right heavy so first left rotate it then right rotate root
        cout<<"  node "<<root->data<<" left heavy, left child bf "<<getBalance(root->left)<<" -> left rotate then right rotate"<<endl;
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //right side heavy
    if(bal<-1){
        //right child bf 0 or less so one left rotate enough
        if(getBalance(root->right)<=0){
            cout<<"  node "<<root->data<<" right heavy, right child bf "<<getBalance(root->right)<<" -> left rotate"<<endl;
            return leftRotate(root);
        }
        //right child is left heavy so right rotate it first then left rotate root
        cout<<"  node "<<root->data<<" right heavy, right child bf "<<getBalance(root->right)<<" -> right rotate then left rotate"<<endl;
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    //node is fine so no rotation
    return root;
}
//insert like normal bst and then fix balance when coming back
Node* insertAVL(Node* root,int value){
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
        //same value ignore it
        return root;
    }
    return rebalance(root);
}
//delete like task 1 bst delete, then fix balance at every ancestor
Node* deleteAVL(Node* root,int value){

    //tree empty or value not found so nothing to do
    if(root==nullptr) return nullptr;

    if(value<root->data)
    {
        root->left=deleteAVL(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=deleteAVL(root->right,value);
    }
    else{
        //no child so leaf, just delete it
        if(root->left==nullptr&&root->right==nullptr){
            delete root;
            return nullptr;
        }
        //only right child, it take the place of root
        else if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //only left child, same thing
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //two child, find smallest in right side and copy it then delete that one
        else{
            Node* successor=root->right;
            while(successor->left!=nullptr){
                successor=successor->left;
            }
            root->data=successor->data;
            root->right=deleteAVL(root->right,successor->data);
        }
    }
    //now update height and fix balance before going back up
    //this happen at every ancestor bcz of recursion
    return rebalance(root);
}
//preorder is root then left then right
void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//inorder is left root right, it come sorted
void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//print every node with height and bf so we can see tree is ok
void printNodes(Node* root){
    if(root==nullptr) return;
    cout<<"  key: "<<root->data<<"  height: "<<root->height<<"  bf: "<<getBalance(root)<<endl;
    printNodes(root->left);
    printNodes(root->right);
}
//this print the full info of tree in one go
void printTree(string msg,Node* root){
    cout<<msg<<endl;
    if(root==nullptr){
        cout<<"  (empty)"<<endl<<endl;
        return;
    }
    cout<<"  root: "<<root->data<<endl;
    cout<<"  preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"  inorder: ";
    inorder(root);
    cout<<endl;
    printNodes(root);
    cout<<endl;
}
//delete all node at end so no memory leak
void freeTree(Node* root){
    if(root==nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main(){

    Node* root=nullptr;

    //first make the tree with lab values
    int keys[]={30,20,40,10,25,50,5};
    for(int k:keys){
        root=insertAVL(root,k);
    }
    printTree("Initial AVL tree (no rotation need here):",root);

    //delete 50, after this 30 become left heavy so rotation come
    cout<<"Deleting 50"<<endl;
    root=deleteAVL(root,50);
    printTree("After deleting 50:",root);

    //delete 40, tree still balance so no rotation need
    cout<<"Deleting 40"<<endl;
    root=deleteAVL(root,40);
    printTree("After deleting 40 (no rotation needed):",root);

    //value which is not in tree, tree should stay same
    cout<<"Deleting 100 (missing key)"<<endl;
    root=deleteAVL(root,100);
    printTree("After deleting 100:",root);

    //try delete from empty tree, it should not crash
    Node* emptyTree=nullptr;
    emptyTree=deleteAVL(emptyTree,10);
    printTree("Delete 10 from empty tree:",emptyTree);

    //tree with only one node, after delete it should be nullptr
    Node* single=newNode(5);
    single=deleteAVL(single,5);
    printTree("Delete 5 from one-node tree:",single);
    cout<<"Root is nullptr: "<<(single==nullptr?"yes":"no")<<endl<<endl;

    //this test is when heavy child have bf 0
    //insert 30 20 40 10 25 then delete 40, now 30 left heavy and 20 have bf 0
    //here only single right rotate is enough bcz 20 is balance, it is not bend to right side
    //if we do double rotation here tree will become unbalance again
    Node* zeroTest=nullptr;
    int zkeys[]={30,20,40,10,25};
    for(int k:zkeys){
        zeroTest=insertAVL(zeroTest,k);
    }
    printTree("Heavy child bf 0 test, tree before:",zeroTest);
    cout<<"Deleting 40"<<endl;
    zeroTest=deleteAVL(zeroTest,40);
    printTree("After deleting 40:",zeroTest);

    //free remaining node before program end
    freeTree(root);
    freeTree(zeroTest);
    root=nullptr;
    zeroTest=nullptr;
    return 0;
}
