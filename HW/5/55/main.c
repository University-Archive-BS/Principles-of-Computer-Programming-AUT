#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ran1,i=0;
    time_t t = time(NULL) % 1000;
    srand(t);
    ran1 = rand() % 1000;

    int x;
    int count_error_pc=0,count_finish=0,count_error_karbar=0;
    while (i==0)
    {
        printf("Now, I made a number in myself\nI want you to guess it...\nLet's Go!\n");
        while( x != ran1 )
        {
            printf("Enter your Guess:");
            scanf("%d",&x);
            if ( x == 0)
            {
                count_finish++;
                if ( count_finish == 3 )
                {
                    printf("The Game Finished!\n");
                    break;
                }
            }
            if ( x==ran1)
            {
                printf("\nHoooooooooooooooooora...Perfect\n");
            }
            if ( x> ran1)
            {
                printf("oooops... high\n");
                count_error_karbar++;
            }
            if ( x < ran1)
            {
                printf("oooops... low\n");
                count_error_karbar++;
            }
            printf("\n");

        }
        if ( count_finish == 3 )
        {
            break;
        }
        int res=0,ran2;
        printf("\n=========================================\n\nNow,I wanna guess.\nSo consider a number in your mind and I will try to guess.\nIn each round please: \n Enter 2 if my guess was high\n Enter 1 if my guess was low \n Enter 5 if my guess was True.\nThanks :D \nStart:\n");
        ran2 = 500;
        printf("\nMy Guess:%d\nYour Respond:",ran2);
        while ( res != 5)
        {
            res=0;
            scanf("%d",&res);
            printf("\n");
            if ( res == 0)
            {
                count_finish++;
                if ( count_finish == 3 )
                {
                    printf("The Game Finished!\n");
                    break;
                }
            }
            if ( res == 1 )
            {
                ran2 = ran2 + 250/((count_error_pc) + 1);
                count_error_pc++;
            }
            if ( res == 2)
            {
                ran2 = ran2 - 250/((count_error_pc) + 1);
                count_error_pc++;
            }
            if ( res == 5)
            {
                printf("HaHaHa...I'm so SMART :))) \n\n=========================================\n\n");
                break;
            }
            printf("\nMy Guess:%d\nYour Respond:",ran2);
        }
        if ( count_finish == 3 )
        {
            break;
        }
        ran1 = rand() % 1000;
    }
    printf("Now I wanna show you how many times we made a mistake in our guesses:\n");
    printf("You mistakes: %d\n",count_error_karbar);
    printf("My mistakes: %d\n",count_error_pc);

    getchar();
    getchar();
    return 0;
}
