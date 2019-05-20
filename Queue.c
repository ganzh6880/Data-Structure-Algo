#include<stdio.h>
#define size 5

int queue[size];
int val,i,r,f;
void queue_init();
int empty();
void enqueue(val);
void dequeue();
int front();

int main(void)
{
 queue_init();
 for(i=0;i<=20;i++)
 {
    printf("Please input your value = ");
    scanf("%d",&val);
    printf("\n");
    switch(val){
    case -1:
     {
         if(empty() == 1)
            printf("Error - Queue is empty.\n\n");
         else
         printf("%d\n\n",front());
         printf("%d\n\n",rear());
         break;
     }

     case 0:
     {
        if(empty() == 1)
            printf("Error - Queue is empty.\n\n");
        else
        dequeue();
        break;
     }

     default:
    {
        enqueue(val);
        break;
    }
 }
}
}

void queue_init()
{
r=f=-1;
}

int empty()
{
return f==r&&queue[r]==0;
}

void enqueue(int val)
{
if(empty())
r=f=0;
else
{
if(f==r&&queue[r]!=0)
{
    printf("FULL.\n\n");
}
else
   {
   r=r+1;
    if(r==size-1)
    r=0;
    queue[r]=val;
   }
}

}

void dequeue()
{
f=f+1;
if(f==size-1)
f=0;
}

int front()
{
return queue[f];
}

int rear()
{
return queue[r];
}

