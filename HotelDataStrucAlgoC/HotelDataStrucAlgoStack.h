
// include stack header-file
#include "HotelDataStrucAlgoStackHeader.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int mainStack(void) {
    
    StackNodePtr stackPtr = NULL; // create stack pointer
    
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
    
    //int value;
    
    // boolean switch for email address validation
    bool emailSwitch = false;
    
    // boolean switch for gender validation
    bool genderSwitch = false;
    
    
    // boolean switch for guestId alpha validation
    bool idSwitchAlpha = false;
    
    // boolean switch for guestId numeric validation
    bool idSwitchNumeric = false;
    
    // all tokens for input
    char *idToken;
    char *numberToken;
    char *priceToken;
    char *nameToken;
    char *genderToken;
    char *emailToken;

    // space delimiter
    const char space[2] = " ";
    
    instructions();
    
    char input[100];

    fgets(input, 100, stdin);
    
    choice = strtol(input, &choiceP, 0);
    
    while(choice != 6) {
        switch(choice) {
                
                // Top of Stack
            case 1:
                if(!isEmpty(stackPtr)) {
                    topOfStack(stackPtr);//print node at the top of the stack
                }
                else{
                    puts("\nThe Stack is Empty\n");
                }
                break;
                
                // Bottom of Stack
                
            case 2:
                if(!isEmpty(stackPtr)) {
                    bottomOfStack(stackPtr);//print node at the bottom of stack
                }
                else{
                    puts("\nThe Stack is Empty\n");
                }
                break;
                
                // Push
            case 3:
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
                
                stackPtr = push(stackPtr, guestId, roomNumber, roomPrice, guestName, guestGender, guestEmail);//push node onto stack
                printStack(stackPtr);//print the stack nodes
                break;
                
                // Pop
            case 4:
                if(!isEmpty(stackPtr)) {
                    stackPtr = pop(stackPtr, guestId);//pop node from stack
                }
                printStack(stackPtr);//print the current stack nodes
                break;
                
                // Print all the data items
            case 5:
                printStack(stackPtr);
                break;
                
                // 6 Exit Stack Application
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
        instructions();

        fgets(input, 100, stdin);
        
        choice = strtol(input, &choiceP, 0);
    }
    printf("\nEnd of run.\n");
    
    return 0;
}



