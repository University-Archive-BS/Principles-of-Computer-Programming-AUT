// Fig. 5.19: fig05_19.c
// Recursive fibonacci function
#include <stdio.h>

unsigned long long int fibonacci( unsigned int n ); // function prototype

// function main begins program execution
int main( void )
{
   unsigned long long int result; // fibonacci value
   unsigned int number; // number input by user

   // obtain integer from user
   printf( "%s", "Enter an integer: " );
   scanf( "%u", &number );

   // calculate fibonacci value for number input by user
   result = fibonacci( number );

   // display result
   printf( "Fibonacci( %u ) = %llu\n", number, result );
} // end main

// Recursive definition of function fibonacci              
unsigned long long int fibonacci( unsigned int n )      
{                                                         
   // base case                                           
   if ( 0 == n || 1 == n ) {                               
      return n;                                            
   } // end if                                           
   else { // recursive step                            
      return fibonacci( n - 1 ) + fibonacci( n - 2 );        
   } // end else                                        
} // end function fibonacci                              


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
