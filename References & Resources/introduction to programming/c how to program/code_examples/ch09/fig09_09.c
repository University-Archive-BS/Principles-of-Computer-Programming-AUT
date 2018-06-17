// Fig. 9.9: fig09_09.c
// Printing integers, floating-point numbers and strings with precisions
#include <stdio.h>

int main( void )
{ 
   int i = 873; // initialize int i
   double f = 123.94536; // initialize double f
   char s[] = "Happy Birthday"; // initialize char array s

   puts( "Using precision for integers" );
   printf( "\t%.4d\n\t%.9d\n\n", i, i );

   puts( "Using precision for floating-point numbers" );
   printf( "\t%.3f\n\t%.3e\n\t%.3g\n\n", f, f, f );  
   
   puts( "Using precision for strings" );
   printf( "\t%.11s\n", s );
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