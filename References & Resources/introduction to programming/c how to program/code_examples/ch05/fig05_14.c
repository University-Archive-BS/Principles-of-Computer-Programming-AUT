// Fig. 5.14: fig05_14.c
// Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice( void ); // function prototype

// function main begins program execution
int main( void )
{ 
   int sum; // sum of rolled dice
   int myPoint; // player must make this point to win

   enum Status gameStatus; // can contain CONTINUE, WON, or LOST

   // randomize random number generator using current time
   srand( time( NULL ) );

   sum = rollDice(); // first roll of the dice

   // determine game status based on sum of dice
   switch( sum ) {

      // win on first roll
      case 7: // 7 is a winner
      case 11: // 11 is a winner          
         gameStatus = WON; // game has been won
         break;

      // lose on first roll
      case 2: // 2 is a loser
      case 3: // 3 is a loser
      case 12: // 12 is a loser
         gameStatus = LOST; // game has been lost
         break;

      // remember point
      default:                  
         gameStatus = CONTINUE; // player should keep rolling
         myPoint = sum; // remember the point
         printf( "Point is %d\n", myPoint );
         break; // optional
   } // end switch

   // while game not complete
   while ( CONTINUE == gameStatus ) { // player should keep rolling
      sum = rollDice(); // roll dice again

      // determine game status
      if ( sum == myPoint ) { // win by making point
         gameStatus = WON; // game over, player won
      } // end if
      else {
         if ( 7 == sum ) { // lose by rolling 7
            gameStatus = LOST; // game over, player lost
         } // end if
      } // end else
   } // end while

   // display won or lost message
   if ( WON == gameStatus ) { // did player win?
      puts( "Player wins" );
   } // end if
   else { // player lost
      puts( "Player loses" );
   } // end else
} // end main

// roll dice, calculate sum and display results
int rollDice( void )
{
   int die1; // first die
   int die2; // second die
   int workSum; // sum of dice

   die1 = 1 + ( rand() % 6 ); // pick random die1 value
   die2 = 1 + ( rand() % 6 ); // pick random die2 value
   workSum = die1 + die2; // sum die1 and die2

   // display results of this roll
   printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
   return workSum; // return sum of dice
} // end function rollRice



/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
