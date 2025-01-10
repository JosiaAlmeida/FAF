#include <stdio.h>
#include <string.h>
#include "partida.h"
#include "../campeonato/campeonato.h"
#include "../equipe/equipe.h"
#include "../dados.h"

Partida partidas[MAX_PARTIDAS];
int totalPartidas = 0;

void inicializarPartidas()
{
    totalPartidas = 0;
}

void registrarPartida()
{
    if (totalPartidas >= MAX_PARTIDAS)
    {
        printf("Limite de partidas atingido.\n");
        return;
    }

    Partida novaPartida;
    listarCampeonatos();
    printf("Escolha o índice do campeonato: ");
    scanf("%d", &novaPartida.idCampeonato);
    novaPartida.idCampeonato--;

    if (novaPartida.idCampeonato < 0 || novaPartida.idCampeonato >= totalCampeonatos)
    {
        printf("Campeonato inválido.\n");
        return;
    }

    listarEquipes();
    printf("Escolha o índice da equipe A: ");
    scanf("%d", &novaPartida.equipeA);
    novaPartida.equipeA--;

    printf("Escolha o índice da equipe B: ");
    scanf("%d", &novaPartida.equipeB);
    novaPartida.equipeB--;

    if (novaPartida.equipeA < 0 || novaPartida.equipeB < 0 ||
        novaPartida.equipeA >= totalEquipes || novaPartida.equipeB >= totalEquipes ||
        novaPartida.equipeA == novaPartida.equipeB)
    {
        printf("Equipes inválidas.\n");
        return;
    }

    printf("Data da partida (DD/MM/AAAA): ");
    scanf(" %[^\n]", novaPartida.data);

    printf("Placar da equipe A: ");
    scanf("%d", &novaPartida.placarA);
    while (novaPartida.placarA != 0)
    {

        printf("\n=== Selecione o artilheiro ===\n");
        int jogador = 0;
        int goal = 0;
        for (int j = 0; j < equipes[novaPartida.equipeA].totalJogadores; j++)
        {
            if (jogadores[j].idEquipe == novaPartida.equipeA)
            {
                printf("%d. %s\n", j + 1, jogadores[j].nome);
            }
        }
        scanf("%d", &jogador);
        printf("Total de Golos: ");
        scanf("%d", &goal);
        while (goal > novaPartida.placarA)
        {
            printf("Quantidade invalida, Insira o total de golos novamente: ");
            scanf("%d", &goal);
        }
        jogadores[jogador--].golsMarcados += goal;
        novaPartida.placarA -= goal;
    }

    printf("Placar da equipe B: ");
    scanf("%d", &novaPartida.placarB);

    while (novaPartida.placarB != 0)
    {

        printf("\n=== Selecione o artilheiro ===\n");
        printf("Placar %d, total %d", novaPartida.placarB, equipes[novaPartida.placarB].totalJogadores);
        int jogador = 0;
        int goal = 0;
        for (int j = 0; j < equipes[novaPartida.placarB].totalJogadores; j++)
        {
            if (jogadores[j].idEquipe == novaPartida.placarB)
            {
                printf("%d. %s\n", j + 1, jogadores[j].nome);
            }
        }
        scanf("%d", &jogador);
        printf("Total de Golos: ");
        scanf("%d", &goal);
        while (goal > novaPartida.placarB)
        {
            printf("Quantidade invalida, Insira o total de golos novamente: ");
            scanf("%d", &goal);
        }
        jogadores[jogador--].golsMarcados += goal;
        novaPartida.placarB -= goal;
    }

    partidas[totalPartidas++] = novaPartida;
    printf("Partida registrada com sucesso!\n");
}

void listarPartidasPorCampeonato()
{
    listarCampeonatos();
    printf("Escolha o índice do campeonato: ");
    int idCampeonato;
    scanf("%d", &idCampeonato);
    idCampeonato--;

    if (idCampeonato < 0 || idCampeonato >= totalCampeonatos)
    {
        printf("Campeonato inválido.\n");
        return;
    }

    printf("\n=== Partidas do Campeonato: %s ===\n", campeonatos[idCampeonato].nome);
    for (int i = 0; i < totalPartidas; i++)
    {
        if (partidas[i].idCampeonato == idCampeonato)
        {
            printf("Data: %s, %s %d x %d %s\n",
                   partidas[i].data,
                   equipes[partidas[i].equipeA].nome, partidas[i].placarA,
                   partidas[i].placarB, equipes[partidas[i].equipeB].nome);
        }
    }
}

void listarPartidasPorEquipe()
{
    listarEquipes();
    printf("Escolha o índice da equipe: ");
    int idEquipe;
    scanf("%d", &idEquipe);
    idEquipe--;

    if (idEquipe < 0 || idEquipe >= totalEquipes)
    {
        printf("Equipe inválida.\n");
        return;
    }

    printf("\n=== Partidas da Equipe: %s ===\n", equipes[idEquipe].nome);
    for (int i = 0; i < totalPartidas; i++)
    {
        if (partidas[i].equipeA == idEquipe || partidas[i].equipeB == idEquipe)
        {
            printf("Data: %s, %s %d x %d %s\n",
                   partidas[i].data,
                   equipes[partidas[i].equipeA].nome, partidas[i].placarA,
                   partidas[i].placarB, equipes[partidas[i].equipeB].nome);
        }
    }
}

void menuGerenciamentoPartidas()
{
    int opcao;
    do
    {
        printf("\n=== Gerenciamento de Partidas ===\n");
        printf("1. Registrar Partida\n");
        printf("2. Listar Partidas por Campeonato\n");
        printf("3. Listar Partidas por Equipe\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            registrarPartida();
            break;
        case 2:
            listarPartidasPorCampeonato();
            break;
        case 3:
            listarPartidasPorEquipe();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
