#include <stdio.h>
#include <string.h>
#include "equipe.h"
#include "../dados.h"
#include "../utils/validate.h"

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

    do
    {
        printf("Nome da equipe: ");
        scanf(" %[^\n]", novaEquipe.nome);
    } while (!validateField(novaEquipe.nome, "Nome da equipe"));

    do
    {
        printf("Cidade: ");
        scanf(" %[^\n]", novaEquipe.cidade);
    } while (!validateField(novaEquipe.cidade, "Cidade"));

    printf("Ano de fundação: ");
    while (scanf("%d", &novaEquipe.anoFundacao) != 1 || novaEquipe.anoFundacao < 1800 || novaEquipe.anoFundacao > 2100)
    {
        printf("Ano inválido. Digite novamente: ");
        while (getchar() != '\n')
            ;
    }

    do
    {
        printf("Treinador: ");
        scanf(" %[^\n]", novaEquipe.treinador);
    } while (!validateField(novaEquipe.treinador, "Treinador"));

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
        printf("%d. %s - %s (Fundada em %d), treinador: %s\n", i + 1, equipes[i].nome, equipes[i].cidade, equipes[i].anoFundacao, equipes[i].treinador);
    }
}

void atualizarEquipe()
{

    if (totalEquipes == 0)
    {
        printf("Nenhuma equipe cadastrada para atualizar.\n");
        return;
    }
    listarEquipes();

    printf("Escolha o índice da equipe para atualizar: ");
    int indice;
    scanf("%d", &indice);
    if (indice < 1 || indice > totalEquipes)
    {
        printf("Índice inválido.\n");
        return;
    }
    indice--;

    do
    {
        printf("Novo nome (atual: %s): ", equipes[indice].nome);
        scanf(" %[^\n]", equipes[indice].nome);
    } while (!validateField(equipes[indice].nome, "Nome da equipe"));

    do
    {
        printf("Nova cidade (atual: %s): ", equipes[indice].cidade);
        scanf(" %[^\n]", equipes[indice].cidade);
    } while (!validateField(equipes[indice].cidade, "Cidade"));

    printf("Novo ano de fundação (atual: %d): ", equipes[indice].anoFundacao);
    while (scanf("%d", &equipes[indice].anoFundacao) != 1 || equipes[indice].anoFundacao < 1800 || equipes[indice].anoFundacao > 2100)
    {
        printf("Ano inválido. Digite novamente: ");
        while (getchar() != '\n')
            ;
    }

    do
    {
        printf("Novo treinador (atual: %s): ", equipes[indice].treinador);
        scanf(" %[^\n]", equipes[indice].treinador);
    } while (!validateField(equipes[indice].treinador, "Treinador"));
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
