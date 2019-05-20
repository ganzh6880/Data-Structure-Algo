#include<stdio.h>
#define size 10

int stack[size];
int val,i,t;
void stack_init();
int empty();
void push(val);
void pop();
int is_full();

int main(void)
{
 stack_init();
 for(i=0;i<=20;i++)
 {
    printf("Please input your value = ");
    scanf("%d",&val);
    printf("\n");
    switch(val){
    case -1:
     {
         if(empty() == 1)
            printf("Error - Stack is empty.\n\n");
         else
         printf("%d\n\n",top());
         break;
     }

     case 0:
     {
        if(empty() == 1)
            printf("Error - Stack is empty.\n\n");
        else
        pop();
        break;
     }

     default:
    {
        push(val);
        break;
    }
 }
}
}

void stack_init()
{
t=-1;
}

int empty()
{
return t==-1;
}

void push(int val)
{
 if(is_full())
 {
     t=t+1;
     stack[t]=val;
     printf("True.\n\n");

 }
 else
 {
    printf("False. The stack is full.\n\n");
 }

}

void pop()
{
t=t-1;
}

int top()
{
return stack[t];
}

int is_full()
{
    return t!=size;
}

