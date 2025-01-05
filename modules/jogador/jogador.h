#ifndef JOGADOR_H
#define JOGADOR_H

#define MAX_JOGADORES 1000

typedef struct
{
    char nome[50];
    int idade;
    int numeroCamisa;
    char posicao[20];
    int idEquipe;
    int golsMarcados;
} Jogador;

void inicializarJogadores();
void cadastrarJogador();
void listarJogadores();
void atualizarJogador();
void menuCadastroJogadores();

#endif
