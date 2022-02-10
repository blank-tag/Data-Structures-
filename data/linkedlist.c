#include<stdio.h>
#include<stdlib.h>

struct blocks {
	
	int money;
	struct blocks *nextline;
	
};

struct blocks *getNewblock(const int money){
	
	struct blocks *newblock = NULL ;
	newblock = malloc(sizeof(struct blocks));
	newblock->nextline = NULL;
	newblock->money = money;
	
	printf("new block is created %p\n",newblock);
	return newblock;	
}  


void printnewblock(const struct blocks *subblock,const char *comment){

	if(subblock == NULL){
	    printf ("%s Empty block\n", comment);
	}
	else 
	{
	 	printf("%s: money:%d \n block address: %p, nextline:%p\n",
	 	 comment,
	 	 subblock->money,
	 	 subblock,
		 subblock->nextline);
	
	}

}


int main () {
	
	struct blocks *first = NULL ;
	struct blocks *second = NULL ;
	struct blocks *third = NULL;
	
	//printnewblock(first, "first");
	
	//printnewblock(second, "second");
	
	first = getNewblock(223213);
	second = getNewblock(323112);
	third = getNewblock(4123);

	first->nextline = second;
	printnewblock(second,"first");
	printnewblock(second->nextline,"third");
	second->nextline = third;
	
	
	printnewblock(first,"first");
	printnewblock(second,"second");
	printnewblock(third,"third");
	
	free(first);
	free(second);
	free(third);
	
	return 0;
	
}
