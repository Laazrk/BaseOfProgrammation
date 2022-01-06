#include <stdio.h>
#include <stdlib.h>

//------------------ CREATE A STACK -------
typedef struct Stack{
    int *item;
    int size;
    int top;

}Stack;

//----------- DECLARATION OF FUNC -----
void init(Stack*,int);
void push(Stack*,int);
int pop(Stack*);
void print(Stack*);

//-------DECLARATION ----------
void init(Stack *stck,int size){
    stck->top = -1;
    stck->item = (int*)malloc(sizeof(int)*size);
    stck->size = size;
}
//------ PUSH -------
void push(Stack *stck, int data){
    if(stck->top == stck->size-1){
        printf("STACK OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    stck->top++;
    stck->item[stck->top] = data;
    return;

}
//------ POP ---------
int pop(Stack *stck){
    if(stck->top == -1)
    {
        printf("STACK UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    int value;
    value = stck->item;
    stck->top--;
    return value;

}
//-------- PRINT LIST -----------
void print(Stack *stck){
    for(int i = 0; i <stck->size;i++)
    {
        printf(" %d ",stck->item[i]);
    }
    return;
}
int main()
{
    Stack s1;
    init(&s1,3);
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    print(&s1);
    int value;
    value = pop(&s1);
    print(&s1);


    return 0;
}
