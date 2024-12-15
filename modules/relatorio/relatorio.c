#include <stdio.h>
#include "relatorio.h"
#include "../campeonato/campeonato.h"
#include "../jogador/jogador.h"
#include "../equipe/equipe.h"
#include "../dados.h"

void gerarRelatorioCampeonatos()
{
    printf("\n=== Relatório de Campeonatos ===\n");
    for (int i = 0; i < totalCampeonatos; i++)
    {
        printf("Campeonato: %s (%d)\n", campeonatos[i].nome, campeonatos[i].anoRealizacao);
        printf("Campeão: %s, Vice: %s, Terceiro: %s\n",
               campeonatos[i].campeao >= 0 ? equipes[campeonatos[i].campeao].nome : "N/A",
               campeonatos[i].viceCampeao >= 0 ? equipes[campeonatos[i].viceCampeao].nome : "N/A",
               campeonatos[i].terceiroColocado >= 0 ? equipes[campeonatos[i].terceiroColocado].nome : "N/A");
    }
}

void calcularMediaIdade()
{
    printf("\n=== Média de Idade por Equipe ===\n");
    for (int i = 0; i < totalEquipes; i++)
    {
        int somaIdades = 0, totalJogadoresEquipe = 0;
        for (int j = 0; j < totalJogadores; j++)
        {
            if (jogadores[j].idEquipe == i)
            {
                somaIdades += jogadores[j].idade;
                totalJogadoresEquipe++;
            }
        }
        double media = totalJogadoresEquipe > 0 ? (double)somaIdades / totalJogadoresEquipe : 0.0;
        printf("Equipe %s: %.2f anos\n", equipes[i].nome, media);
    }
}

void listarArtilheiros()
{
    printf("\n=== Artilheiros ===\n");
    for (int i = 0; i < totalJogadores; i++)
    {
        if (jogadores[i].golsMarcados > 0)
        {
            printf("%s (Equipe: %s) - %d gols\n",
                   jogadores[i].nome,
                   equipes[jogadores[i].idEquipe].nome,
                   jogadores[i].golsMarcados);
        }
    }
}

void consultarGolsJogador()
{
    listarJogadores();
    printf("Escolha o índice do jogador: ");
    int idJogador;
    scanf("%d", &idJogador);
    idJogador--;

    if (idJogador < 0 || idJogador >= totalJogadores)
    {
        printf("Jogador inválido.\n");
        return;
    }

    printf("Jogador: %s, Total de gols: %d\n",
           jogadores[idJogador].nome, jogadores[idJogador].golsMarcados);
}

void menuRelatorios()
{
    int opcao;
    do
    {
        printf("\n=== Relatórios e Estatísticas ===\n");
        printf("1. Relatório de Campeonatos\n");
        printf("2. Média de Idade por Equipe\n");
        printf("3. Listar Artilheiros\n");
        printf("4. Consultar Gols de um Jogador\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            gerarRelatorioCampeonatos();
            break;
        case 2:
            calcularMediaIdade();
            break;
        case 3:
            listarArtilheiros();
            break;
        case 4:
            consultarGolsJogador();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
