#include <stdlib.h>
#include <stdio.h>


typedef struct Queue
{
    struct Queue *next;     //pointing next Queue node
    int data;               
} Queue;
//insert node after target
Queue* I_operator(Queue * target,int value);
//delete node (parent of target)
bool D_operator(Queue * target);
Queue * findParent(Queue * target,Queue * head)     //double linked list 가 아니므로 이전 노드를 찾는 함수를 구현
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
Queue * findValue(int value , Queue * head) //특정 값을 가지는 node를 찾는다.
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
Queue * findLast(Queue * head)  //마지막 노드를 찾는 함수
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
        Queue * target = findParent(findedQueue,head);
        D_operator( target);
    }
    else
    {
        printf("wrong input");
        //wrong input
    }
}
//input operator
//target 의 뒤에 value 를 가지는 노드를 넣는다.
Queue* I_operator(Queue * target,int value)
{
    Queue * newQueue = (Queue*)malloc(sizeof(Queue));
    
    newQueue->data = value;
    newQueue->next = target->next;
    target->next = newQueue;
    return newQueue;
}
//target 의 앞에있는(parent) 노드를 제거한다.
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
    Queue * head = (Queue*)malloc(sizeof(Queue));
    head->next = NULL;      //initialize head node ( head node is dummy node in my code )
    
    int inputSize;
    scanf("%d", &inputSize);
    for(int i = 0; i < inputSize; i++)
    {
        //key input
        char OpType;    //operation type ( I , O , P )
        int value;
        
        scanf(" %c",&OpType);
        if(OpType != 'O')   //if Input's operator type is not 'O' , scan value
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

