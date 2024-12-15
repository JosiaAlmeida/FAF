#include <stdio.h>
#include <string.h>
#include "jogador.h"
#include "../equipe/equipe.h"
#include "../dados.h"

Jogador jogadores[MAX_JOGADORES];
int totalJogadores = 0;

void inicializarJogadores()
{
    totalJogadores = 0;
}

void cadastrarJogador()
{
    if (totalJogadores >= MAX_JOGADORES)
    {
        printf("Limite de jogadores atingido.\n");
        return;
    }

    Jogador novoJogador;
    printf("Nome do jogador: ");
    scanf(" %[^\n]", novoJogador.nome);
    printf("Idade: ");
    scanf("%d", &novoJogador.idade);
    if (novoJogador.idade < 16 || novoJogador.idade > 40)
    {
        printf("Idade inválida. O jogador deve ter entre 16 e 40 anos.\n");
        return;
    }
    printf("Número da camisa: ");
    scanf("%d", &novoJogador.numeroCamisa);
    printf("Posição (Atacante, Meio-campo, Defesa): ");
    scanf(" %[^\n]", novoJogador.posicao);

    listarEquipes();
    printf("Escolha o índice da equipe do jogador: ");
    scanf("%d", &novoJogador.idEquipe);
    novoJogador.idEquipe--; // Ajusta para índice do array

    if (novoJogador.idEquipe < 0 || novoJogador.idEquipe >= totalEquipes)
    {
        printf("Equipe inválida.\n");
        return;
    }

    novoJogador.golsMarcados = 0;
    jogadores[totalJogadores++] = novoJogador;
    printf("Jogador cadastrado com sucesso!\n");
}

void listarJogadores()
{
    if (totalJogadores == 0)
    {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalJogadores; i++)
    {
        printf("%d. %s, %d anos, camisa %d, posição: %s, Equipe: %d, Gols: %d\n",
               i + 1, jogadores[i].nome, jogadores[i].idade, jogadores[i].numeroCamisa,
               jogadores[i].posicao, jogadores[i].idEquipe + 1, jogadores[i].golsMarcados);
    }
}

void atualizarJogador()
{
    listarJogadores();
    printf("Escolha o índice do jogador para atualizar: ");
    int indice;
    scanf("%d", &indice);
    if (indice < 1 || indice > totalJogadores)
    {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para índice do array

    printf("Novo nome (atual: %s): ", jogadores[indice].nome);
    scanf(" %[^\n]", jogadores[indice].nome);
    printf("Nova idade (atual: %d): ", jogadores[indice].idade);
    scanf("%d", &jogadores[indice].idade);
    printf("Novo número da camisa (atual: %d): ", jogadores[indice].numeroCamisa);
    scanf("%d", &jogadores[indice].numeroCamisa);
    printf("Nova posição (atual: %s): ", jogadores[indice].posicao);
    scanf(" %[^\n]", jogadores[indice].posicao);
    printf("Jogador atualizado com sucesso!\n");
}

void menuCadastroJogadores()
{
    int opcao;
    do
    {
        printf("\n=== Cadastro de Jogadores ===\n");
        printf("1. Cadastrar Jogador\n");
        printf("2. Listar Jogadores\n");
        printf("3. Atualizar Jogador\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarJogador();
            break;
        case 2:
            listarJogadores();
            break;
        case 3:
            atualizarJogador();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
