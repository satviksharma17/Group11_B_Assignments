#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int *queue;
    int front, rear;
    int size;
} Queue;

void create(Queue *q, int size)
{
    q->queue = (int *)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
}


int is_empty(Queue *q)
{
    return (q->front) == -1;
}

int is_full(Queue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(Queue *q, int value)
{
    //first insertion
    if (is_empty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->queue[0] = value;

        return;
    }

 
    assert(!is_full(q));

    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = value;
}


int dequeue(Queue *q)
{
    //queue is not empty;
    assert(!is_empty(q));

    int temp = q->queue[q->front];

    //resetting queue to empty

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }

    return temp;
}


int peek(Queue *q)
{
    assert(!is_empty(q)); //queue is not empty;

    return q->queue[q->front];
}

typedef struct
{
    Queue q1, q2;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    create(&s->q1, 101);
    create(&s->q2, 101);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x)
{
    enqueue(&obj->q1, x);
}

int myStackPop(MyStack *obj)
{
    while (!is_empty(&obj->q1))
    {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    int toReturn;
    while (!is_empty(&obj->q2))
    {
        toReturn = dequeue(&obj->q2);
        if (is_empty(&obj->q2))
            break;
        enqueue(&obj->q1, toReturn);
    }
    return toReturn;
}

int myStackTop(MyStack *obj)
{
    int toReturn = myStackPop(obj);
    myStackPush(obj, toReturn);
    return toReturn;
}


bool myStackEmpty(MyStack *obj)
{
    return is_empty(&obj->q1);
}

void myStackFree(MyStack *obj)
{
    free(obj->q1.queue);
    free(obj->q2.queue);
    free(obj);
}