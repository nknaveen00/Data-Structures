#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* insertion(struct Node*,int);
struct Node* inorder(struct Node*);
struct Node* preorder(struct Node*);
struct Node* postorder(struct Node*);
struct Node* search(struct Node*,int);
struct Node* normal_search(struct Node*,int);
struct Node* getmin(struct Node*);
struct Node* getmax(struct Node*);
struct Node* deletenode(struct Node*,int);

void main()
{
    system("color 5f");
    int ch,data;
    struct Node* temp=NULL;
    struct Node* root=NULL;
    do
    {
        printf("\n1. INSERT");
        printf("\n2. PREORDER");
        printf("\n3. INORDER");
        printf("\n4. POSTORDER");
        printf("\n5. SEARCH WITH RECURSION");
        printf("\n6. SEARCH WITHOUT RECURSION");
        printf("\n7. GET MINIMUM");
        printf("\n8. GET MAXIMUM");
        printf("\n9. DELETE");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nEnter the data: ");
                scanf("%d",&data);
                root=insertion(root,data);
                break;
        case 2: preorder(root);
                break;
        case 3: inorder(root);
                break;
        case 4: postorder(root);
                break;
        case 5: printf("\nEnter the data to search: ");
                scanf("%d",&data);
                search(root,data);
                //printf("%d",temp->data);
                //if(data==temp->data)
                  //  printf("Not found\n");
                break;
        case 6: printf("\nEnter the data to search: ");
                scanf("%d",&data);
                normal_search(root,data);
                //printf("%d",temp->data);
                //if(data==temp->data)
                  //  printf("Not found\n");
                break;
        case 7: temp=getmin(root);
                printf("The minimum element is: %d\n",temp->data);
                break;
        case 8: temp=getmax(root);
                printf("\nThe maximum element is: %d\n",temp->data);
                break;
        case 9: printf("\nEnter the data to delete: ");
                scanf("%d",&data);
                root=deletenode(root,data);
                break;
        }
    }while(ch>0&&ch<=9);
}

struct Node* insertion(struct Node* root,int data)
{
    if(root==NULL)
    {
        struct Node* newnode=(struct Node*) malloc(sizeof(struct Node));
        newnode->left=NULL;
        newnode->data=data;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    else if(data<root->data)
        root->left=insertion(root->left,data);
    else if(data>root->data)
        root->right=insertion(root->right,data);
    else
        printf("\nNot allowed to insert duplicate values");
    return root;
}

struct Node* preorder(struct Node* root)
{
    if(root==NULL)
        return root;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
    return root;

}

struct Node* inorder(struct Node* root)
{
    if(root==NULL)
        return root;
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
    return root;
}

struct Node* postorder(struct Node* root)
{
   if(root==NULL)
        return root;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
    return root;
}

struct Node* search(struct Node* root,int data)
{
    if(root==NULL)
        return root;
    if(root->data==data)
    {
        printf("%d is present in the tree\n",data);
        return root;
    }
    if(root->data<data)
        return search(root->right,data);
    if(root->data>data)
        return search(root->left,data);
}

struct Node* normal_search(struct Node* root, int data)
{
    if(root==NULL)
        return root;
    struct Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->data==data)
        {
            printf("%d is present in the tree\n",data);
            return curr;
        }
        if(curr->data<data)
            curr=curr->right;
        if(curr->data>data)
            curr=curr->left;
    }
    return root;
}

struct Node* getmin(struct Node* root)
{
    if(root==NULL)
        printf("\nTree is Empty");
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct Node* getmax(struct Node* root)
{
    if(root==NULL)
        printf("\nTree is Empty");
    while(root->right!=NULL)
        root=root->right;
    return root;
}

struct Node* deletenode(struct Node* root,int data)
{
    if(root==NULL)
        return root;
    if(data>root->data)
        root->right=deletenode(root->right,data);
    else if(data<root->data)
        root->left=deletenode(root->left,data);
    else if(data==root->data)
    {
        if(root->left==NULL)
        {
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp=getmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
