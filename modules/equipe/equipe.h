#ifndef EQUIPE_H
#define EQUIPE_H

#define MAX_EQUIPES 50
#define MAX_JOGADORES_POR_EQUIPE 4

typedef struct
{
    char nome[50];
    char cidade[50];
    int anoFundacao;
    char treinador[50];
    int jogadores[MAX_JOGADORES_POR_EQUIPE];
    int totalJogadores;
} Equipe;

void inicializarEquipes();
void cadastrarEquipe();
void listarEquipes();
void atualizarEquipe();
void menuCadastroEquipes();

#endif
