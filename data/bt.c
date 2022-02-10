#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
int value; 
struct treenode *left;
struct treenode *right;
} treenode; 

/* function to create a node and store values*/

treenode *createnode(int value){

treenode *results = malloc(sizeof(treenode));     //allocating memeory space for treenode

if(results != NULL ){
results->left = NULL ;
results->right = NULL;
results->value = value ;
}
return results;
}

void printtree (treenode* root){
    if (root == NULL){
        printf ("empty");
        return;
    }
    printf("value = %d\n",root->value);
    printf("left\n" );
    printtree(root->left );
    printf("right:\n");
    printtree(root->right);
    
}

//----------------------------------------------------//

int main ()  {

treenode *n1 = createnode(10);
treenode *n2 = createnode(11);
treenode *n3 = createnode(12);
//treenode *n4 = createnode(13);
//treenode *n5 = createnode(14);


n1->left = n2;
n1->right = n3;
 

printtree(n1);

free(n1);
free(n2);
free(n3);


}



