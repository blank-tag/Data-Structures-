
#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>     
#include<string.h>

#define SIZE 1000


char stack[SIZE];
int top = -1;



void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


char pop() {
	char a;

	a = stack[top--]; 
                                
	return a;
}



int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

// prefix 
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


				if (is_operator(stack[top]) <= precedence(symbol)) {

					push(symbol);

				} 
				else {


					while(is_operator(stack[top]) >= precedence(symbol)){

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

//conversion to prefix 

/*char *prifix(char infix[SIZE], char prefix[SIZE])
{
  int i, j  = 0;
  char item;
  
  stack[++top] = '#';
  
  reverse(infix);
  for (i=0;i<strlen(infix);i++)
  {
  
  item = infix[i];
  
  if( isdigit(item) || isalpha(item))
  {
  	prefix[j] = item ;
  	j++;
  }
  else if(item == ')')
  {
  	push(item);
  
  }
  else if(item == '(')
  {
  	while(stack[top] != ')') {
  	
  		prefix[j]=

();
  		j++;
  	
  	}
  	pop();
  }
  else {
  
  	if(is_operator(stack[top] <= precedence(item)))
  	{
  		push(item);
  	}
  	else {
  	
  		while(is_operator(stack[top] >= precedence(item))){
  			prefix[j] = pop();
  			j++;
  		
  		}
  		
  		push(item);
  	
  	}
  
  
   }
  
  
  }
  	while(stack[top]!= '#')
	{
		prefix[j]= pop();
		j++;
	}
	prefix[j] ='\0';
	return prefix;
}*/


int InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               
	strcat(infix_exp,")");                  

	i=0;
	j=0;
	item=infix_exp[i];         

	while(item != '\0')     
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              
			j++;
		}
		else if(is_operator(item) == 1)        
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                      
			}
			push(x);
			

			push(item);                
		}
		else if(item == ')')         
		{
			x = pop();                   
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}

		i++;


		item = infix_exp[i]; 
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");       
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; 
	return 0;
}


void main()
{
	char infix[SIZE], postfix[SIZE], prefix[SIZE];      

	
	printf("\nEnter Infix expression : ");
	scanf("%s",infix);
	
	printf("\n");
	
	
	InfixToPostfix(infix,postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     
	
	
	
	
	prifix(infix,prefix);
	reverse(prefix);
	puts((prefix));
	
	
	              
}


