#include<stdio.h>
#include<stdlib.h>

typedef struct btree {

	int value ;
	struct btree *left;
	struct btree *right;
}btree;


btree *createnode(int value){

	btree *results = malloc(sizeof(btree));
	if(results != NULL){
		results->left = NULL;
		results->right = NULL;
		results->value = value ;
	
	}
	return results;	
}


void printtabs(int numtabs){
	for(int i=0;i<numtabs;i++){
	printf("\t");
	
	}


}

void printtree_rec(btree *root, int level){

	if(root==NULL){
	printtabs(level);
	printf("--->empty<----\n");
		
	return;	
		
	}
	
	printtabs(level);
	printf("value = %d\n", root->value);
	printtabs(level);
	printf("left\n");
	
	printtree_rec(root->left,level+1);
	printtabs(level);
	printf("right\n");
	
	printtree_rec(root->right,level+1);
	
	printtabs(level);
	printf("done\n");

}

void printtree(btree* root){
	printtree_rec(root,0);	
	}




int main(){

	
	btree *n1 = createnode(10);
	btree *n2 = createnode(11);
	btree *n3 = createnode(12);
	btree *n4 = createnode(13);
	btree *n5 = createnode(14);
	
	n1->left=n2;
	n1->right= n3;
	n3->left = n4;
	n3->right = n5;
	
	
	printtree(n1);
	
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	
	
	


}




