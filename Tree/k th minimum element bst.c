#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* insert(struct node* , int);
void display(struct node*);
void find_kth_min(struct node* , int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int findk(struct node*);

void main(){
    struct node* root=NULL;
    int ch,data,k;
    system("color 3f");
    do{
        printf("\n1. Insert");
        printf("\n2. display");
        printf("\n3. Find kth minimum");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the data to insert: ");
                    scanf("%d",&data);
                    root=insert(root , data);
                    break;
            case 2: display(root);
                    break;
            case 3: printf("\nEnter the value of k: ");
                    scanf("%d",&k);
                    find_kth_min(root,k);
        }
    }while(ch>0 && ch<=3);
}

int count=0;
struct node* insert(struct node* root,int data){
    if(root==NULL){
        count++;
        struct node* newnode=(struct node*) malloc (sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    else
        printf("\nDuplicate data is not allowed\n");

    return root;
}

void display(struct node* root){
    if(root==NULL)
        printf("\nTree is Empty\n");
    else{
        printf("\nIn-order\n");
        inorder(root);
        printf("\nPre-order\n");
        preorder(root);
        printf("\nPost-order\n");
        postorder(root);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int arr[50],i=-1;
void find_kth_min(struct node* root, int k){
    if(k>count)
        printf("\nk value is greater than number of node!!!\nEnter valid number");
    else{
            int *ele=findk(root);
        printf("The %d minimum element is: %d",k,ele[k-1]);
    }
}

int findk(struct node* root){
    if(root!=NULL){
        findk(root->left);
        arr[++i]=root->data;
        findk(root->right);
    }
    /*for(int k=0;k<=i;k++)
        printf("%d ",arr[k]);*/
    return arr;
}
