// Fig. 10.16: fig10_16.c
// Representing cards with bit fields in a struct
#include <stdio.h>
#define CARDS 52

// bitCard structure definition with bit fields
struct bitCard {                                  
   unsigned int face : 4; // 4 bits; 0-15        
   unsigned int suit : 2; // 2 bits; 0-3         
   unsigned int color : 1; // 1 bit; 0-1          
}; // end struct bitCard                          

typedef struct bitCard Card; // new type name for struct bitCard   

void fillDeck( Card * const wDeck ); // prototype
void deal( const Card * const wDeck ); // prototype

int main( void )
{ 
   Card deck[ CARDS ]; // create array of Cards

   fillDeck( deck );
   deal( deck );
} // end main

// initialize Cards
void fillDeck( Card * const wDeck )
{ 
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = i % (CARDS / 4); 
      wDeck[ i ].suit = i / (CARDS / 4);  
      wDeck[ i ].color = i / (CARDS / 2);
   } // end for
} // end function fillDeck

// output cards in two-column format; cards 0-25 subscripted with 
// k1 (column 1); cards 26-51 subscripted with k2 (column 2)
void deal( const Card * const wDeck )
{ 
   size_t k1; // subscripts 0-25
   size_t k2; // subscripts 26-51

   // loop through wDeck
   for ( k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2 ) { 
      printf( "Card:%3d  Suit:%2d  Color:%2d   ",
         wDeck[ k1 ].face, wDeck[ k1 ].suit, wDeck[ k1 ].color );
      printf( "Card:%3d  Suit:%2d  Color:%2d\n",
         wDeck[ k2 ].face, wDeck[ k2 ].suit, wDeck[ k2 ].color );
   } // end for
} // end function deal


 

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
