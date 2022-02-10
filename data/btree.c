#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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



bool insertnumber(btree **rootptr, int value){
	
	btree *root = *rootptr;
	if(root == NULL){
	
	(*rootptr) = createnode(value);
	return true;
	}
	
	if(value == root->value){
		return false;
	}
	
	if(value < root->value){
	 return insertnumber(&(root->left),value);
	} else {
	 return insertnumber(&(root->right),value);
	}
	

}

bool findnumber(btree *root, int value){
	if(root == NULL ) return false;
	
	
	if(root->value == value){
		return true;
	}
	if(value > root->value){
	
	 return findnumber(root->right,value);	
	}
	else {
	
	 return findnumber(root->left,value);
	
	}




}

int main(){

	btree *root = NULL;
	
	insertnumber(&root, 15);
	insertnumber(&root, 11);
	insertnumber(&root, 14);
	insertnumber(&root, 12);
	insertnumber(&root, 21);
	insertnumber(&root, 231);
	
	
	printtree(root);
	
	
	printf("%d (%d)\n",14 ,findnumber(root,14));
	
	printf("%d (%d)\n",45 ,findnumber(root,45));
	


}




