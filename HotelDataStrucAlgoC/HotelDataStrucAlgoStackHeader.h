#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure definition
struct stackNode{
    // string member as per requirements
    char guestId[10];
    // int member as per requirements
    int roomNumber;
    float roomPrice;
    char guestName[20];
    // char member as per requirements
    char guestGender;
    char guestEmail[50];
    struct stackNode *nextPtr;
};

// Type renaming using typedef
typedef struct stackNode StackNode;
typedef struct stackNode *StackNodePtr;

/* Function Protypes */
StackNodePtr push(StackNodePtr topPtr, char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50]);
StackNodePtr pop(StackNodePtr topPtr, char guestId[10]);
int isEmpty(StackNodePtr topPtr);
void topOfStack(StackNodePtr topPtr);
void bottomOfStack(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);
// function prototype for finding guest
int findGuest(StackNodePtr topPtr, char guestId[10]);


// function for findGuest
int findGuest(StackNodePtr topPtr, char guestId[10])
{
    StackNodePtr currentPtr = topPtr;
    int index = 0;
    while (currentPtr != NULL) {
        if (strcmp(currentPtr->guestId, guestId) == 0) {
            return index;
        }
        currentPtr = currentPtr->nextPtr;
        index++;
    }
    return -1;
}

/*.......Function Definitions .....*/
StackNodePtr push(StackNodePtr topPtr, char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50]) {
	StackNodePtr newPtr;// Initialise pointer for new StackNode
    
    // Check if the guestId already exists in the list
    // if it does then return topPtr;
    if (findGuest(topPtr, guestId) != -1)
    {
        printf("\nGuestId already exists...Please Try Again.\n\n");
        return topPtr;
    }
    
	newPtr = malloc(sizeof(StackNode));// Create memory for new StackNode
	
        // Push new StackNode onto top-of-stack
	if(newPtr != NULL) {
	    // add code to push
        strcpy(newPtr->guestId, guestId);
        newPtr->roomNumber = roomNumber;
        newPtr->roomPrice = roomPrice;
        strcpy(newPtr->guestName, guestName);
        // only need one character
        strncpy(&newPtr->guestGender, &guestGender, 1);
        strcpy(newPtr->guestEmail, guestEmail);
        
	    newPtr->nextPtr = topPtr;
	    topPtr = newPtr;
        } else {
		printf("\n%s not inserted. No memory available.\n", guestId);
	}
        return topPtr; // return pointer to top-of-stack;
}

StackNodePtr pop(StackNodePtr topPtr, char guestId[10]) {
	// Initialise temporary pointer to hold address of StackNode to pop
	StackNodePtr tempPtr;
    char popValue[50];
        /* add code to pop StackNode from the top-of-stack */
        tempPtr = topPtr;            // isolate StackNode to be deleted / popped
    //strcpy(tempPtr->guestId, guestId);    // inform user of Node to be popped

    //strcpy(popValue, tempPtr);
        printf("%s is being removed...\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n", tempPtr->guestId, tempPtr->guestId, tempPtr->roomNumber, tempPtr->roomPrice, tempPtr->guestName, tempPtr->guestGender, tempPtr->guestEmail);
	topPtr = topPtr->nextPtr;    // update topPtr 
        free(tempPtr);// deallocate memory
        
	return topPtr; // return pointer to top-of-stack
}

void printStack(StackNodePtr topPtr) {
        StackNodePtr currentPtr = topPtr;
	if(currentPtr == NULL) { /*stack is empty*/
		puts ("\nThe stack is empty\n");
	} else {
		printf("\nThe stack is:\n");
		while(currentPtr != NULL) { /*not at the end of stack*/
            printf("Guest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n-->",currentPtr->guestId, currentPtr->roomNumber, currentPtr->roomPrice, currentPtr->guestName, currentPtr->guestGender, currentPtr->guestEmail); // print current node
			currentPtr = currentPtr->nextPtr; // move onto the next node
		}
		printf("NULL\n\n");
	}
}

int isEmpty(StackNodePtr topPtr) {
    // return true if topPtr is NULL of False otherwise;
    return topPtr == NULL;
}

void topOfStack(StackNodePtr topPtr)
{
   // display value at the top-of-stack
   printf("\nThe value at the top-of-stack is \nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n-->", topPtr->guestId, topPtr->roomNumber, topPtr->roomPrice, topPtr->guestName, topPtr->guestGender, topPtr->guestEmail);
}

void bottomOfStack(StackNodePtr topPtr)
{
   StackNodePtr previousPtr = NULL, currentPtr = topPtr;
   // display value at the bottom-of-stack
   while(currentPtr != NULL)
   {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
   }
   printf("\nThe value at the bottom-of-stack is \nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n", previousPtr->guestId, previousPtr->roomNumber, previousPtr->roomPrice, previousPtr->guestName, previousPtr->guestGender, previousPtr->guestEmail);
   
}

void instructions(void) {
	printf("Enter choice:\n1) Top of Stack\n2) Bottom of stack\n3) Push\n4) Pop\n5) Print all the data items\n6) Exit Stack Application\n");
}

