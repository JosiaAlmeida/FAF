#ifndef DADOS_H
#define DADOS_H

#include "equipe/equipe.h"
#include "jogador/jogador.h"
#include "campeonato/campeonato.h"
#include "partida/partida.h"

extern Campeonato campeonatos[MAX_CAMPEONATOS];
extern Equipe equipes[MAX_EQUIPES];
extern Jogador jogadores[MAX_JOGADORES];
extern Partida partidas[MAX_PARTIDAS];
extern int totalPartidas;

extern int totalEquipes;
extern int totalJogadores;
extern int totalCampeonatos;
extern int totalPartidas;

#endif
