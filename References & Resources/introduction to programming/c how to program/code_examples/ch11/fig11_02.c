// Fig. 11.2: fig11_02.c
// Creating a sequential file
#include <stdio.h>

int main( void )
{ 
   unsigned int account; // account number
   char name[ 30 ]; // account name
   double balance; // account balance

   FILE *cfPtr; // cfPtr = clients.dat file pointer   

   // fopen opens file. Exit program if unable to create file 
   if ( ( cfPtr = fopen( "clients.dat", "w" ) ) == NULL ) {
      puts( "File could not be opened" );
   } // end if
   else { 
      puts( "Enter the account, name, and balance." );
      puts( "Enter EOF to end input." );
      printf( "%s", "? " );
      scanf( "%d%29s%lf", &account, name, &balance );

      // write account, name and balance into file with fprintf
      while ( !feof( stdin ) ) { 
         fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
         printf( "%s", "? " );
         scanf( "%d%29s%lf", &account, name, &balance );
      } // end while
      
      fclose( cfPtr ); // fclose closes file   
   } // end else
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
