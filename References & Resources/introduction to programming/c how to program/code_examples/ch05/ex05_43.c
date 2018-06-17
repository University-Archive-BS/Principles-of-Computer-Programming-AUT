#include <stdio.h>

unsigned int mystery( unsigned int a, unsigned int b ); // function prototype
 
// function main begins program execution  
int main( void )
{
   unsigned int x; // first integer
   unsigned int y; // second integer
   
   printf( "%s", "Enter two positive integers: " );
   scanf( "%u%u", &x, &y );

   printf( "The result is %u\n", mystery( x, y ) );
} // end main

// Parameter b must be a positive integer 
// to prevent infinite recursion
unsigned int mystery( unsigned int a, unsigned int b )
{                                              
   // base case
   if ( 1 == b ) {
      return a;
   } // end if
   else { // recursive step
      return a + mystery( a, b - 1 );
   } // end else
} // end function mystery


 

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