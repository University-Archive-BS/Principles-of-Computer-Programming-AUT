// Fig. 6.11: fig06_11.c
// Static arrays are initialized to zero if not explicitly initialized.
#include <stdio.h>

void staticArrayInit( void ); // function prototype
void automaticArrayInit( void ); // function prototype

// function main begins program execution
int main( void )
{
   puts( "First call to each function:" );
   staticArrayInit();   
   automaticArrayInit();

   puts( "\n\nSecond call to each function:" );
   staticArrayInit();   
   automaticArrayInit();
} // end main
 
// function to demonstrate a static local array
void staticArrayInit( void )
{
   // initializes elements to 0 first time function is called
   static int array1[ 3 ];
   size_t i; // counter

   puts( "\nValues on entering staticArrayInit:" );

   // output contents of array1
   for ( i = 0; i <= 2; ++i ) {
      printf( "array1[ %u ] = %d  ", i, array1[ i ] );
   } // end for

   puts( "\nValues on exiting staticArrayInit:" );

   // modify and output contents of array1
   for ( i = 0; i <= 2; ++i ) {
      printf( "array1[ %u ] = %d  ", i, array1[ i ] += 5 );
   } // end for
} // end function staticArrayInit

// function to demonstrate an automatic local array
void automaticArrayInit( void )
{
   // initializes elements each time function is called
   int array2[ 3 ] = { 1, 2, 3 };
   size_t i; // counter

   puts( "\n\nValues on entering automaticArrayInit:" );

   // output contents of array2
   for ( i = 0; i <= 2; ++i ) {
      printf("array2[ %u ] = %d  ", i, array2[ i ] );
   } // end for

   puts( "\nValues on exiting automaticArrayInit:" );

   // modify and output contents of array2
   for ( i = 0; i <= 2; ++i ) {
      printf( "array2[ %u ] = %d  ", i, array2[ i ] += 5 );
   } // end for
} // end function automaticArrayInit



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

