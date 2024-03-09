// Binary Tree 
#include <time.h>
#include "HotelDataStrucAlgoTreesHeader.h"
#include <stdbool.h>
#include <string.h>


TreeNodePtr binaryTreeSearch (TreeNodePtr treePtr, char key[10]);

int mainTrees( void )
{
    /* Add Code:  Create Pointer to the tree root */
    TreeNodePtr rootPtr = NULL;
    TreeNodePtr searchPtr = NULL;
    
    // string member as per requirements
    char guestId[10];
    // user input
    long int choice;
    char *choiceP = NULL;
    //char choiceStr[7];
    // numeric member as per requirements
    int roomNumber;
    float roomPrice;
    char guestName[20];
    // char member as per requirements
    char guestGender;
    char guestEmail[50];
    //key for searching binaryTree
    char searchKey[10] = "000000000";
    
    // boolean switch for email address validation
    bool emailSwitch = false;
    
    // boolean switch for gender validation
    bool genderSwitch = false;
    
    // boolean switch for guestId alpha validation
    bool idSwitchAlpha = false;
    
    // boolean switch for guestId numeric validation
    bool idSwitchNumeric = false;
    
    // boolean switch for guestId space validation
    // validation is necessary to make sure binary search works properly
    bool tokenSwitchID = false;
    
    bool tokenSwitchEmail = false;
    // boolean switch for guestId space validation
    // validation is necessary to make sure binary search works properly
    
    // all tokens for input
    char *idToken;
    char *numberToken;
    char *priceToken;
    char *nameToken;
    char *genderToken;
    char *emailToken;
    
    // space delimiter
    const char space[2] = " ";
    
    instructionsTrees();
    
    // user insert input
    char input[100];
    
    // user searching input
    char searchInput[100];
    
    fgets(input, 100, stdin);
    
    choice = strtol(input, &choiceP, 0);
    
    // while user does not enter 6
    while(choice != 7) {
        switch(choice) {
                
                // Insert Into tree
            case 1:
                printf("\nEnter GuestId, Room Number, Price, Name, Gender & Email of Guest for Insertion: ");
                fgets(input, 100, stdin);
                
                // Tokenizing the string
                idToken = strtok(input, space);
                numberToken = strtok(NULL, space);
                priceToken = strtok(NULL, space);
                nameToken = strtok(NULL, space);
                genderToken = strtok(NULL, space);
                emailToken = strtok(NULL, space);
                
                
                if (idToken == NULL || numberToken == NULL || priceToken == NULL || nameToken == NULL || genderToken == NULL || emailToken == NULL)
                {
                    printf("\nInvalid input... Please Try Again\n");
                    break;
                }
                
                // copying tokens to variables
                strcpy(guestId, idToken);
                
                roomNumber = strtol(numberToken, NULL, 0);
                
                roomPrice = strtof(priceToken, NULL);
                
                strcpy(guestName, nameToken);
                
                // strncpy will only copy one character, and thats all we need to determine whhich gender it is or if its invalid
                strncpy(&guestGender, genderToken, 1);
                
                
                // reintialize boolean emailSwitch to False
                tokenSwitchEmail = false; // once its switched to true, it needs to be switched back to its original state (false)
                
                // Makes sure the token's last value is \0 if its \n
                // will help us avoid complications with the input using tokens and strcpy and strcmp
                for (int i = 0; emailToken[i] != '\0'; i++)
                {
                    if (emailToken[i] == '\n')
                    {
                        emailToken[i] = '\0';
                        //printf("\nPlease Enter A Valid GuestID Input Only With No Extra Spaces \n");
                        tokenSwitchEmail = true;
                        break;
                    }
                    
                }
                strcpy(guestEmail, emailToken);
                
                // reintialize boolean emailSwitch to False
                emailSwitch = false; // once its switched to true, it needs to be switched back to its original state (false)
                for (int i = 0; guestEmail[i] != '\0'; i++){
                    if (guestEmail[i] == '@'){
                        emailSwitch = true;
                    }
                }
                
                // reintialize boolean genderSwitch to False
                genderSwitch = false; // once its switched to true, it needs to be switched back to its original state (false)
                
                // char input validation
                if (guestGender == 'm' || guestGender == 'M' || guestGender == 'f' || guestGender == 'F'){
                    genderSwitch = true;
                }
                
                // if the original token length is greater than one character it wont allow the program to proceed, as its a char
                if (strlen(genderToken) > 1) {
                    genderSwitch = false;
                }
                
                // reintialize boolean idSwitchAlpha to False
                idSwitchAlpha = false; // once its switched to true, it needs to be switched back to its original state
                
                // reintialize boolean idSwitchNumeric to False
                idSwitchNumeric = false; // once its switched to true, it needs to be switched back to its original state
                
                // we need two switches because we have to account for both alpha and numeric validation
                for (int i = 0; guestId[i] != '\0'; i++)
                {
                    if ((guestId[i] >= 'a' && guestId[i] <= 'z') || (guestId[i] >= 'A' && guestId[i] <= 'Z'))
                    {
                        idSwitchAlpha = true;
                    }
                    if (guestId[i] >= '0' && guestId[i] <= '9')
                    {
                        idSwitchNumeric = true;
                    }
                }
                
                // if statements checks for all possible validation
                // note there is no error checking for numbers in a name, because a rare anomaly might happen and someone might have a number in their name
                if (idSwitchAlpha == false || idSwitchNumeric == false || roomNumber < 1 || roomPrice < 1 || genderSwitch == false || emailSwitch == false) {
                    
                    if (idSwitchAlpha == false || idSwitchNumeric == false) {
                        printf("\nGuestId must be alphanumeric... Please Try Again\n");
                        //break;
                    }
                    
                    if (roomNumber < 1) {
                        printf("\nRoom Number cannot be lower than 1... Please Try Again\n");
                        //break;
                    }
                    
                    if (roomPrice < 1) {
                        printf("\nRoom Price cannot be lower than 1... Please Try Again\n");
                        //break;
                    }
                    
                    if (genderSwitch == false){
                        printf("\nGender cannot be invalid/empty (Only one character M/m or F/f)... Please Try Again\n");
                        //break;
                    }
                    
                    if (emailSwitch == false){
                        printf("\nEmail address needs an '@' sign... Please Try Again\n\n");
                        //break;
                    }
                    break;
                }
                
                insertNode(&rootPtr, guestId, roomNumber, roomPrice, guestName, guestGender, guestEmail);
                
                break;
                
                // Remove From Tree
            case 2:
                // reintialize boolean tokenSwitchID to False
                // once its switched to true, it needs to be switched back to its original state
                tokenSwitchID = false;
                
                printf("\nEnter GuestId for Deletion from Binary Tree: \n");
                fgets(input, 100, stdin);
                
                idToken = strtok(input, space);
                
                // Makes sure the token's last value is \0 if its \n
                // will help us avoid complications with the input using tokens and strcpy and strcmp
                for (int i = 0; idToken[i] != '\0'; i++)
                {
                    if (idToken[i] == '\n')
                    {
                        idToken[i] = '\0';
                        //printf("\nPlease Enter A Valid GuestID Input Only With No Extra Spaces \n");
                        tokenSwitchID = true;
                        break;
                    }
                    
                }
                
                // copying tokens to variables
                strcpy(guestId, idToken);
                
                // reintialize boolean idSwitchAlpha to False
                idSwitchAlpha = false; // once its switched to true, it needs to be switched back to its original state
                
                // reintialize boolean idSwitchNumeric to False
                idSwitchNumeric = false; // once its switched to true, it needs to be switched back to its original state
                
                // we need two switches because we have to account for both alpha and numeric validation
                for (int i = 0; guestId[i] != '\0'; i++)
                {
                    if ((guestId[i] >= 'a' && guestId[i] <= 'z') || (guestId[i] >= 'A' && guestId[i] <= 'Z'))
                    {
                        idSwitchAlpha = true;
                    }
                    if (guestId[i] >= '0' && guestId[i] <= '9')
                    {
                        idSwitchNumeric = true;
                    }
                }
                
                if (idSwitchAlpha == false || idSwitchNumeric == false)
                {
                    printf("\nGuestId must be alphanumeric... Please Try Again\n");
                    break;
                }
                
                deleteNode(&rootPtr, guestId);
                break;
                
                // Binary Search
            case 3:
                
                // reintialize boolean idSwitchN to False
                // once its switched to true, it needs to be switched back to its original state
                tokenSwitchID = false;
                
                printf("\nEnter GuestId to Search in Binary Tree: \n");
                
                fgets(searchInput, 100, stdin);
                
                idToken = strtok(searchInput, space);
                
                // Makes sure the token's last value is \0 if its \n
                // will help us avoid complications with the input using tokens and strcpy and strcmp
                for (int i = 0; idToken[i] != '\0'; i++)
                {
                    if (idToken[i] == '\n')
                    {
                        idToken[i] = '\0';
                        //printf("\nPlease Enter A Valid GuestID Input Only With No Extra Spaces \n");
                        tokenSwitchID = true;
                        break;
                    }
                    
                }
                
                // copying tokens to variables
                strcpy(guestId, idToken);
                // copying idToken to Key as we will use key to compare
                // searchKey was getting extra input variables
                strcpy(searchKey, idToken);
                
                
                // reintialize boolean idSwitchAlpha to False
                idSwitchAlpha = false; // once its switched to true, it needs to be switched back to its original state
                
                // reintialize boolean idSwitchNumeric to False
                idSwitchNumeric = false; // once its switched to true, it needs to be switched back to its original state
                
                // we need two switches because we have to account for both alpha and numeric validation
                for (int i = 0; guestId[i] != '\0'; i++)
                {
                    if ((guestId[i] >= 'a' && guestId[i] <= 'z') || (guestId[i] >= 'A' && guestId[i] <= 'Z'))
                    {
                        idSwitchAlpha = true;
                    }
                    if (guestId[i] >= '0' && guestId[i] <= '9')
                    {
                        idSwitchNumeric = true;
                    }
                }
                
                if (idSwitchAlpha == false || idSwitchNumeric == false)
                {
                    printf("\nGuestId must be alphanumeric... Please Try Again\n");
                    break;
                }
                searchPtr = binaryTreeSearch(rootPtr, searchKey);
                
                if (searchPtr != NULL)
                {
                    printf("\nRecord with key %s was Found \nGuest ID: %s\nRoom #: %d\nRoom Price: %.2f\nGuest Name: %s\nGuest Gender: %c\nGuest Email: %s\n", searchPtr->guestId, searchPtr->guestId, searchPtr->roomNumber, searchPtr->roomPrice, searchPtr->guestName, searchPtr->guestGender, searchPtr->guestEmail);
                }
                else
                {
                    printf("\nRecord with key %s was [Not] Found \n", searchKey);
                    
                }
                break;
                // Pre-order Traversal of Tree
            case 4:
                preOrder(rootPtr);
                break;
                
                // Post-order Traversal of Tree
            case 5:
                postOrder(rootPtr);
                break;
                
                // In-order Traversal of Tree
            case 6:
                inOrder(rootPtr);
                break;
                
            default:
                puts("\nInvalid choice.\n\n" );
                break;
        } // end switch
        instructionsTrees();
        fgets(input, 100, stdin);
        choice = strtol(input, &choiceP, 0);
    } // end while
    
    puts( "End of run." );
    return 0;
} /* end main */

TreeNodePtr binaryTreeSearch (TreeNodePtr treePtr, char searchKey[10])
{
    // imples treePtr is NULL
    if (treePtr == NULL)
    {
        // add code here to process search key not found
        return NULL;
    }
    // implies (key == treePtr->data)
    //else if (searchKey == treePtr->guestId)
    else if (strcmp(searchKey, treePtr->guestId) == 0)
    {
        // add code here to process search key found
        return treePtr;
        
    }
    // implies (key < treePtr->data)
    //else if (searchKey < treePtr->guestId)
    else if (strcmp(searchKey, treePtr->guestId) < 0)
    {
        // add code here to continue searching left subtree
        return binaryTreeSearch(treePtr->leftPtr, searchKey);
    }
    // implies (key > treePtr->data)
    else
    {
        // add code here to search right tree
        return binaryTreeSearch(treePtr->rightPtr, searchKey);
    }
    
}
