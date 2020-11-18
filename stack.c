#include <stdio.h>
#include <stdlib.h>

// Will represent elements in the stack
struct Node
{
    int data;
    struct Node* next;
};

// Pointer to top node in stack
struct Node* top;

// Function declarations
void Pop(); // Removes element from top of stack
void Push(); // Adds element to top of stack
int Top(); // returns the top element from the stack
int IsEmpty(); // Returns true if stack is empty, false if it is not (0 = false, 1 = true)

int main()
{
    // Stack is empty
    top = NULL;

    // Check if stack is empty
    int isEmpty;
    isEmpty = IsEmpty();
    printf("%d\n", isEmpty); // Returns 1 meaning stack is empty

    // Push element to stack
    Push(7);

    // Check if stack is empty
    isEmpty = IsEmpty();
    printf("%d\n", isEmpty); // Stack is no longer empty so returns 0

    // Push another element
    Push(12);

    // Grab top element
    int topElement;
    topElement = Top();
    printf("Top element is %d\n", topElement);

    // Remove top element
    Pop();

    // Check to see if Pop() worked
    topElement = Top();
    printf("New top element is %d\n", topElement);

    // Remove final element in stack and see if IsEmpty returns true like it should
    Pop();
    isEmpty = IsEmpty();
    printf("%d\n", isEmpty);

    // Try to get the top element when it doesn't exist
    topElement = Top();
    if (topElement == 0)
    {
        printf("Top element is NULL\n");
    }
    else
    {
        printf("Top element is %d\n", topElement);
    }

    // One more test
    Push(89);
    isEmpty = IsEmpty();
    topElement = Top();
    printf("IsEmpty() returned %d and top element is %d\n", isEmpty, topElement);

    return 0;
}

void Push(int data)
{
    // Create node and allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and next values for our newNode
    newNode->data = data;
    // Points to previous top node
    newNode->next = top;

    // This node is now at the top of the stack
    top = newNode;
}

void Pop()
{
    // Create pointer to top node
    struct Node* topNode = top;
    // Set new top node to the node that top pointed to
    top = topNode->next;
    // Remove topNode from memory
    free(topNode);
}

int Top()
{
    // top = NULL would mean stack is empty
    if (top != NULL)
    {
        // Create pointer to top node and return its data
        struct Node* topNode = top;
        return topNode->data;
    }
    // Stack is empty
    else
    {
        return 0;
    }
    

}

int IsEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}