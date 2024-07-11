#include<stdio.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node * head, *tail;

void insertFirst(int num)
{
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->prev = NULL;
    newItem->next = NULL;

    if(head==NULL)
    {
        head=newItem;
        tail=newItem;
    }
    else
    {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
}

void insertTail(int num)
{
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->prev = NULL;
    newItem->next = NULL;

    if(head==NULL)
    {
        head=newItem;
        newItem->prev = NULL;
        newItem->next = NULL;
        tail=head;
    }

    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

                tail->next=newItem;
        newItem->prev=tail;
        tail=newItem;
    }
}

void forward_traversal()
{
    if (head==NULL)
    {
        return;
    }
    struct node *temp =  head;
    while(temp != NULL)
    {
        printf("%d ->",temp->value);
        temp = temp->next;
    }
    printf(" end\n");
}

void backward_traversal()
{
    if (head==NULL)
    {
        return;
    }
    struct node *temp =  tail;
    while(temp != NULL)
    {
        printf("%d ->",temp->value);
        temp = temp->prev;
    }
    printf(" end\n");
}

int main()
{
    head=NULL;
    tail=NULL;
    int num, ch;

    while(1)
    {
        printf("\n01.Insert first :\n02.insert last :\n03.Forward traversal  :\n04.Backword traversal  :\n");
        scanf("%d",&ch);

        if(ch == 1)
        {
            scanf("%d", &num);
            insertFirst(num);
        }
        else if(ch == 2)
        {
            scanf("%d", &num);
            insertTail(num);
        }
        else if(ch == 3)
        {
            forward_traversal();
        }
        else if(ch == 4)
        {
            backward_traversal();
        }
        else
        {
            printf("invalid");
            break;
        }
    }
    return 0;
}
