#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "equipe/equipe.h"
#include "jogador/jogador.h"
#include "campeonato/campeonato.h"
#include "partida/partida.h"
#include "relatorio/relatorio.h"
#include "persistencia/persistencia.h"
#include "dados.h"

void exibirMenu();

void inicializarSistema()
{
    totalEquipes = 0;
    totalJogadores = 0;
    totalCampeonatos = 0;
    totalPartidas = 0;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    inicializarSistema(); // Inicializa dados, pode carregar de arquivos

    int opcao;
    do
    {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            menuCadastroEquipes();
            break;
        case 2:
            if (totalEquipes == 0)
                printf("Precisa de equipa cadastrada.\n\n");
            else
                menuCadastroJogadores();
            break;
        case 3:
            menuGerenciamentoCampeonatos();
            break;
        case 4:
            menuGerenciamentoPartidas();
            break;
        case 5:
            menuRelatorios();
            break;
        case 0:
            printf("Saindo...\n");
            salvarDados(); // Salva dados persistentes
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void exibirMenu()
{
    printf("\n=== Sistema da Federação Angolana de Futebol ===\n");
    printf("1. Gerenciamento de Equipes\n");
    printf("2. Gerenciamento de Jogadores\n");
    printf("3. Gerenciamento de Campeonatos\n");
    printf("4. Registro de Partidas\n");
    printf("5. Relatórios e Estatísticas\n");
    printf("0. Sair\n");
}
