CC = gcc # Compilateur 
EXEC = read_rs232 # Nom executable 
SRC = $(wildcard *.c) # Prend tout les fichier avec l'extension 
OBJ = $(SRC:.c=.o) # Prend le contenu de SRC et transforme les .c en .o 
CFLAGS = -Wall -Wextra # Options de compilation 


all: $(EXEC) 

# Génére le .exe (Windows) ou le elf (linux)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^  
# Création des fichier .o
%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)