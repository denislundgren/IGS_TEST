// Progarma que verifica acerto de aposta. Questao 5.

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

int **cria_slot(int **slot)
{
#ifdef DEBUG
  int i, j;
#endif
  int col=0;
  int line=0;

  slot = malloc (sizeof(int *) * LINHAS);

  while (line < LINHAS)
    slot[line++] = malloc (sizeof (int) * COLUNAS);

  line = 0;
  while (line < LINHAS)
  {
    printf("Insira os valores da linha %d:\n", (line + 1));
    while (col < COLUNAS)
    {
      scanf("%d", &slot[line][col]);
      col++;
    }
    col = 0;
    line++;
  }

#ifdef DEBUG
  for (i = 0; i < LINHAS; i++)
    for (j = 0; j < COLUNAS; j++)
      printf("i %d j %d slot %d\n", i, j, slot[i][j]);
#endif

  return (slot);
}

int main (void)
{
  int premio[LINHAS][COLUNAS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
  int **slot = 0;
  int lines = 0;
  int cols = 0;
  int count_prize = 0;

  // coleta os numeros dqa aposta:
  slot = cria_slot(slot);

  // compara a aposta com os resultados do sorteio:
  while (lines < LINHAS)
  {
    while (cols < COLUNAS)
    {
      if (slot[lines][cols] == premio[lines][cols])
        count_prize++;
      cols++;
    }
    lines++;
    cols = 0;
  }

  lines = 0;
  while (lines < LINHAS)
    free (slot[lines++]);

  free(slot);

  if (count_prize == (LINHAS * COLUNAS))
    printf ("Gahnou!\n");
  else
    printf("Acertou %d numeros, mas nao ganhou.\n", count_prize);

  return (0);

}
