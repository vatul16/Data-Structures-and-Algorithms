// Implementation of various BST Operations

#include <iostream>
using namespace std;

struct btreenode
{
    btreenode *leftchild;
    int data;
    btreenode *rightchild;
};

class btree
{
    private:
        btreenode *root;

        void inorder(btreenode *sr);
        void preorder(btreenode *sr);
        void postorder(btreenode *sr);
        void insert(btreenode **sr, int);
        bool search(struct btreenode *, int);
        void locate(btreenode **sr, int num, btreenode **par, btreenode **x, bool *found);
        void rem(btreenode **sr, int num);
        void del(btreenode *sr);

    public:
        btree();
        void buildtree(int num);
        void display();
        bool searchbst(int);
        void remove(int num);
        ~btree();
};

// initialises data members
btree :: btree()
{
    root = NULL;
}

// calls insert() to build tree
void btree :: buildtree(int num)
{
    insert(&root, num);
}

// inserts a new node in a binary search tree
void btree :: insert(btreenode **sr, int num)
{
    if(*sr == NULL)
    {
        *sr = new btreenode;
        (*sr) -> leftchild = NULL;
        (*sr) -> data = num;
        (*sr) -> rightchild = NULL;
    }
    else        // search the node to which new node will be attached
    {
        // if new data is less, traverse to left
        if(num < (*sr) -> data)
        {
            insert(&((*sr) -> leftchild), num);
        }
        else
        {
            // traverse to right
            insert(&((*sr) -> rightchild), num);
        }
    }
}

// calls display()
void btree :: display()
{
    cout<<endl<<"Inorder:";
    inorder(root);

    cout<<endl<<"Preorder:";
    preorder(root);

    cout<<endl<<"Postorder:";
    postorder(root);
}

// traverse BST in Left-Root-Right fashion
void btree :: inorder(btreenode *sr)
{
    if(sr != NULL)
    {
        inorder(sr -> leftchild);
        cout<<sr -> data<<"\t";
        inorder(sr -> rightchild);
    }
}

// traverse BST in Root-Left-Right fashion
void btree :: preorder(btreenode *sr)
{
    if(sr != NULL)
    {
        cout<<sr -> data<<"\t";
        preorder(sr -> leftchild);
        preorder(sr -> rightchild);
    }
}

// traverse BST in Left-Right-Root fashion
void btree :: postorder(btreenode *sr)
{
    if(sr != NULL)
    {
        postorder(sr -> leftchild);
        postorder(sr -> rightchild);
        cout<<sr -> data<<"\t";
    }
}

bool btree :: searchbst(int num)
{
    bool flag;
    flag = search(root, num);
    return flag;
}

// search BST
bool btree :: search(struct btreenode *sr, int num)
{
    while(sr != NULL)
    {
        if(num == sr -> data)
            return true;

        else if(num < sr -> data)
            sr = sr -> leftchild;

        else
            sr = sr -> rightchild;
    }

    return false;
}

// calls rem to delete node
void btree :: remove(int num)
{
    rem(&root, num);
}

// deletes a node from the BST
void btree :: rem(btreenode **sr, int num)
{
    bool found;
    btreenode *parent, *x, *xsucc;

    // if tree is empty
    if(*sr == NULL)
    {
        cout<<endl<<"Tree is empty";
        return;
    }

    parent = x = NULL;

    // call to search function to find the node to be deleted
    locate(sr, num, &parent, &x, &found);

    //if the node to deleted is not found
    if(found == false)
    {
        cout<<endl<<"Data to be deleted, not found";
        return;
    }

    // if the node to be deleted has two children
    if(x -> leftchild != NULL && x ->  rightchild != NULL)
    {
        parent = x;
        xsucc = x -> rightchild;

        while(xsucc -> leftchild != NULL)
        {
            parent = xsucc;
            xsucc = xsucc -> leftchild;
        }

        x -> data = xsucc -> data;
        x =  xsucc;
    }

    //if the node to be deleted has no child
    if(x -> leftchild == NULL && x -> rightchild == NULL)
    {
        if(parent -> rightchild == x)
            parent  -> rightchild = NULL;

        else
            parent -> leftchild = NULL;

        delete x;
        return;
    }

    // if the node to be deleted has only rightchild
    if(x -> leftchild == NULL && x -> rightchild != NULL)
    {
        if(parent -> leftchild == x)
            parent -> leftchild = x -> rightchild;

        else
            parent -> rightchild = x -> rightchild;

        delete x;
        return;
    }

    // if the node to be deleted has only left child
    if(x -> leftchild != NULL && x -> rightchild == NULL)
    {
        if(parent -> leftchild == x)
            parent -> leftchild = x -> leftchild;

        else
            parent -> rightchild = x -> leftchild;

        delete x;
        return;
    }
}

// returns the address of the node to be deleted,
// address of its parent and whether the node is found or not
void btree :: locate(btreenode **sr, int num, btreenode **par, btreenode **x, bool *found)
{
    btreenode *q;

    q = *sr;
    *found = false;
    *par = NULL;

    while(q != NULL)
    {
        // if the node to be deleted is found
        if(q -> data == num)
        {
            *found = true;
            *x = q;
            return;
        }

        *par = q;

        if(q -> data > num)
            q = q -> leftchild;
        
        else 
            q = q -> rightchild;
    }
}

// calls del to deallocate memory
btree :: ~btree()
{
    del(root);
}

// deletes nodes of a BST
void btree :: del(btreenode *sr)
{
    if(sr != NULL)
    {
        del(sr -> leftchild);
        del(sr -> rightchild);
    }

    delete sr;
}

int main()
{
    btree bt;
    int i, a[] = {20, 17, 6, 18, 8, 5, 7, 10, 13};
    bool flag;

    for(i = 0; i <= 8; i++)
        bt.buildtree(a[i]);

    cout<<endl<<"BST after insertion:";
    bt.display();

    flag = bt.searchbst(13);
    if(flag == true)
        cout<<endl<<"Node 13 found in BST";
    else
        cout<<endl<<"Node 13 not found in BST";

    bt.remove(10);
    cout<<endl<<"BST after deleting 10:";
    bt.display();

    bt.remove(14);
    cout<<endl<<"BST after deleting 14:";
    bt.display();

    bt.remove(8);
    cout<<endl<<"BST after deleting 8:";
    bt.display();

    return 0;
}