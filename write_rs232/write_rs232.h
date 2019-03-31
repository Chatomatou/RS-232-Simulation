/* INCLUSION DES BIBLIOTHEQUES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enumeration pour géré la parité de la liaison  */
 typedef enum 
 {
    RS232_PARITY_WITHOUT,
    RS232_PARITY_PEER,
    RS232_PARITY_ODD
 }RS232_Parity;

/* Enumération pour géré le nombre de bit(s) de stop*/
 typedef enum 
 {
    RS232_STOP_BIT_ONE,
    RS232_STOP_BITS_TWO
 }RS232_Stop;

/* Prototype */
void write232(const char byte, const RS232_Parity parity, const RS232_Stop stop);
void writeMessage(char* str, const RS232_Parity parity, const RS232_Stop stop);
