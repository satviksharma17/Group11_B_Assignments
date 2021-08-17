#include <stdlib.h>

typedef struct
{
    int currentElement;
    int minElement;
} Pair;

typedef struct
{
    Pair *stack;
    int top;
} MinStack;

MinStack *minStackCreate()
{
    MinStack *s = (MinStack *)malloc(sizeof(MinStack));
    s->stack = (Pair *)malloc(sizeof(Pair) * 30001);
    s->top = 0;
    return s;
}

int minStackGetMin(MinStack *obj)
{
    return obj->stack[obj->top - 1].minElement;
}

void minStackPush(MinStack *obj, int val)
{
    Pair toPush = {val, val};

    if (obj->top != 0 && minStackGetMin(obj) < val)
        toPush.minElement = minStackGetMin(obj);

    obj->stack[obj->top++] = toPush;
}

void minStackPop(MinStack *obj)
{
    obj->top--;
}

int minStackTop(MinStack *obj)
{
    return obj->stack[obj->top - 1].currentElement;
}

void minStackFree(MinStack *obj)
{
    free(obj->stack);
    free(obj);
}