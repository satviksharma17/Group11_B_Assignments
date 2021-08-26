#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert();  
void delete();  
void display();  
void peek();
void isEmpty();
int menu()
{
 int ch;
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Peek\n5.isEmpty\n6.exit");  
        printf("\nEnter your choice ?");  
 scanf("%d",&ch);
 system("clear");
 return ch;

}
void main ()  
{  
     printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
    int choice;   
    while(1)   
    {     
      
        switch(menu())  
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            delete();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:
            peek();
            break;
            case 5:  
            isEmpty();  
            break;
            case 6:  
            exit(0);  
            break;
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
void isEmpty()
{
    if(front==NULL)
    printf("Yes Queue is empty");
    else
    printf("Queue is not empty");
}
void peek()
{
     struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    } 
    else
     {   printf("\nPrinting peek .....\n");  
     
            printf("\n%d\n",ptr -> data);  
            
    }  
    
}