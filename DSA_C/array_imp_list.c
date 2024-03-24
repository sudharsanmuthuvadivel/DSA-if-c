/*Array implementation of list*/
#include <stdio.h>
#include<stdlib.h>
#define Maxsize 50
int arr[Maxsize];
int size = 0;

void display()
{
    int i;
    if (size == 0)
        printf("List is empty.");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
void insertAtPos(int pos, int val)
{
    int i;
    for (i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    size++;
    printf("Inserted %d at position %d ", val, pos);
}
void deleteFromPos(int pos)
{
    int i;
    int del = arr[pos];
    for (i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Deleted %d at pos %d", del, pos);
}
int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\n------------List Menu---------\n");
        printf("1.Insert at end \n");
        printf("2.Insert at spec Pos \n");
        printf("3.Delete at spec pos \n");
        printf("4.Display \n");
        printf("5.Exit \n");
        printf("\n-------------------------------\n");
        printf("Enter the choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Insert at end
            if (size == Maxsize)
                printf("list if full");
            else
                {printf("Enter the value:");
                scanf("%d", &val);
                arr[size++] = val; // 1st store the value at arr[size] then size++ will increment
                }
            break;
        case 2:
            if (size == Maxsize)
                printf("list if full");
            else
                {
                    printf("Enter the position(pos start at 0): ");
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= size)
                        printf("Invalid position\n");
                    else
                    {
                        printf("Enter the Data:");
                        scanf("%d", &val);
                        insertAtPos(pos, val);
                    }
                }
            break;
        case 3:
            if (size == 0)
                printf("List is empty");
            else
                {
                    printf("Enter the position(pos start at 0):");
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= size)
                        printf("Invalid position\n");
                    else
                        deleteFromPos(pos);
                }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong choice.");
            break;
        }
    }
    return 0;
}