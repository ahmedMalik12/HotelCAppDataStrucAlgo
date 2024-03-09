//
//  main.c

//header files imported
#include "HotelDataStrucAlgoQueues.h"
#include "HotelDataStrucAlgoStack.h"
#include "HotelDataStrucAlgoTrees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void instructionsMainMenu(void);

int main() {
    
    // user input
    static long int choice;
    static char *choiceP = NULL;

    instructionsMainMenu();

    static char input[100];
    
    fgets(input, 100, stdin);
    
    choice = strtol(input, &choiceP, 0);
    
    // while user does not enter 4
    while(choice != 4) {
        switch(choice) {
            
            // 1) Stack Operations
            case 1:
                // main function renamed
                mainStack();
                break;

            // 2) Queue Operations
            case 2:
                // main function renamed
                mainQueues();
                break;
                
            // 3) Tree Operations
            case 3:
                //main function renamed
                mainTrees();
                break;
                
            // 4) Exit
            case 4:
                break;
                
            default:
                puts("\nInvalid choice.\n\n" );
                break;
        } // end switch
        instructionsMainMenu();
        fgets(input, 100, stdin);
        choice = strtol(input, &choiceP, 0);
    } // end while
    
    puts( "End of run." );

}

// display program instructions to user
void instructionsMainMenu( void )
{
   printf ( "Enter your choice:\n"
           "   1) Stack Operations\n"
           "   2) Queue Operations\n"
           "   3) Tree Operations\n"
           "   4) Exit\n"
           );
} // end function instructions
