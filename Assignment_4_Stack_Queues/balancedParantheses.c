#include<stdio.h>

#define SIZE 10

char Stack[SIZE], top=-1;
                                           
int isFull()
{
  return top==(SIZE-1);
}

int isEmpty()
{
  return top==-1;
}

// Function to add an item to stack.  It increases top by 1
void push(char item)
{
  if (isFull())
  {
    printf("OVERFLOW");
    
  }

  Stack[++top] = item;

}

// Function to remove an item from stack.  It decreases top by 1
char pop()
{
  char temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  return temp;
}
int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
int areBrackectsBalanced(char exp[])       
{
    int i=0;
    while(exp[i])
    {
      //  printf("%c ",exp[i]);
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')         // If the exp[i] is a starting bracket then push it
        push(exp[i]);
            
                                                      // If exp[i] is an ending bracket then pop from stack and check if the popped bracket is a  matching pair*/
         if (exp[i] == '}' || exp[i] == ')'
            || exp[i] == ']')                                    
            {
 
            // If we see an ending bracket without a pair
            // then return false
            if (isEmpty())
                return 0;
            else if (!isMatchingPair(pop(), exp[i]))
                return 0;
            }
       i++;
    }
    return 1;
}
int main()
{
  char exp[100] = "{()}[]";
 
    // Function call
    if (areBrackectsBalanced(exp))
        printf("True \n");
    else
        printf("False \n");
    return 0;
}
