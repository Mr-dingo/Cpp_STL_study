#include <stdlib.h>
#include <stdio.h>


typedef struct Queue
{
    struct Queue *next;
    int data;
} Queue;

Queue* I_operator(Queue * target,int value);
bool D_operator(Queue * target);
Queue * findChild(Queue * target,Queue * head)
{
    Queue * resultQ;
    if(head->next == NULL)
        return NULL;
    for(resultQ = head->next; resultQ ; resultQ = resultQ->next)
    {
        if(resultQ->next == target)
        {
            return resultQ;
        }
    }
    return resultQ;
}
Queue * findValue(int value , Queue * head)
{
    Queue * resultQ;
    if(head->next == NULL)
        return NULL;
    for(resultQ = head->next; resultQ ; resultQ = resultQ->next)
    {
        if(resultQ->data == value)
        {
            return resultQ;
        }
    }
    return resultQ;
}
Queue * findLast(Queue * head)
{
    Queue * resultQ = head;
    if(head->next == NULL)
        return resultQ;
    for(resultQ = head->next; resultQ->next ; resultQ = resultQ->next)
    {
    }
    return resultQ;
}
void doOperation(char OpType,int value,Queue * head)
{
    if(OpType == 'O')
    {
        D_operator(head);
    }
    else if(OpType == 'I')
    {
        Queue * last = findLast(head);
        I_operator(last,value);
    }
    else if(OpType == 'P')
    {
        Queue * findedQueue = findValue(value,head) ;
        Queue * target = findChild(findedQueue,head);
        D_operator( target);
    }
    else
    {
        printf("wrong input");
        //wrong input
    }
}
void initHead(Queue * head)
{
    head = (Queue*)malloc(sizeof(Queue));
    head->next = NULL;
}
Queue* I_operator(Queue * target,int value)
{
    Queue * newQueue = (Queue*)malloc(sizeof(Queue));
    
    newQueue->data = value;
    newQueue->next = target->next;
    target->next = newQueue;
    return newQueue;
}
bool D_operator(Queue * target)
{
    if(target == NULL)
        return false;
    Queue * del = target->next;
    if(del == NULL)
    {
        return false;
    }
    printf("%d\n",del->data);
    target->next = del->next;
    free(del);
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    Queue * arrayQ = (Queue*)malloc(sizeof(Queue) * 100);
    Queue * head = (Queue*)malloc(sizeof(Queue));
    head->next = NULL;
    arrayQ[0];
    arrayQ[1];
    
    int inputSize;
    scanf("%d", &inputSize);
    for(int i = 0; i < inputSize; i++)
    {
        //key input
        
        char OpType;
        int value;
        
        scanf(" %c",&OpType);
        if(OpType != 'O')
        {
            scanf("%d",&value);
        }
        
        doOperation(OpType,value , head);
        
    }
    for(Queue * curQ = head->next; curQ; curQ = curQ->next)
    {
        printf("%d ",curQ->data);
    }
    
    return 0;
}

