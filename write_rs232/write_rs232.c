/* INCLUSION DE LA BIBLIOTHEQUE */
#include "write_rs232.h"

/*!
\brief Simule l'envoi d'un octet en liaison RS-232
\param byte la donnée a envoyer 
\param parity savoir si on rajoute le bit de parité
\param stop savoir combien de bit(s) de stop doit on afficher
*/
void write232(const char byte, const RS232_Parity parity, const RS232_Stop stop)
{
    char i = 0;
    unsigned char count = 0;

    printf("_"); // bit de start 

    // Début bits de données 
    for(i = 0; i < 8; i++) // Envoi les donnée de 2^0 a 2^7 du LSB au MSB  (Dépend de l'endianness de votre MACHINE bien évidéments :) ) 
        (byte >> i & 1) ? printf("-"), count++ /*Compte le nombre de bit a 1*/ : printf("_");
    
    // Bit de parité
    switch(parity)
    {
    case RS232_PARITY_PEER:
        if(count % 2 == 1) // Si on a une nombre impair de bit on ajoute un bit pour avoir un nombre pair de bit qui vaut - vu qu'on veut une parité pair 
            printf("-");
        else 
            printf("_"); // On ajoute le 0 car c'est déja pair 
   
        break; 
    case RS232_PARITY_ODD:
        if(count % 2 == 0) // Si on a une nombre pair de bit on ajoute un bit pour avoir un nombre impair de bit qui vaut - vu qu'on veut une parité impair
            printf("-");
        else 
            printf("_"); // On ajoute le 0 car c'est déja impair
        break;
    case RS232_PARITY_WITHOUT: // ajoute pas de parité 
        break;
    }    

    // Bit de stop
    (stop == RS232_STOP_BIT_ONE) ? printf("-") : printf("--");
}

/*!
\brief Simulation d'une chaine de caractère en RS-232
\param byte la donnée a envoyer 
\param parity savoir si on rajoute le bit de parité
\param stop savoir combien de bit(s) de stop doit on afficher
*/
void writeMessage(char* str, const RS232_Parity parity, const RS232_Stop stop)
{
    while(*str != '\0')
    {
        write232(*str, parity, stop);
        printf(" ");
        str++;
    }
}