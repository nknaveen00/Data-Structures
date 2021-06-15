#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* insert_Node(struct node*, int);
void display(struct node*);
int check_bst_or_not(struct node*);
struct node* inorder(struct node*);
struct node* preorder(struct node*);
struct node* postorder(struct node*);
int getmax(struct node*);
int getmin(struct node*);
struct node* insert(struct node*);

void main()
{
    int ch,item,flag;
    struct node* root=NULL;
    do
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Check BST or NOT");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: root=insert(root);
                    break;/*printf("\nEnter the data to insert: ");
                    scanf("%d",&item);
                    root=insert_Node(root,item);
                    break;*/
            case 2: display(root);
                    break;
            case 3: flag=check_bst_or_not(root);
                    if(flag==1)
                        printf("\nThis tree is a BST");
                    else
                        printf("\nThis tree is not a BST");
        }
    }while(ch>0 && ch<=3);
}

struct node* insert_Node(struct node* root, int data)
{
    if(root==NULL)
    {
        struct node* newnode = (struct node*) malloc (sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return root=newnode;
    }
    else if(root->data<data)
        root->right=insert_Node(root->right,data);
    else if(root->data>data)
        root->left=insert_Node(root->left,data);
    else
        printf("\nDuplicate data not allowed");
}

void display(struct node* root)
{
    if(root==NULL)
        printf("\nTree is Empty");
    else
    {
        printf("\nINORDER\n");
        inorder(root);
        printf("\nPREORDER\n");
        preorder(root);
        printf("\nPOSTORDER\n");
        postorder(root);
    }
}

struct node* inorder(struct node* root)
{
    if(root==NULL)
        return root;
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}
struct node* preorder(struct node* root)
{
    if(root==NULL)
        return root;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* postorder(struct node* root)
{
    if(root==NULL)
        return root;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}

int check_bst_or_not(struct node* root)
{
    if(root==NULL)
        return 1;
    if(root->left!=NULL && getmax(root->left) > root->data)
        return 0;
    if(root->right!=NULL && getmin(root->right) < root->data)
        return 0;
    if(!check_bst_or_not(root->left) || !check_bst_or_not(root->right))
        return 0;

    return 1;
}

int getmax(struct node* root)
{
   while(root->right!=NULL)
    root=root->right;
   return root->data;
}

int getmin(struct node* root)
{
    while(root->left!=NULL)
    root=root->left;
   return root->data;
}

struct node* insert(struct node* root)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=6;
    root=newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=10;
    root->left=newnode;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=5;
    newnode->left=NULL;
    newnode->right=NULL;
    root->right=newnode;



    return root;
}
