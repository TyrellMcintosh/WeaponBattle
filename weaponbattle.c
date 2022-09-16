#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char GetUserSelection()
{
        char choice;
        
        // Rules of the game
        printf("\nA for armor, H for hammer, S for sword or Q to quit\n"); 
        // Takes user input
        printf("Enter your choice:");
        scanf_s("%c", &choice);
        choice = tolower(choice);       // makes character into lowercase
        return choice;
}

char GetComputerSelection()
{
        int choice;
        char answer;
        /* Generates a random number */
        srand(time(NULL));
        choice = rand() % 2;

        if (choice == 0)
                answer = 'h';
        else if (choice == 1)
                answer = 's';
        else
                answer = 'a';

        return answer;
}

int GetWinner(char user_choice, char computer_choice)
{
        // If they are the same it is a tie
        if (user_choice == computer_choice)
                return 0;

        // Hammer beats armor 
        if (user_choice == 'h' && computer_choice == 'a')
                return 1;
        if (computer_choice == 'h' && user_choice == 'a')
                return -1;

        // Sword beats hammer
        if (user_choice == 's' && computer_choice == 'h')
                return 1;
        if (computer_choice == 's' && user_choice == 'h')
                return -1;

        // Armor beats sword
        if (user_choice == 'a' && computer_choice == 's')
                return 1;
        if (computer_choice == 'a' && user_choice == 's')
                return -1;
}

int main()
{
        char user;         // user choice
        char computer;     // computer choice
        int winner;         // winner outcome

        do
        {
                user = GetUserSelection();
                if (user == 'q')
                        break;
                computer = GetComputerSelection();
                winner = GetWinner(user, computer);
                if (winner == -1)
                        printf("Computer wins!");
                else if (winner == 0)
                        printf("It's a tie!");
                else if (winner == 1)
                        printf("User wins!");
        } while (user != 'q');
}
