// Programa de print de gardacao de cores. Questao 3.
#include <stdio.h>
#include <string.h>

// Funcao main()
int main()
{
  int cor;
  int cor_inicial = 0x00001A;
  int cor_final = 0xFF001A;
  int cont_steps = 0;
  int steps = 0;
  int soma_range = 0;

  printf("Informe o numero de passos de gradacao da cor : ");
  scanf("%d", &steps);

  soma_range = 0xFF / steps;

  soma_range <<= 16;

//  printf("%08X\n", cor_inicial);

  cor = cor_inicial;

  while (cont_steps < steps) {
    cor += soma_range;
    cont_steps++;
    if (cont_steps < steps) 
      printf("%08X\n", cor);
    else 
      printf("%08X\n", cor_final);
  }

  return 0;
}
