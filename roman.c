// Programa de conversao de algarismos romanos para decimal. Questao 2.

#include <stdio.h>
#include <string.h>

// Associa o valor do digito romano.
int dig_conv(char rom_dig)
{
  if (rom_dig == 'I')
    return 1;
  else if (rom_dig == 'V')
    return 5;
  else if (rom_dig == 'X')
    return 10;
  else if (rom_dig == 'L')
    return 50;
  else if (rom_dig == 'C')
    return 100;
  else if (rom_dig == 'D')
    return 500;
  else if (rom_dig == 'M')
    return 1000;
  else
   return -1;
}

// Faz a conversao de numero romano para decimal.
int conv_rom_dec(char *buf)
{
  int len;
  int i;
  int parc_1;
  int parc_2;

  // Variavel de contabilizacao dos digitos:
  int soma = 0;

  len = strlen(buf);
  // loop de conversao :
  for (i = 0; i < len; i++) {
    // calculo do digito corrente :
    parc_1 = dig_conv(buf[i]);

    if ((i + 1) < strlen(buf)) {
      // calculo do digito seguinte :
      parc_2 = dig_conv(buf[i + 1]);

      // compara valores :
      if (parc_1 >= parc_2) {
        soma += parc_1;
      }
      else {
        soma += parc_2;
        soma -= parc_1;
        i++;
      }
    }
    else {
      soma += parc_1;
    }
  }

  return soma;
}

// Funcao main()
int main()
{
  char buf_s[32];
// char buf_s[32] = "MCMVII";
// char buf_s[32] = "MDCCCXXII";
// char buf_s[32] = "MDCDLXXIV";

// scanf do numero romano:
 printf("Informe um numero romano : ");
 scanf("%s", buf_s);

 printf("Valor decimal de numero romano %s = %d\n", buf_s, conv_rom_dec(buf_s));

 return 0;
}
