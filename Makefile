# Nome do executável
TARGET = sistema

# Compilador
CC = gcc

# Flags do compilador (opcional: pode incluir -Wall para avisos)
CFLAGS = -Wall

# Diretórios e arquivos fonte
SRCS = modules/main.c \
       modules/equipe/equipe.c \
       modules/jogador/jogador.c \
       modules/campeonato/campeonato.c \
       modules/partida/partida.c \
       modules/relatorio/relatorio.c \
       modules/persistencia/persistencia.c \
       modules/utils/validate.c

# Objetos gerados
OBJS = $(SRCS:.c=.o)

# Regra padrão para compilar e linkar
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Alias para rodar o programa
run: $(TARGET)
	./$(TARGET)
