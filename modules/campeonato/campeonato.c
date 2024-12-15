#include <stdio.h>
#include <string.h>
#include "campeonato.h"
#include "../equipe/equipe.h"
#include "../dados.h"

Campeonato campeonatos[MAX_CAMPEONATOS];
int totalCampeonatos = 0;

void inicializarCampeonatos()
{
    totalCampeonatos = 0;
}

void cadastrarCampeonato()
{
    if (totalCampeonatos >= MAX_CAMPEONATOS)
    {
        printf("Limite de campeonatos atingido.\n");
        return;
    }

    Campeonato novoCampeonato;
    printf("Nome do campeonato: ");
    scanf(" %[^\n]", novoCampeonato.nome);
    printf("Ano de realização: ");
    scanf("%d", &novoCampeonato.anoRealizacao);

    printf("Adicione equipes participantes (mínimo 4, máximo 20):\n");
    listarEquipes();
    int numEquipes;
    printf("Número de equipes: ");
    scanf("%d", &numEquipes);
    if (numEquipes < 4 || numEquipes > 20)
    {
        printf("Número inválido de equipes.\n");
        return;
    }

    for (int i = 0; i < numEquipes; i++)
    {
        printf("Escolha o índice da equipe %d: ", i + 1);
        scanf("%d", &novoCampeonato.equipesParticipantes[i]);
        novoCampeonato.equipesParticipantes[i]--;
    }
    novoCampeonato.totalEquipes = numEquipes;
    novoCampeonato.campeao = novoCampeonato.viceCampeao = novoCampeonato.terceiroColocado = -1;

    campeonatos[totalCampeonatos++] = novoCampeonato;
    printf("Campeonato cadastrado com sucesso!\n");
}

void listarCampeonatos()
{
    if (totalCampeonatos == 0)
    {
        printf("Nenhum campeonato cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalCampeonatos; i++)
    {
        printf("%d. %s (%d) - Total de equipes: %d\n", i + 1, campeonatos[i].nome,
               campeonatos[i].anoRealizacao, campeonatos[i].totalEquipes);
    }
}

void menuGerenciamentoCampeonatos()
{
    int opcao;
    do
    {
        printf("\n=== Gerenciamento de Campeonatos ===\n");
        printf("1. Cadastrar Campeonato\n");
        printf("2. Listar Campeonatos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarCampeonato();
            break;
        case 2:
            listarCampeonatos();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
