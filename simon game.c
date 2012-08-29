#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    char another_game = 'Y';
    int correct = false;
    int counter = 0;
    int sequence_length = 0;
    time_t seed = 0;
    int number = 0;
    time_t now = 0;
    int time_taken = 0;
    printf("\nTo play Simple simon,"
            "watch the screen for a sequence of digits.");
    printf("\nGood luck!\nPress enter to play\n");
    scanf("%c", &another_game);
    do
    {
        correct = true;
        counter = 0;
        sequence_length = 2;
        time_taken = clock();
        while (correct)
        {
            sequence_length += counter % 3 == 0;
            seed = time(NULL);
            now = clock();
            srand((unsigned int)seed);
            for (int i = 1; i <= sequence_length; i++)
                printf("%d ", rand() % 10);
            for ( ; clock() - now <CLOCKS_PER_SEC; );
            printf("\r");
            for(int i = 1; i <= sequence_length; i++)
                printf("  ");
            if(counter == 1)
                printf("\nNow you enter the sequence - don't forget"
                        "the spaces\n");
            else
                printf("\r");
            srand((unsigned int)seed);
            for(int i = 1; i <= sequence_length; i++)
            {
                scanf("%d", &number);
                if(number != rand() % 10)
                {
                    correct = false;
                    break;
                    }
                }
                printf("%s\n", correct? "Correct!" : "Wrong!");
                }
            time_taken = (clock()- time_taken) / CLOCKS_PER_SEC;
            printf("\n\nYour score is %d", --counter * 100 / time_taken);
            fflush(stdin);
            printf("\nDo you want to play agin (y/n)? ");
            scanf("%c",&another_game);
            }while(toupper(another_game) == 'Y');
            return 0;
}
