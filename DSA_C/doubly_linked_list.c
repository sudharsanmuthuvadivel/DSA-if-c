// implementation of linked list
#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *prev;
    struct lnode *next;
};
typedef struct lnode node;
node *head = NULL;
node *tail = NULL;

void insert_at_begining(int user_val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    if (Newnode == NULL)
    {
        printf("Out of Memory.\n");
        return;
    }
    Newnode->data = user_val;
    Newnode->prev = NULL;
    Newnode->next = NULL;
    if (head == NULL)//only one
    {
        
        tail = Newnode;
    }
    else// already one
    {
        Newnode->next = head;
        head->prev = Newnode;
    }
        head = Newnode;
        
    printf("%d Inserted at begining succussfully.\n", user_val);
}
void list_display()
{
    if (head == NULL)
    {
        printf("List is Empty..!\n");
        return;
    }
    node *temp = head;
    printf("Data in the List are:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void list_rev_display()
{
    if (tail == NULL)
    {
        printf("List is Empty..!\n");
        return;
    }
    node *temp = tail;
    printf("Data in the List are(reverse):\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void insert_at_spec_pos(int user_pos, int user_val)
{
    if (user_pos == 0){
        insert_at_begining(user_val);
        return;
    }
    node *Newnode = (node *)malloc(sizeof(node));
    if (Newnode == NULL)
    {
        printf("Out of Memory..!\n");
        return;
    }
    Newnode->data = user_val;
    node* temp = head;
    
    for (int i = 0; i < user_pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    Newnode->next = temp->next;
    temp->next->prev = Newnode;
    temp->next = Newnode;
    Newnode->prev = temp;
    printf("%d was inserted at %d position.\n", user_val, user_pos);
}
/*void delete_at_spec_pos(int user_pos)
{
    node *prev = NULL;
    node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty!");
        return;
    }
    if (user_pos == 0)
    {
        head = head->next;
        printf("%d was deleted at the position of %d.\n", temp->data, user_pos);
        free(temp);
        return;
    }
    for (int i = 0; i < user_pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position !\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("%d was deleted at %d position.\n", temp->data, user_pos);
    free(temp);
}
void list_reversal()
{

    node *prev = NULL;
    node *current = head;
    node *next = head->next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
} */
int main()
{
    insert_at_begining(3);
    insert_at_begining(2);
    insert_at_begining(1);
    list_display();
    insert_at_spec_pos(3, 4);
    list_display();
    list_rev_display();
    return 0;
}