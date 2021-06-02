#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct stack{
	int n;
	int data[100];
	int top;
}stack;
int getsize(stack *);
void push(stack *,int);
int pop(stack *);
int peep(stack);
void display(stack);
int main()
{
	stack s1;
	int ch,item;
	getsize(&s1);
	s1.top=-1;
	do{
		system("cls");
		printf("1. Push\n2. Pop\n3. Peep\n4. Display \n5. Exit\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element you want to push :");
				scanf("%d",&item);
				push(&s1,item);
				break;
			case 2:
				item=pop(&s1);
				if(item!=-1)
					printf("The item popped is :%d\n",item);
				break;
			case 3:
				item=peep(s1);
				if(item!=-1)
					printf("The item peeped is :%d\n",item);
				break;
			case 4:
				display(s1);
				break;
			case 5:
				printf("The program is exited ");
				break;	
		}getch();
	}while(ch!=5);
	return 0;
}
int getsize(stack *s1)
{
	int t;
	
	printf("\nEnter the size of stack :");
	scanf("%d",&s1->n);
	t=(stack *)malloc(s1->n*sizeof(stack));
	return t;
}
void push(stack *s1,int item)
{
	if(s1->top==s1->n-1)
	{
		printf("Overflow!");
		return;
	}
	
		s1->top++;
		s1->data[s1->top]=item;
}
int pop(stack *s1)
{
	int item;
	if(s1->top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	else{
		item=s1->data[s1->top];
		s1->top--;
	}
	return item;
}
int peep(stack s1)
{
	int item;
	if(s1.top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	else
	{
		item=s1.data[s1.top];
	}
	return item;
}
void display(stack s1){
	int i;
	if(s1.top==-1)
	{
		printf("\nStack is empty!\n");
		return;
	}
	
	printf("The stack is :\n");
	for(i=s1.top;i>=0;i--)
	{
		printf("%d\n",s1.data[i]);
	}
}







