// Operating and maintaining a queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode {  // Structure definition
    // string member as per requirements
    char guestId[10];
    // int member as per requirements
    int roomNumber;
    float roomPrice;
    char guestName[20];
    // char member as per requirements
    char guestGender;
    char guestEmail[50];
    struct queueNode *nextPtr; // queueNode pointer
};  // end structure queueNode

// Use typedef to rename types
typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

// function prototypes
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50]);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char guestId[10]);
int isEmptyQueue(QueueNodePtr *headPtr);
void printQueue(QueueNodePtr headPtr);
void front(QueueNodePtr headPtr);
void back(QueueNodePtr tailPtr);
void instructionsQueues(void);

/*Function Definitions*/

// insert a node in at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50])
{ 
   // Declare pointer to store address of new QueueNode
    QueueNodePtr newPtr;
    
    // Check if the guestId already exists in the list
    QueueNodePtr currentPtr;
    currentPtr = *headPtr;
    while (currentPtr != NULL) {
            if (strcmp(currentPtr->guestId, guestId) == 0) {
                printf("\nGuestId already exists...Please Try Again.\n\n");
                // no need to return number since its a void function
                return;
            } 
            currentPtr = currentPtr->nextPtr;
    }
    
   // Create memory for new QueueNode
    newPtr = malloc(sizeof(QueueNode));
   // if is space available
    if (newPtr != NULL)
    {
        // load data into new node
        strcpy(newPtr->guestId, guestId);
        newPtr->roomNumber = roomNumber;
        newPtr->roomPrice = roomPrice;
        strcpy(newPtr->guestName, guestName);
        // only need one character
        strncpy(&newPtr->guestGender, &guestGender, 1);
        strcpy(newPtr->guestEmail, guestEmail);
        
        newPtr->nextPtr = NULL;
        // if queue is empty, insert node at head
        if (*headPtr == NULL)
        {
            // add code to insert node at the head
            *headPtr = newPtr;
        }
        else
        {
            // otherwise insert at the tail
            // add code to insert node at the tail
            (*tailPtr)->nextPtr = newPtr;
        }
        // update tailPtr ... this is always done
        *tailPtr = newPtr;
    }
    else
    {
        printf("\n%s not inserted. No memory available.\n", guestId);
    }
}


// remove node from queue head
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char guestId[10])
{ 
   // Declare temporary node pointer to isolate node to be deleted
    QueueNodePtr tempPtr;
    //char dequeueValue[50];

   // store headPtr into tempPtr
    tempPtr = *headPtr;
    

   // inform user  or return value;
    //strcpy(tempPtr->guestId, guestId);
    
    //strcpy(dequeueValue, tempPtr);
    //printf("%s is being deleted\n", tempPtr->guestId);
    printf("%s is being deleted\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n", tempPtr->guestId, tempPtr->guestId, tempPtr->roomNumber, tempPtr->roomPrice, tempPtr->guestName, tempPtr->guestGender, tempPtr->guestEmail);


   // update headPtr
    *headPtr = (*headPtr)->nextPtr;
   // if queue is empty, update tailPtr
    if(*headPtr == NULL)
    {
        // add code to update tailPtr
        *tailPtr = NULL;
    }
   // de-allocate memory from tempPtr
    free(tempPtr);
}

// return 1 if the queue is empty, 0 otherwise
int isEmptyQueue(QueueNodePtr *headPtr)
{
   //return queue is empty if headPtr == NULL
    return headPtr == NULL;
} 


// print the queue
void printQueue( QueueNodePtr headPtr )
{ 
   // set currentPtr to head of queue
    QueueNodePtr currentPtr = headPtr;
   // if queue is empty
   if ( currentPtr == NULL ) {
      puts( "\n Queue is empty.\n" );
   } // end if
   else { 
      puts( "The queue is:" );

      // while not end of queue
      while ( currentPtr != NULL ) { 

          printf("Guest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",currentPtr->guestId, currentPtr->roomNumber, currentPtr->roomPrice, currentPtr->guestName, currentPtr->guestGender, currentPtr->guestEmail);
         currentPtr = currentPtr->nextPtr;
      } // end while
 
      puts( "NULL\n" );
   } // end else
} // end function printQueue

void front(QueueNodePtr headPtr)
{
    printf("\nThe front of the queue is:\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",headPtr->guestId, headPtr->roomNumber, headPtr->roomPrice, headPtr->guestName, headPtr->guestGender, headPtr->guestEmail);
}

void back(QueueNodePtr tailPtr)
{
    printf("\nThe back of the queue is:\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",tailPtr->guestId, tailPtr->roomNumber, tailPtr->roomPrice, tailPtr->guestName, tailPtr->guestGender, tailPtr->guestEmail);
}

// display program instructions to user
void instructionsQueues( void )
{ 
   printf ( "Enter your choice:\n"
           "   1) Front of Queue\n"
           "   2) Back of Queue\n"
           "   3) Enqueue\n"
           "   4) Dequeue\n"
           "   5) Print Items in Queue\n"
           "   6) Exit Queue operations\n"
           );
} // end function instructions



