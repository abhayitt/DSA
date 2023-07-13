#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data[100];
    struct node* left;
    struct node* right;
};

int findPath(struct node* root,char* common){
    if(root==NULL){
        return 0;
    }
    
    if(strcmp(root->data,common)==0){
        printf("%s ",root->data);
        return 1;
    }
    
    int left = findPath(root->left,common);
    int right = findPath(root->right,common);
    
    if(left!=0 || right!=0){
        printf("%s ",root->data);
        return 1;
    }
    
    return 0;
    
}
struct node *nodeInit(char* name){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    strcpy(newNode->data,name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* findCommonTown(struct node* root, char* corp1, char* corp2){
        if(root==NULL){
            return NULL;
        }
        
        if(strcmp(root->data,corp1)==0 || strcmp(root->data,corp2)==0){
            return root;
        }
        
        struct node* left = findCommonTown(root->left,corp1,corp2);
        struct node* right = findCommonTown(root->right,corp1,corp2);
        
        if(left !=NULL && right!=NULL){
            return root;
        }
        
        else{
            if(left!=NULL){
                return left;
            }
            return right;
        }
}

int main() {
    // struct node*root = NULL;
    struct node* cityNode = nodeInit("Jaipur");
    
    struct node* suburb1Node = nodeInit("North");
    cityNode->left = suburb1Node;

    struct node* suburb2Node = nodeInit("South");
    cityNode->right = suburb2Node;
    
    struct node* town1 = nodeInit("A");
    struct node* town2 = nodeInit("B");
    suburb1Node->left = town1;
    suburb1Node->right = town2;
    
    struct node* town3 = nodeInit("C");
    struct node* town4 = nodeInit("D");
    suburb2Node->left = town3;
    suburb2Node->right = town4;
    
    struct node* corp1 = nodeInit("56001");
    struct node* corp2 = nodeInit("56002");
    town1->left = corp1;
    town1->right = corp2;
    
    struct node* corp3 = nodeInit("56003");
    struct node* corp4 = nodeInit("56004");
    town2->left = corp3;
    town2->right = corp4;
    
    struct node* corp5 = nodeInit("56005");
    struct node* corp6 = nodeInit("56006");
    town3->left = corp5;
    town3->right = corp6;
    
    struct node* corp7 = nodeInit("56007");
    struct node* corp8 = nodeInit("56008");
    town4->left = corp7;
    town4->right = corp7;
    
    char corporation1[100],corporation2[100];
    printf("Enter Corporation 1\n");
    scanf("%[^\n]%*c", corporation1);
    
    printf("Enter Corporation 2\n");
    scanf("%[^\n]%*c", corporation2);
    
    struct node* ans = findCommonTown(cityNode,corporation1,corporation2);
    
    // printf("%s",ans->data);
    
    findPath(cityNode,ans);
    return 0;
}
