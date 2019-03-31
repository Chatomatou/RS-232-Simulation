/* INCLUSION DES BIBLIOTHEQUES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>

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
extern void read232(const char* byte, const RS232_Parity parity, const RS232_Stop stop);
extern void readMessage(const char* str, const RS232_Parity parity, const RS232_Stop stop);
extern bool testParity(const char* str, const RS232_Parity parity);