#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#define MAX_CAMPEONATOS 50

typedef struct {
    char nome[50];
    int anoRealizacao;
    int equipesParticipantes[20];
    int totalEquipes;
    int campeao;
    int viceCampeao;
    int terceiroColocado;
} Campeonato;

void inicializarCampeonatos();
void cadastrarCampeonato();
void listarCampeonatos();
void menuGerenciamentoCampeonatos();

#endif
