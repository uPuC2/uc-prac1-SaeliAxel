/**************************************************************************
//Examples code
*******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
/*
  Ejercicios de enmascaramientos. 
  Lo que se busca es que imprima el valor que esta comentado,
  alterando unicamente el valor anterior utilizando los operadores bitwise.
  Todas las conversiones deberian ser posibles con una sola operacion
*/
int main()
{
    uint16_t a = 0;
    printf("\na = %X", a);
//  Como ejemplo se da el analisis de la primera operacion

//1 B0B0 
//       hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      B0B0 = 1011 0000 1011 0000  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1011 0000 1011 0000  (mascara para lograrlo) = (1<<15) | (3<<12) | (1<<7) | (3<<4)
//------------------------------------------------
//    1011 0000 1011 0000  (valor que se desea)
    a |= (1<<15) | (3<<12) | (1<<7) | (3<<4);
    printf("\na = %X", a);
    
//2 BABA
// 1011 0000 1011 0000
// 1011 1010 1011 1010
// ------------------------------------------------
// 
    a |= (0xA << 8) | (0xA << 0) ;
    printf("\na = %X", a);
//3 BEBE
    a |= (0xE << 9) | (0xE << 0);
    printf("\na = %X", a);
    // 1011 1110 1011 1110
    // 1111 1110 0000 0000
//4 FE00
    a = a<<8 | (1<<14);
    printf("\na = %X", a);
//5 FEAA
    a |= (0xA << 4) | (0xA << 0);
    printf("\na = %X", a);
//6 0155
    a = (~1<<15) | (1<<8)| (5 << 4) | (5<<0);
    //0000 0001 0101 0101  
    printf("\na = %X", a);
//7 0001 
    a = (0<<8) | (0 << 6) | (0<<4) | (1<<0);
    // 0000 0000 0000 0001
    printf("\na = %X", a);
//8 0100
    a =(0<<12) | (1<< 8);
    //0000 0001 0000 0000
    printf("\na = %X", a);
    return 0;
}
