#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Head of linked list, or first node
struct Node* head;

// Function declarations
void InsertAtStart(int data);
void InsertAtEnd(int data);
void InsertAtN(int data, int n);
void DeleteAtN(int n);
void Print();
void PrintValueWithAddress();
void ReverseListWithIteration();
void ReverseListWithRecursion(struct Node* p);

// Use main() to do testing
int main()
{
    // Do not remove this line
    head = NULL; // list is empty

    return 0;
}

void InsertAtStart(int data)
{
    // Create new node and allocate the required memory
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // Set data and next fields
    temp->data = data;
    // Since the node we inserted will be replacing the current head, the ->next can point to that head
    temp->next = head;
    // The head node is now our newly created node
    head = temp;
}

void InsertAtN(int data, int n)
{
    int i;

    // Create new node in the heap and set initial value of next to null, which means it points to nothing at the moment
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    // if user wants to insert node at head position of linked list
    // We use a 1 based index system
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    // Pointing to n - 1 node
    // Will need this node to fix next variable as it will need to point to our newly created node and not the 
    // previous next node
    struct Node* temp2 = head;
    for (i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    // Temp1 is our newly created node, we adjust the next field to point to the node that temp2 was previously pointing to
    // Also adjust the pointer of the temp2 node to point to our newly created node
    // These 2 lines taxe care of all the link adjustments needed for adding a new node at n position
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void InsertAtEnd(int data)
{
    // Create new node, allocate memory in the heap, and set data and next properties
    // next is set to null since it is now the last element in the list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Fix link of previous tail node
    struct Node* tail = head;
    // While loop will traverse the list until it reaches the last node, where next = NULL
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Change next field of previous tail to point to new tail
    tail->next = newNode;
}

void Print()
{
    struct Node* temp = head;
    printf("\n");
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        // Use the ->next to get to the next node in the list
        temp = temp->next;
    }
    printf("\n");
}

void PrintValueWithAddress()
{
    struct Node* temp = head;
    printf("\n");
    while (temp != NULL)
    {
        // Print data of node, address of node, and the address that the node points to
        // Use this to confirm links are working
        printf("List item: %d has an address of %p and points to %p\n", temp->data, temp ,temp->next);
        // Follow links to move to next node in list
        temp = temp->next;
    }
    printf("\n");
}

void DeleteAtN(int n)
{
    struct Node* temp1 = head;
    // If user wants to delete the first node from the list
    if (n == 1)
    {
        // Since the head is being deleted, we set the new value of head to the node that head was originally pointing to
        head = temp1->next;
        // Remove temp1 from the stack
        free(temp1);
        // Return out of the function
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next; // nth node
    temp1->next = temp2->next; // n+1 node
    // Deletes temp2 node from memory
    free(temp2);
}

void ReverseListWithIteration()
{
    struct Node *current, *prev, *next;
    // Current is set to head as we will loop through the list starting at the first node
    current = head;
    // Initially set to NULL as the head node doesn't have a previous node it comes after
    prev = NULL;

    while (current != NULL)
    {
        // Store address of next node in variable, since breaking the links will cause it to be inaccessible
        next = current->next;
        // Current node now points to previous node
        current->next = prev;
        // Move previous to current and current to next
        prev = current;
        current = next;
    }
    // This code is run when current == NULL, or when the last node in the list is reached
    // We set this to the new head of the list
    head = prev;
}

void ReverseListWithRecursion(struct Node* p)
{
    // Exit condition
    if (p->next == NULL)
    {
        // Set the head to point to p, which is the last node in the list since its next field is equal to NULL
        head = p;
        return;
    }
    // Recursive call passing the pointer to the next node as an argument
    ReverseListWithRecursion(p->next);
    // Represent the node that p points to (p->next)
    struct Node* q = p->next;
    // since were reversing the list, we have to fix the links so that q->next points to p and not the other way around
    q->next = p;
    // Set p->next to NULL for a moment, will be fixed after recurvive calls are over and begin to fall back
    p->next = NULL;
}
