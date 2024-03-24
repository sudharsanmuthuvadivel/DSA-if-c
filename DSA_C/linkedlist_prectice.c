// implementation of linked list
#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
};
typedef struct lnode node;
node *head = NULL;

void insert_at_begining(int user_val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    if (Newnode == NULL)
    {
        printf("Out of Memory.\n");
        return;
    }
    Newnode->data = user_val;
    if (head == NULL)
    {
        head = Newnode;
        Newnode->next = NULL;
    }
    else
    {
        Newnode->next = head;
        head = Newnode;
    }
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
void insert_at_spec_pos(int user_pos, int user_val)
{
    node *Newnode = (node *)malloc(sizeof(node));
    if (Newnode == NULL)
    {
        printf("Out of Memory..!\n");
        return;
    }
    Newnode->data = user_val;
    node *temp = head;
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
    temp->next = Newnode;
    printf("%d was inserted at %d position.\n", user_val, user_pos);
}
void delete_at_spec_pos(int user_pos)
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
}
int main()
{
    int choice, countinue, user_val, user_pos;
    do
    {
        printf("\nIMPLEMENTION OF LINKED LIST\n.");
        printf("--------------------------------\n");
        printf("1.Insert at Begining.\n");
        printf("2.Display the list.\n");
        printf("3.Insert at specific postion.\n");
        printf("4.Delete at specific position.\n");
        printf("5.Reversal.\n");
        printf("6.Exit\n");
        printf("----------------------------------\n");
        printf("Enter Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // printf("You select Insert at Begining.");
            printf("Enter the value:");
            scanf("%d", &user_val);
            insert_at_begining(user_val);
            break;
        case 2:
            list_display();
            break;
        case 3:
            printf("Enter the Position (start at 0) :");
            scanf("%d", &user_pos);
            if (user_pos < 0)
            {
                printf("Invalid position.\n");
                return 0;
            }
            printf("Enter the data: ");
            scanf("%d", &user_val);
            if (user_pos == 0)
            {
                insert_at_begining(user_val);
            }
            else
            {
                insert_at_spec_pos(user_pos, user_val);
            }
            break;
        case 4:
            printf("Enter the position: ");
            scanf("%d", &user_pos);
            if (user_pos < 0)
            {
                printf("Invalid position.\n");
                return 0;
            }
            else
                delete_at_spec_pos(user_pos);
            break;
        case 5:
            if (head == NULL)
            {
                printf("List is Empty!\n");
                return 0;
            }
            list_reversal();
            list_display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid option.");
            break;
        }
        printf("Press 0 or 1 to countinue...");
        scanf("%d", &countinue);
    } while (countinue <= 1);
    return 0;
}