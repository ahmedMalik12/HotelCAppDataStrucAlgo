// Binary Tree Header

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
/* TreeNode structure definition */
struct treeNode {
    // pointer to left subtree
    struct treeNode *leftPtr;
    // pointer to right subtree
    struct treeNode *rightPtr;
    // string member as per requirements
    char guestId[10];
    // int member as per requirements
    int roomNumber;
    float roomPrice;
    char guestName[20];
    // char member as per requirements
    char guestGender;
    char guestEmail[50];
    
    /* end struct TreeNode */
};
/* Create Aliases for the TreeNode */
typedef struct treeNode TreeNode;
//typedef struct treeNode *TreeNodePtr;
typedef TreeNode *TreeNodePtr;

/* function prototypes */
void insertNode(TreeNodePtr *treePtr,  char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50]);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void deleteNode( TreeNodePtr *treePtr, char guestId[10]);
void searchNode ( TreeNodePtr *treePtr, char guestId[10], TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found );
void instructionsTrees(void);


/*********Function Definitions**********/

/* insert a node into the tree */
void insertNode(TreeNodePtr *treePtr, char guestId[10], int roomNumber, float roomPrice, char guestName[20], char guestGender, char guestEmail[50])
{
    /* insert here as a leaf node*/
    if (*treePtr == NULL)
    {
        
        /* dynamically allocate memory */
        *treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));
        if (*treePtr != NULL)	/* if memory was allocated, insert node */  {
            // add code to insert data into node
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
            strcpy((*treePtr)->guestId, guestId);
            (*treePtr)->roomNumber = roomNumber;
            (*treePtr)->roomPrice = roomPrice;
            strcpy((*treePtr)->guestName, guestName);
            // only need one character
            strncpy(&(*treePtr)->guestGender, &guestGender, 1);
            strcpy((*treePtr)->guestEmail, guestEmail);
            printf("\nGuest ID: %s was inserted successfully.\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n\n", (*treePtr)->guestId, (*treePtr)->guestId, (*treePtr)->roomNumber, (*treePtr)->roomPrice, (*treePtr)->guestName, (*treePtr)->guestGender, (*treePtr)->guestEmail);
            
        }
        else {
            printf("\nGuest ID: %s not inserted... No memory available.\n", guestId);
        }
        return;
    }
    
    /*otherwise if treePtr is-not NULL, recursively call insertNode */
    else
    {
        /* insert node in left subtree */
        if (strcmp(guestId, (*treePtr)->guestId) < 0) {
            // add code here to go left
            insertNode(&((*treePtr)->leftPtr), guestId, roomNumber, roomPrice, guestName, guestGender, guestEmail);
        }
        /* insert into right subtree*/
        else if (strcmp(guestId, (*treePtr)->guestId) > 0){
            // add code here to go right
            insertNode(&((*treePtr)->rightPtr), guestId, roomNumber, roomPrice, guestName, guestGender, guestEmail);
        }
        else { // duplicate value will be eliminated
            puts("\nGuestId already exists...Please Try Again.\n-duplicate-not-inserted\n\n");
        }
    } // end of else
} // end of function

/* traverse the tree inorder */
void inOrder(TreeNodePtr treePtr)
{
    /* traverse left subtree, print node, traverse right subtree */
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("Guest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",treePtr->guestId, treePtr->roomNumber, treePtr->roomPrice, treePtr->guestName, treePtr->guestGender, treePtr->guestEmail);
        inOrder(treePtr->rightPtr);
    }
} 

/* traverse the tree preorder */
void preOrder(TreeNodePtr treePtr)
{
    /* print node, traverse left subtree, traverse right subtree */
    if(treePtr != NULL)
    {
        printf("Guest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",treePtr->guestId, treePtr->roomNumber, treePtr->roomPrice, treePtr->guestName, treePtr->guestGender, treePtr->guestEmail);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
} 

/* traverse the tree postorder */
void postOrder(TreeNodePtr treePtr)
{
    /* traverse left subtree, traverse right subtree, print node */
    if(treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("Guest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n --> ",treePtr->guestId, treePtr->roomNumber, treePtr->roomPrice, treePtr->guestName, treePtr->guestGender, treePtr->guestEmail);
    }
}


void deleteNode(TreeNodePtr *treePtr, char guestId[10]) {
    int found;
    TreeNodePtr parentPtr = NULL, tempNodePtr = NULL, replacementNodePtr = NULL;
    
    // if tree is empty
    if (*treePtr == NULL) {
        printf("\nTree is Empty\n");
        return;
    }
    
    // find the node to be deleted
    searchNode(treePtr, guestId, &parentPtr, &tempNodePtr, &found);
    
    // if the node is not found
    if (found == FALSE) {
        printf("\nThe Data was not found\n");
        return;
    }
    
    // if the node to be deleted has no child
    if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr == NULL) {
        if (parentPtr != NULL) {
            if (parentPtr->rightPtr == tempNodePtr) {
                parentPtr->rightPtr = NULL;
            } else {
                parentPtr->leftPtr = NULL;
            }
        } else {
            *treePtr = NULL; // the node to be deleted is the root
        }
        free(tempNodePtr);
        return;
    }
    
    // if the node to be deleted has only right child
    if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr != NULL) {
        if (parentPtr != NULL) {
            if (parentPtr->leftPtr == tempNodePtr) {
                parentPtr->leftPtr = tempNodePtr->rightPtr;
            } else {
                parentPtr->rightPtr = tempNodePtr->rightPtr;
            }
        } else {
            *treePtr = tempNodePtr->rightPtr; // the node to be deleted is the root
        }
        free(tempNodePtr);
        return;
    }
    
    // if the node to be deleted has only left child
    if (tempNodePtr->leftPtr != NULL && tempNodePtr->rightPtr == NULL) {
        if (parentPtr != NULL) {
            if (parentPtr->leftPtr == tempNodePtr) {
                parentPtr->leftPtr = tempNodePtr->leftPtr;
            } else {
                parentPtr->rightPtr = tempNodePtr->leftPtr;
            }
        } else {
            *treePtr = tempNodePtr->leftPtr; // the node to be deleted is the root
        }
        free(tempNodePtr);
        return;
    }
    
    // if the node to be deleted has two children
    parentPtr = tempNodePtr;
    replacementNodePtr = tempNodePtr->rightPtr;
    
    while (replacementNodePtr->leftPtr != NULL) {
        parentPtr = replacementNodePtr;
        replacementNodePtr = replacementNodePtr->leftPtr;
    }
    
    strcpy(tempNodePtr->guestId, replacementNodePtr->guestId);
    tempNodePtr = replacementNodePtr;
    deleteNode(&parentPtr->rightPtr, tempNodePtr->guestId);
    
    // Re-link the parent of the replacement node to its right child
    if (parentPtr == tempNodePtr) {
        parentPtr->rightPtr = replacementNodePtr->rightPtr;
    } else {
        parentPtr->leftPtr = replacementNodePtr->rightPtr;
    }

    // Free the memory occupied by the replacement node
    free(replacementNodePtr);
}

void searchNode ( TreeNodePtr *treePtr, char guestId[10], TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found )
{
    
    TreeNodePtr tempPtr ;
    tempPtr = *treePtr ;
    *found = FALSE ;
    *parentPtr = NULL ;
    
    while ( tempPtr != NULL )
    {
        //if ( tempPtr -> guestId == guestId )
        if (strcmp(tempPtr ->guestId, guestId) == 0)
            //if ( tempPtr -> guestId == value )
        {
            *found = TRUE ;
            *tempNodePtr = tempPtr ;
            printf("\nGuest ID: %s was deleted.\nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n", tempPtr->guestId, tempPtr->guestId, tempPtr->roomNumber, tempPtr->roomPrice, tempPtr->guestName, tempPtr->guestGender, tempPtr->guestEmail);
            return ;
        }
        
        *parentPtr = tempPtr ;
        //if (tempPtr -> guestId > guestId )
        if (strcmp(tempPtr ->guestId, guestId) > 0)
            //if ( tempPtr ->guestId > value)
            
        {
            tempPtr = tempPtr -> leftPtr ;
        }
        else
        {
            tempPtr = tempPtr -> rightPtr ;
        }
    }
}

// display program instructions to user
void instructionsTrees( void )
{
    printf ( "Enter your choice:\n"
            "   1) Insert into Tree\n"
            "   2) Remove from Tree\n"
            "   3) Binary Search of the Tree for a specific data item\n"
            "   4) Pre-order Traversal of Tree\n"
            "   5) Post-order Traversal of Tree\n"
            "   6) In-order Traversal of Tree\n"
            "   7) Exit Tree Operations\n"
            );
} // end function instructions
