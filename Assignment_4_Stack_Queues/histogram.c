// 1257 satvik sharma
#include <assert.h>
#include <stdlib.h>

int *stack;
int size;
int top;

void resize()
{
    size *= 2;
    stack = realloc(stack, size * sizeof(int));
}

void push(int value)
{
    if (top == size)
    {
        resize();
    }

    stack[top++] = value;
}

int pop()
{
    assert(!is_empty()); //if stack is not empty

    return stack[--top];
}


int peek()
{
    assert(!is_empty()); //if stack is not empty

    return stack[top - 1];
}

int is_empty()
{
    return top == 0;
}

void initialize()
{
    size = 1;
    top = 0;
    stack = (int *)malloc(sizeof(int));
}


int largestRectangleArea(int *heights, int heightsSize)
{
    initialize();
    int ans = 0;
    for (int i = 0; i <= heightsSize; i++)
    {
       
        int now = (i == heightsSize) ? 0 : heights[i];

        while (!is_empty() && heights[peek()] >= now)
        {
            int current = pop();
            int right = i - 1;
            int left = is_empty() ? 0 : peek() + 1;
            int bestAnsForCurrent = heights[current] * (right - left + 1);
            if (bestAnsForCurrent > ans)
                ans = bestAnsForCurrent;
        }
        if (i != heightsSize)
            push(i);
    }
    return ans;
}