#include <stdio.h>
#include "../dados.h"

#define ARQUIVO_EQUIPES "equipes.dat"
#define ARQUIVO_JOGADORES "jogadores.dat"
#define ARQUIVO_CAMPEONATOS "campeonatos.dat"
#define ARQUIVO_PARTIDAS "partidas.dat"

// Salva os dados do sistema em arquivos
void salvarDados()
{
  FILE *arquivo;

  // Salvar equipes
  arquivo = fopen(ARQUIVO_EQUIPES, "wb");
  if (arquivo)
  {
    fwrite(&totalEquipes, sizeof(int), 1, arquivo);
    fwrite(equipes, sizeof(Equipe), totalEquipes, arquivo);
    fclose(arquivo);
  }
  else
  {
    perror("Erro ao salvar equipes");
  }

  // Salvar jogadores
  arquivo = fopen(ARQUIVO_JOGADORES, "wb");
  if (arquivo)
  {
    fwrite(&totalJogadores, sizeof(int), 1, arquivo);
    fwrite(jogadores, sizeof(Jogador), totalJogadores, arquivo);
    fclose(arquivo);
  }
  else
  {
    perror("Erro ao salvar jogadores");
  }

  // Salvar campeonatos
  arquivo = fopen(ARQUIVO_CAMPEONATOS, "wb");
  if (arquivo)
  {
    fwrite(&totalCampeonatos, sizeof(int), 1, arquivo);
    fwrite(campeonatos, sizeof(Campeonato), totalCampeonatos, arquivo);
    fclose(arquivo);
  }
  else
  {
    perror("Erro ao salvar campeonatos");
  }

  // Salvar partidas
  arquivo = fopen(ARQUIVO_PARTIDAS, "wb");
  if (arquivo)
  {
    fwrite(&totalPartidas, sizeof(int), 1, arquivo);
    fwrite(partidas, sizeof(Partida), totalPartidas, arquivo);
    fclose(arquivo);
  }
  else
  {
    perror("Erro ao salvar partidas");
  }

  printf("Dados salvos com sucesso!\n");
}

// Carrega os dados do sistema a partir de arquivos
void carregarDados()
{
  FILE *arquivo;

  // Carregar equipes
  arquivo = fopen(ARQUIVO_EQUIPES, "rb");
  if (arquivo)
  {
    fread(&totalEquipes, sizeof(int), 1, arquivo);
    fread(equipes, sizeof(Equipe), totalEquipes, arquivo);
    fclose(arquivo);
  }
  else
  {
    printf("Nenhum dado de equipes encontrado.\n");
  }

  // Carregar jogadores
  arquivo = fopen(ARQUIVO_JOGADORES, "rb");
  if (arquivo)
  {
    fread(&totalJogadores, sizeof(int), 1, arquivo);
    fread(jogadores, sizeof(Jogador), totalJogadores, arquivo);
    fclose(arquivo);
  }
  else
  {
    printf("Nenhum dado de jogadores encontrado.\n");
  }

  // Carregar campeonatos
  arquivo = fopen(ARQUIVO_CAMPEONATOS, "rb");
  if (arquivo)
  {
    fread(&totalCampeonatos, sizeof(int), 1, arquivo);
    fread(campeonatos, sizeof(Campeonato), totalCampeonatos, arquivo);
    fclose(arquivo);
  }
  else
  {
    printf("Nenhum dado de campeonatos encontrado.\n");
  }

  // Carregar partidas
  arquivo = fopen(ARQUIVO_PARTIDAS, "rb");
  if (arquivo)
  {
    fread(&totalPartidas, sizeof(int), 1, arquivo);
    fread(partidas, sizeof(Partida), totalPartidas, arquivo);
    fclose(arquivo);
  }
  else
  {
    printf("Nenhum dado de partidas encontrado.\n");
  }

  printf("Dados carregados com sucesso!\n");
}
