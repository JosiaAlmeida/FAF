#ifndef PARTIDA_H
#define PARTIDA_H

#define MAX_PARTIDAS 500

typedef struct
{
    int idCampeonato; // Índice do campeonato
    int equipeA;      // Índice da equipe A
    int equipeB;      // Índice da equipe B
    int placarA;      // Gols da equipe A
    int placarB;      // Gols da equipe B
    char data[11];    // Data da partida no formato DD/MM/AAAA
} Partida;

void inicializarPartidas();
void registrarPartida();
void listarPartidasPorCampeonato();
void listarPartidasPorEquipe();
void menuGerenciamentoPartidas();

void menuRegistroPartidas();

#endif
