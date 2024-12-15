#include <stdio.h>
#include <string.h>
#include "equipe.h"
#include "../dados.h"

Equipe equipes[MAX_EQUIPES];
int totalEquipes = 0;

void inicializarEquipes()
{
    totalEquipes = 0;
}

void cadastrarEquipe()
{
    if (totalEquipes >= MAX_EQUIPES)
    {
        printf("Limite de equipes atingido.\n");
        return;
    }

    Equipe novaEquipe;
    printf("Nome da equipe: ");
    scanf(" %[^\n]", novaEquipe.nome);
    printf("Cidade: ");
    scanf(" %[^\n]", novaEquipe.cidade);
    printf("Ano de fundacao: ");
    scanf("%d", &novaEquipe.anoFundacao);
    printf("Treinador: ");
    scanf(" %[^\n]", novaEquipe.treinador);

    novaEquipe.totalJogadores = 0;
    equipes[totalEquipes++] = novaEquipe;
    printf("Equipe cadastrada com sucesso!\n");
}

void listarEquipes()
{
    if (totalEquipes == 0)
    {
        printf("Nenhuma equipe cadastrada.\n");
        return;
    }
    for (int i = 0; i < totalEquipes; i++)
    {
        printf("%d. %s - %s (Fundada em %d)\n", i + 1, equipes[i].nome, equipes[i].cidade, equipes[i].anoFundacao);
    }
}

void atualizarEquipe()
{
    listarEquipes();
    printf("Escolha o índice da equipe para atualizar: ");
    int indice;
    scanf("%d", &indice);
    if (indice < 1 || indice > totalEquipes)
    {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para índice do array
    printf("Novo nome (atual: %s): ", equipes[indice].nome);
    scanf(" %[^\n]", equipes[indice].nome);
    printf("Nova cidade (atual: %s): ", equipes[indice].cidade);
    scanf(" %[^\n]", equipes[indice].cidade);
    printf("Novo ano de fundação (atual: %d): ", equipes[indice].anoFundacao);
    scanf("%d", &equipes[indice].anoFundacao);
    printf("Novo treinador (atual: %s): ", equipes[indice].treinador);
    scanf(" %[^\n]", equipes[indice].treinador);
    printf("Equipe atualizada com sucesso!\n");
}

void menuCadastroEquipes()
{
    int opcao;
    do
    {
        printf("\n=== Cadastro de Equipes ===\n");
        printf("1. Cadastrar Equipe\n");
        printf("2. Listar Equipes\n");
        printf("3. Atualizar Equipe\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarEquipe();
            break;
        case 2:
            listarEquipes();
            break;
        case 3:
            atualizarEquipe();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
