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
            int cur = pop();
            int r = i - 1;
            int l = is_empty() ? 0 : peek() + 1;
            int area = heights[cur] * (r - l + 1);
            if (area > ans)
                ans = area;
        }
        if (i != heightsSize)
            push(i);
    }
    return ans;
}