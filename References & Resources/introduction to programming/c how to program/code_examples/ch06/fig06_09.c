// Fig. 6.9: fig06_09.c
// Roll a six-sided die 6,000,000 times
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7

// function main begins program execution
int main( void )
{
   size_t face; // random die value 1 - 6
   unsigned int roll; // roll counter 1-6,000,000
   unsigned int frequency[ SIZE ] = { 0 }; // clear counts    

   srand( time( NULL ) ); // seed random number generator

   // roll die 6,000,000 times
   for ( roll = 1; roll <= 6000000; ++roll ) {
      face = 1 + rand() % 6;
      ++frequency[ face ]; // replaces entire switch of Fig. 5.8
   } // end for                          

   printf( "%s%17s\n", "Face", "Frequency" );

   // output frequency elements 1-6 in tabular format
   for ( face = 1; face < SIZE; ++face ) {
      printf( "%4d%17d\n", face, frequency[ face ] );
   } // end for
} // end main



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

