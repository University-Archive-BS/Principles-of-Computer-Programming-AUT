#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

FILE * AVAILABLE_TOPICS ;
FILE * selected_topic ;
FILE * players ;
FILE * graphics ;
FILE * greeting ;
FILE * correct ;
FILE * wrong ;
FILE * main_menu ;
FILE * not_working ;
FILE * bye ;

time_t t ;

    /*
    clock_t  begin= clock() //process begins

    process here

    clock_t end= clock //process ends

    time_spent = end-begin/CLOCKS_PER_SEC

    //define the structure of nodes
    */

struct node
{
    char word [ 30 ] ;
    struct node * next ;
} ;
struct node * head = NULL ;
//

//define the structure of saving information of players
typedef struct
{
    char name [ 30 ] ;
    int high_score ;
    int sum_score ;
} player ;
player now ;
//

void print_file ( FILE * a ) ; //print the content of a file completely !
int menu () ; //this is my main menu
int new_game () ; //show topics and select one of them //when the player press 1 we will come here
int open_topic ( int a ) ; //here we open the selected topic
int init_link ( FILE * b ) ;  //put each word into a node of linked list
void add_link_node ( struct node * current ) ; //add a new node at the end of the linked list
void process_topic () ;
int true_or_false ( char c , char guessed_char ) ; //to check whether this character is in this word or not
int process_word_begin ( char random_word [] ) ;
void graphic ( int l ) ; // print the process of going the person down the water
void print_words ( char print_word [] , int word_length ) ; //print the word , character by character
void init_word ( int random , char random_word [] ) ; //go to the node and copy the word to an array to process
void delete_node ( int random ) ;  // delete the node that we have played with it
int find_random_word ( int length_link ) ;//find a random number to select that node of words
int length_link ( struct node * head ) ; //find the length of the linked list
void init_players () ;  //get the name of the player and welcoming
void color ( int a ) ;

int main ()
{
    t = time( NULL ) ;
    srand ( t ) ;

    greeting = fopen ( "greeting.txt" , "r" ) ;
    print_file ( greeting ) ;
    fclose ( greeting ) ;

    init_players () ;

    return 0 ;
}

void color ( int a )
{
    HANDLE hConsole ;
    hConsole = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
    SetConsoleTextAttribute ( hConsole , a ) ;
}

void print_file ( FILE * a )
{
    char qqq [ 500 ] ;
    while ( fgets ( qqq , 500 , a ) != NULL )
    {
        printf ( "%s" , qqq ) ;
    }
}

void init_players ()
{
    players = fopen ( "players.txt" , "a+" ) ;

    //get player's name and welcoming
    printf ( "\t\tEnter your name:" ) ;
    scanf ( "%s" , now.name ) ;
    fprintf ( players , "\n%s" , now.name ) ;
    printf ( "\n\t\tWelcome %s!\n\n" , now.name ) ;
    Sleep ( 700 ) ;
    //

    int finish = 1 ;
    now.sum_score = 0 ;
    while ( finish )
    {
        finish = menu ( now ) ;
    }

    fprintf ( players , " %d" , now.sum_score ) ;
    //fprintf ( players , " %d" , now.high_score ) ;

}

int menu ()
{
    system ( "cls" ) ;
    //show the description of menu and get what player wants
    main_menu = fopen ( "main_menu.txt" , "r" ) ;
    color ( 10 ) ;
    print_file ( main_menu ) ;
    printf ( "So: " ) ;
    int char_input ;
    scanf ( "%d", & char_input ) ;
    fclose ( main_menu ) ;
    color ( 15 ) ;
    system ( "cls" ) ;
    //

    // if player choose 1, we will start new game with all of the topics and words
    if ( char_input == 1 )
    {
        new_game () ;
        return 1 ;
    }
    //

    //if player choose 2, we will continue his previous game
    if ( char_input == 2 )
    {
        color ( 13 ) ;
        not_working = fopen ( "not_working.txt" , "r" ) ;
        print_file ( not_working ) ;
        Sleep ( 2500 ) ;
        fclose ( not_working ) ;
        color ( 15 ) ;
    }

    //if player choose 3, we will finish the game
    if ( char_input == 3 )
    {
        color ( 12 ) ;
        Beep ( 1500 , 500 ) ;
        bye = fopen ( "bye.txt" , "r" ) ;
        print_file ( bye ) ;
        Sleep ( 2500 ) ;
        fclose ( bye ) ;
        color ( 15 ) ;
        return 0 ;
    }
    //

    else //yeah, this is nothing ha ha
    {
        Beep ( 1000 , 500 ) ;
        menu () ;
    }
}

int new_game ()
{
    AVAILABLE_TOPICS = fopen ( "AVAILABLE_TOPICS.txt" , "r" ) ; //open file of topics
    system( "cls" ) ;

    //put each line in a string and print each topic
    char c [ 500 ] ;
    int i = 1 ;
    printf ( "\n" ) ;
    while ( fgets ( c , 500 , AVAILABLE_TOPICS ) != NULL )
    {
        printf ( "\tEnter [%d] for:  " , i ) ;
        printf ( "%s\n" , c ) ;
        i++ ;
    }
    printf ( "\n\tAnd also you can enter [20] to generate your own topic.\n" ) ;
    //

    // here we ask player to choose a topic
    int topic_input ;
    printf ( "\nSo: " ) ;
    scanf ( "%d" , & topic_input ) ;
    //
    system ( "cls" ) ;
    open_topic ( topic_input ) ;
    fclose ( AVAILABLE_TOPICS ) ;
}

int open_topic ( int a )
{
    char name_own_topic [ 40 ] ;
    int number_generated ;
    char generated_word [ 30 ] ;

    //open the selected file of words
    switch ( a )
    {
    case 1 :
        selected_topic = fopen ( "fruits.txt" , "r" ) ;
        break;
    case 2 :
        selected_topic = fopen ( "soccer_players.txt" , "r" ) ;
        break;
    case 3 :
        selected_topic = fopen ( "programming_languages.txt" , "r" ) ;
        break;
    case 4 :
        selected_topic = fopen ( "computer_networks.txt" , "r" ) ;
        break;
    case 5 :
        selected_topic = fopen ( "video_games.txt" , "r" ) ;
        break;
    case 6 :
        selected_topic = fopen ( "name_of_teacher_assistants.txt" , "r" ) ;
        break ;
    case 7 :
        selected_topic = fopen ( "adobe_products.txt" , "r" ) ;
        break ;
    case 8 :
        selected_topic = fopen ( "animals.txt" , "r" ) ;
        break ;
    case 9 :
        selected_topic = fopen ( "colors.txt" , "r" ) ;
        break ;
    case 10 :
        selected_topic = fopen ( "test.txt" , "r" ) ;
        break ;
    case 20 :
        printf ( "Enter the name of your topic ( in format: name.txt ) : " ) ;
        scanf ( "%s" , name_own_topic ) ;
        getchar () ;
        selected_topic = fopen ( name_own_topic , "a" ) ;
        printf ( "How many words you want to have in your topic? " ) ;
        scanf ( "%d" , & number_generated ) ;
        int jj ;
        for ( jj = 0 ; jj < number_generated ; jj++ )
        {
            printf ( "Enter youe word: " ) ;
            scanf ( "%s" , generated_word ) ;
            getchar () ;
            fprintf ( selected_topic , "%s " , generated_word ) ;
        }
        fclose ( selected_topic ) ;
        selected_topic = fopen ( name_own_topic , "r" ) ;
        break ;
    }
    //

    init_link ( selected_topic ) ;
    fclose ( selected_topic ) ;
}

int init_link ( FILE * b )
{
    head = ( struct node* )malloc( sizeof ( struct node ) ) ;
    head -> next = NULL;
    struct node * current = head ;
    char c_word ;
    while ( 1 )
    {
        //put each word in a node and create the next node
        fscanf( b , "%s" , current -> word ) ;
        add_link_node ( current ) ;
        current = current -> next ;
        current -> next = NULL ;
        if( feof ( b ) )
        {
            break ;
        }
    }

    // delete the last two node because they are extra
    struct node * to_delete = head ;
    struct node * tmp = head ;
    while ( to_delete -> next != NULL )
    {
        tmp = to_delete ;
        to_delete = to_delete -> next ;
    }
    tmp -> next = NULL ;
    free ( to_delete ) ;
    to_delete = head ;
    tmp = head ;
    while ( to_delete -> next != NULL )
    {
        tmp = to_delete ;
        to_delete = to_delete -> next ;
    }
    tmp -> next = NULL ;
    free ( to_delete ) ;
    //until here


 current = head ;
    while (1)
    {
        printf("%s\n",current->word);
        if ( current -> next == NULL)
        {
            break;
        }
        current = current -> next ;
    }
    printf("\n%d\n",length_link(head));


    process_topic () ;
}

void add_link_node ( struct node * current )
{
    current -> next = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
}

void process_topic ()
{
    Sleep ( 2000 ) ;
    int random;
    char random_word [ 30 ] ;
    while ( 1 )
    {
        random = find_random_word ( length_link ( head ) ) ;         //find a word randomly to start process
        init_word ( random , random_word ) ; //put the word in an array
        process_word_begin ( random_word ) ; //process that word to play

        //check if the nodes are finished or not
        if ( length_link ( head ) == 1 )
        {
            free ( head ) ; //delete the last remaining node
            break ;
        }
        //

        delete_node ( random ) ; //delete that node of word
    }
    printf ( "Sum of your scores in this topic is: %d" , now.sum_score ) ;
    Sleep ( 2000 ) ;
}

int find_random_word ( int length_link )
{
    return ( ( ( rand () ) % length_link ) + 1 ) ;
}

int length_link ( struct node * head )
{
    struct node * temp = head ;
    int j = 1 ;
    while ( temp -> next != NULL )
    {
        temp = temp -> next ;
        j++ ;
    }
    return j ;
}

void init_word ( int random , char random_word [] )
{
    int y ;
    struct node * selected_node = head ;
    //go to a loop to reach the selected node
    for ( y = 1 ; y < random ; y++ )
    {
        selected_node = selected_node -> next ;
    }
    //

    strcpy ( random_word , selected_node -> word ) ; //copy the word to the array
}

int process_word_begin ( char random_word [] )
{
    int word_length = strlen ( random_word ) ;
    int p , o ;
    int l = 0 ;

    char print_word [ word_length ] ;
    for ( p = 0 ; p < word_length ; p++ )
    {
        print_word [ p ] = '_' ;
    }
    system( "cls" ) ;
    printf( "\nSo the word is like this: " ) ;
    print_words ( print_word , word_length ) ;
    printf( "\n\n" ) ;
    graphic ( l ) ;
    printf ( "\n" ) ;

    char guessed_char;
    int error ;
    int guessed ;
    guessed = 0 ;
    for ( l = 0 ; l < 5 ; )
    {
        printf ( "Enter your guess \n( Notice: enter [Q] to skip a word and [P] to exit the game ) : " ) ;
        getchar () ;
        scanf ( "%c", & guessed_char ) ;
        if ( guessed_char == 'P' )
        {
            Beep ( 1500 , 500 ) ;
            bye = fopen ( "bye.txt" , "r" ) ;
            print_file ( bye ) ;
            Sleep ( 2500 ) ;
            fclose ( bye ) ;
            exit ( -1 ) ;
        }
        if ( guessed_char == 'Q' )
        {
            break ;
        }
        system( "cls" ) ;
        error = 0 ;
        for ( o = 0 ; o < word_length ; o++ )
        {
            if ( true_or_false ( random_word [ o ] , guessed_char ) == 1 )
            {
                print_word [ o ] = guessed_char ;
                guessed++ ;
            }
            else
            {
                error++ ;
            }
        }

        if ( error == word_length )
        {
            wrong = fopen ( "no.txt" , "r" ) ;
            Beep ( 1000 , 500 ) ;
            print_file ( wrong ) ;
            fclose ( wrong ) ;
            Sleep ( 750 ) ;
            system ( "cls" ) ;
            printf ( "Wrong!" ) ;
            l++ ;
            switch ( l )
            {
            case 1 :
                printf ( "  (4/5) \n" ) ;
                graphic ( l ) ;
                break ;
            case 2 :
                printf ( "  (3/5) \n" ) ;
                graphic ( l ) ;
                break ;
            case 3 :
                printf ( "  (2/5) \n" ) ;
                graphic ( l ) ;
                break ;
            case 4 :
                printf ( "  (1/5) \n" ) ;
                graphic ( l ) ;
                break ;
            }
            if ( l == 5 )
            {
                printf ( "  (0/5) \n" ) ;
                graphic ( l ) ;
                printf( "\nOh! You could not guess the word! " ) ;
                printf( "\nThe word was: %s " , random_word ) ;
                printf( "\nScore of this round is ZERO .\n" ) ;
                Sleep ( 3000 ) ;
            }
            printf ( "\n" ) ;
        }
        else
        {
            correct = fopen ( "yes.txt" , "r" ) ;
            print_file ( correct ) ;
            fclose ( correct ) ;
            Sleep ( 1000 ) ;
        }

        printf ( "\nSo: " ) ;
        print_words( print_word , word_length ) ;
        printf( "\n" ) ;

        if ( guessed == word_length )
        {
            printf ( "\nWow you guessed the word correctly! \n\n" ) ;
            int score = ( 3 * ( word_length ) - l ) ;
            now.sum_score += score ;
            printf ( "Score of this round is: %d" , score ) ;
            printf ( "\n\nSum of your scores until now, is: %d" , now.sum_score ) ;
            printf ( "\n" ) ;
            Sleep ( 3000 ) ;
            break ;
        }
    }
}

void print_words ( char print_word [] , int word_length )
{
    int q ;
    for ( q = 0 ; q < word_length ; q++ )
    {
        printf( " %c" , print_word [ q ] ) ;
    }
}

int true_or_false ( char c , char guessed_char )
{
    if ( guessed_char == c )
    {
        return 1 ;
    }
    return 0 ;
}

void graphic ( int l )
{
    switch ( l )
    {
    case 0 :
        graphics = fopen ( "step0.txt" , "r" ) ;
        break;
    case 1 :
        graphics = fopen ( "step1.txt" , "r" ) ;
        break;
    case 2 :
        graphics = fopen ( "step2.txt" , "r" ) ;
        break;
    case 3 :
        graphics = fopen ( "step3.txt" , "r" ) ;
        break;
    case 4 :
        graphics = fopen ( "step4.txt" , "r" ) ;
        break;
    case 5 :
        graphics = fopen ( "step5.txt" , "r" ) ;
        break ;
    }
    print_file ( graphics ) ;
    fclose ( graphics ) ;
}

void delete_node ( int random )
{
    struct node * deleted_node = head ;
    struct node * last = head ;
    int k ;
    //if it is the first node we should do this
    if ( random == 1 )
    {
        head = head -> next ;
        free ( deleted_node ) ;
        return ;
    }
    //

    //if it is the last node, we should do this
    else if ( random == length_link ( head ) )
    {
        while ( deleted_node -> next != NULL )
        {
            last = deleted_node ;
            deleted_node = deleted_node -> next ;
        }
        last -> next = NULL ;
        free ( deleted_node ) ;
        return ;
    }
    //

    else
    {
        for ( k = 1 ; k < random ; k++ )
        {
            last = deleted_node ;
            deleted_node = deleted_node -> next ;
        }
        last -> next = deleted_node -> next ;
        free( deleted_node ) ;
        return ;
    }
}


