//   ___            ___    ___  ________      _______       _______           ________      ________      ___           ________      _______       ________      _________                
//  |\  \          |\  \  /  /||\   ____\    |\  ___ \     |\  ___ \         |\   ____\    |\   __  \    |\  \         |\   __  \    |\  ___ \     |\   __  \    |\___   ___\              
//  \ \  \         \ \  \/  / /\ \  \___|    \ \   __/|    \ \   __/|        \ \  \___|    \ \  \|\  \   \ \  \        \ \  \|\ /_   \ \   __/|    \ \  \|\  \   \|___ \  \_|              
//   \ \  \         \ \    / /  \ \  \        \ \  \_|/__   \ \  \_|/__       \ \  \        \ \  \\\  \   \ \  \        \ \   __  \   \ \  \_|/__   \ \   _  _\       \ \  \               
//    \ \  \____     \/  /  /    \ \  \____    \ \  \_|\ \   \ \  \_|\ \       \ \  \____    \ \  \\\  \   \ \  \____    \ \  \|\  \   \ \  \_|\ \   \ \  \\  \|       \ \  \              
//     \ \_______\ __/  / /       \ \_______\   \ \_______\   \ \_______\       \ \_______\   \ \_______\   \ \_______\   \ \_______\   \ \_______\   \ \__\\ _\        \ \__\             
//      \|_______||\___/ /         \|_______|    \|_______|    \|_______|        \|_______|    \|_______|    \|_______|    \|_______|    \|_______|    \|__|\|__|        \|__|             
//                \|___|/                                                                                                                                                                  
//                                                                                                                                                                                         
//                                                                                                                                                                                         
//                           ________      ___      ________      ________      ________          ________       ________      _____ ______       ___  ___      _______       ___          
//                          |\   __  \    |\  \    |\   ____\    |\_____  \    |\   __  \        |\   ____\     |\   __  \    |\   _ \  _   \    |\  \|\  \    |\  ___ \     |\  \         
//                          \ \  \|\ /_   \ \  \   \ \  \___|     \|___/  /|   \ \  \|\  \       \ \  \___|_    \ \  \|\  \   \ \  \\\__\ \  \   \ \  \\\  \   \ \   __/|    \ \  \        
//                           \ \   __  \   \ \  \   \ \  \            /  / /    \ \  \\\  \       \ \_____  \    \ \   __  \   \ \  \\|__| \  \   \ \  \\\  \   \ \  \_|/__   \ \  \       
//                            \ \  \|\  \   \ \  \   \ \  \____      /  /_/__    \ \  \\\  \       \|____|\  \    \ \  \ \  \   \ \  \    \ \  \   \ \  \\\  \   \ \  \_|\ \   \ \  \____  
//                             \ \_______\   \ \__\   \ \_______\   |\________\   \ \_______\        ____\_\  \    \ \__\ \__\   \ \__\    \ \__\   \ \_______\   \ \_______\   \ \_______\
//                              \|_______|    \|__|    \|_______|    \|_______|    \|_______|       |\_________\    \|__|\|__|    \|__|     \|__|    \|_______|    \|_______|    \|_______|
//                                                                                                  \|_________|                                                                           
//                                                                                                                                                                                         
//                     
                                                                                                                                                                    
/* INCLUSION DE LA BIBLIOTHEQUE */
#include "write_rs232.h"

int main(int argc, char* argv[])
{
    RS232_Parity parity;
    RS232_Stop stop;

    memset(&parity, 0, sizeof(parity));
    memset(&stop, 0, sizeof(stop));

    // Verification des argument 
    if(argc != 4)
    {
        fprintf(stderr, "Usage : ./write_rs232 <string> <parity> <stop>\n");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[2], "RS232_PARITY_PEER") == 0)
        parity = RS232_PARITY_PEER;
    else if(strcmp(argv[2], "RS232_PARITY_ODD") == 0)
        parity = RS232_PARITY_ODD;
    else if(strcmp(argv[2], "RS232_PARITY_WITHOUT") == 0)
        parity = RS232_PARITY_WITHOUT;
    else 
    {
        fprintf(stderr, "Usage : ./write_rs232 <string> <parity> <stop>\n");
        return EXIT_FAILURE;
    }
 
    if(strcmp(argv[3], "RS232_STOP_BIT_ONE") == 0)
        stop = RS232_STOP_BIT_ONE;
    else if(strcmp(argv[3], "RS232_STOP_BITS_TWO") == 0)
        stop = RS232_STOP_BITS_TWO;
    else 
    {
        fprintf(stderr, "Usage : ./write_rs232 <string> <parity> <stop>\n");
        return EXIT_FAILURE;
    }

    // Simule une liaison RS-232
    writeMessage(argv[1], parity, stop);
    printf("\n");
    return EXIT_SUCCESS;
}