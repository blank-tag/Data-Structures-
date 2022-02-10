#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>                                          
#define MAX 20


int postfix ();




char *prifix( char infix[20], char prefix[20] );



char *reverse ( char array[30] );


char pop();


void push( char symbol );



int prcd( char symbol );



int top = -1 ;
char stack[MAX];

void main() {

	char infix[20],prefix[20],temp;

	printf("Enter infix operation: ");
	scanf("%s",infix);

	printf("\n");

	printf("infix expression : %s \n",infix);
	postfix(infix);

	printf("\n");

	prifix(infix,prefix);

	reverse(prefix); 
                               
	puts((prefix));
	printf("\n");
   
}

char *prifix(char infix[20],char prefix[20]) {
	int i,j = 0;
	char symbol;
	

	stack[++top] = '#';
	

	reverse(infix);      
                           
	printf("prefix expression : ");
	for (i = 0;i<strlen(infix);i++) {


		symbol = infix[i];   
                         
		if (isalnum(symbol)) {

			prefix[j] = symbol;
			j++;

		}
		else {
			if (symbol == ')' ) {

						
				push(symbol);   
                    
			} 
			else if(symbol == '('){


				while (stack[top] != ')' ){

					prefix[j] = pop();
					j++;

				}
				pop();
			}
			else{


				if (prcd(stack[top]) <= prcd(symbol)) {

					push(symbol);

				} 
				else {


					while(prcd(stack[top]) >= prcd(symbol)){

						prefix[j] = pop();
						j++;

					}
					push(symbol);
				}
			}
		}
	}


	while (stack[top] != '#'){

		prefix[j] = pop();
		j++;

	}
	prefix[j] = '\0';
	return prefix;
}

char *reverse(char array[30]){
	int i,j;
	char temp[100];
	

	for (i = strlen(array)-1, j = 0; i+1!=0; --i, ++j) {

		temp[j] = array[i];

	}

	temp[j] = '\0';
	strcpy(array,temp);
	return array;
}

char pop() {
	char a;

	a = stack[top--]; 
                                
	return a;
}

void push(char symbol) {

	stack[++top] = symbol;                            
}

int prcd(char symbol) {
	switch(symbol){
		case '+':
		case '-':
		return 2;
		break;

		case '*':
		case '/':
		return 4;
		break;

		case '$':                                    
		case '^':
		return 6;
		break;

		case '#':
		case '(':
		case ')':
		return 1;
		break;
	}
}

int postfix(char exp[20]){
	char *e, x;
	printf("\n");

	e = exp;                                                     
	
	printf("postfix expression : ");
	while(*e != '\0'){
	    if(isalnum(*e)){
	        printf("%c",*e);
            }


	    else if(*e == '(') {                                        
	        push(*e);
	    }

	    else if(*e == ')'){
	        while((x = pop()) != '(')
	            printf("%c", x);
	    }

	    else{
	        while(prcd(stack[top]) >= prcd(*e))
	            printf("%c",pop());
	        push(*e);
	    }
	    e++;
	}
	
	while((top != -1) && (stack[top] != '#')){

	    printf("%c",pop());

	}
	printf("\n");
	return 0;
}
