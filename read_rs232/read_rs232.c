/* INCLUSION DES BIBLIOTHEQUES */
#include "read_rs232.h"
 
/*!
\brief Lecture d'une très longue trames RS-232
\param La très grande trames 
\param Sa parité pour verifier si la trame et correctement reçu  
\param stop savoir combien de bit(s) de stop on a
*/
void readMessage(const char* str, const RS232_Parity parity, const RS232_Stop stop)
{
    char* cpy = NULL;
    char* split = NULL;

    cpy = malloc(sizeof(char)* strlen(str));

    if(cpy == NULL)
    {
        fprintf(stderr, "Error : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
 
    strcpy(cpy, str); // copie str dans cpy 
    split = strtok(cpy, " "); // découpe ma chaine en fonction des espace 
 
    while(split != NULL)
    {
        read232(split, parity, stop); // call ma fonction de lecture 
        split = strtok(NULL, " "); // Redecoupe ma string en fonction des espace 
    }

    // Libére la mémoire alloué dans le tas pour cpy
    free(cpy);  
}

/*!
\brief Verification du bit de parité pour la trames
\param La trame en question 
\param Sa parité pour verifier si la trame et correctement reçu  
\param stop savoir combien de bit(s) de stop doit on afficher
*/
bool testParity(const char* str, const RS232_Parity parity)
{
    unsigned int i = 0;
    unsigned int count = 0; 
 
    for(i = 1; i < 9; i++)
    {
        if(str[i] == '-')
            count++;
    }

    if(parity == RS232_PARITY_PEER && count % 2 == 0 && str[9] == '_')
        return true; // On a bien une parité pair
    else if (parity == RS232_PARITY_PEER && count % 2 == 0 && str[9] == '-')
        return false; // Une erreur c'est produite 
    else if(parity == RS232_PARITY_PEER && count % 2 == 1 && str[9] == '-')
        return true; // On a bien une parité pair 
    else if(parity == RS232_PARITY_ODD && count % 2 == 0 && str[9] == '-')
        return true;// On a bien une parité impair
    else if(parity == RS232_PARITY_ODD && count % 2 == 1 && str[9] == '-')
        return false; // Une erreur c'est produite 
    else if(parity == RS232_PARITY_ODD && count % 2 == 1 && str[9] == '_')
        return true; // On a bien une parité impair 
    else 
        return false; // Si on a une RS232_PARITY_WITHOUT
}

/*!
\brief Lit une trames RS-232
\param La trame en question 
\param Sa parité pour verifier si la trame et correctement reçu  
\param stop savoir combien de bit(s) de stop doit on afficher
*/
void read232(const char* byte, const RS232_Parity parity, const RS232_Stop stop)
{
    (void)stop;
    unsigned int data = 0;
    unsigned int i = 0;

    if(testParity(byte, parity) == false && parity != RS232_PARITY_WITHOUT) 
    {
        printf(" RS-232 : Received failure... ");
    }
    else 
    {
        for(i = 1; i < 9; i++)
        {
            if(byte[i] == '-')
                data += pow(2, i - 1);
        }
        printf("%c", data);
    }
}

 
 
