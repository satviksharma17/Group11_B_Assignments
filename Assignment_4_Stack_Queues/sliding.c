#include <assert.h>
#include <assert.h>

int *deque;
int front = -1, rear = -1;
int size;

int is_empty()
{
    return front == -1;
}

int is_Full()
{
    return ((front == 0 && rear == size - 1) ||
            front == rear + 1);
}


void pushBack(int value)
{
    assert(!is_Full());

    //first insertion
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % size;

    deque[rear] = value;
}

void pushFront(int value)
{
    assert(!is_Full());

    //first insertion
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        front = front - 1;

    if (front < 0)
        front = size - 1;

    deque[front] = value;
}

int popFront()
{
    //deque is not empty;
    assert(!is_empty());

    int temp = deque[front];

    //resetting deque to empty
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return temp;
}

int popBack()
{
   
    assert(!is_empty());

    int temp = deque[rear];


    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear--;
    }
    if (rear < 0)
        rear = size - 1;

    return temp;
}
int Front()
{
    assert(!is_empty()); //deque is not empty;

    return deque[front];
}

int Back()
{
    assert(!is_empty() && rear >= 0); //deque is not empty;

    return deque[rear];
}

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    size = k;
    front = rear = -1;
    deque = (int *)malloc(sizeof(int) * k);
    int *ans = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++)
    {
        //removing indices out of current window
        while (!is_empty() && Front() <= (i - k))
            popFront();

        //removing the smaller elements than this element in window
        while (!is_empty() && nums[i] >= nums[Back()])
            popBack();

        //pushing the new index
        pushBack(i);

        //if we have processed k elements till now
        if (i >= (k - 1))
            ans[i - (k - 1)] = nums[Front()];
    }

    return ans;
}