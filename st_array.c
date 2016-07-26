#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack{
  int top;
  int capacity;
  int *array;    
}stack;

stack* createStack(int capacity){
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    st->capacity = capacity;
    st->array = (int *)malloc(capacity * sizeof(int));
    
    return st;
}
int isEmpty(stack *st){
    return (st->top == -1) ? 1 : 0;
}
int isFull(stack *st){
    return (st->capacity-1 == st->top) ? 1 : 0;
}
void push(stack *st, int data){
    if(isFull(st))
        return;
    st->array[++(st->top)] = data;
    printf("%d pushed\r\n",data);
}
int pop(stack *st){
    if(isEmpty(st))
        return INT_MIN;
    return st->array[(st->top)--];    
}
int peek(stack *st){
    if(isEmpty(st))
        return INT_MIN;
    return st->array[st->top];
    
}
int main()
{
    stack *st = NULL;
    int capacity = 10;
    st = createStack(capacity);
    push(st, 10);
    push(st, 20);
    push(st, 30);
 
    printf("%d popped from stack\n", pop(st));
    push(st, 60);
    printf("Top item is %d\n", peek(st));
    if(st != NULL){
        free(st);
        st = NULL;
    }
    return 0;
}
