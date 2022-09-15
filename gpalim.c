// Programa que identifica sub string palindrome em lista de strings. Questao 1.

#include <stdio.h>
#include <string.h>
#include <errno.h>
 
#define MAX_PATH_SZ 120

extern int errno;

int vet_pos[10000];
int vet_len[10000];
int vet_ret[10000];
int pos_max;

int is_palim(char *buf_s)
{

    int len = 0;
    int ini_len;
    int dec_len;


    ini_len  = dec_len=  strlen(buf_s);
    dec_len -= 1;
    // Keep comparing characters
    // while they are same
    while (dec_len > len) {
        if (buf_s[len++] != buf_s[dec_len--]) {
//  printf("STRINGS %c %c\n", buf_s[len -1],  buf_s[dec_len +1]);
//            printf("%s is not a palindrome, len [%d] dec_len [%d] diff %d\n", buf_s, len, dec_len, dec_len - len);
            return 0;
            // will return from here
        }
    }
 
//    printf("%s is a palindrome\n", buf_s);
 
    return ini_len;
}



int main(int argc,char *argv[])
{
  char buf_s[MAX_PATH_SZ + 1];
  char buf_palim[MAX_PATH_SZ + 1]; 
  int len = 0;
  FILE *fp;

  int i;
  int j;
  int k;
  int len_sub;
  char buf_sub[MAX_PATH_SZ + 1];
  char buf_sub_sub[MAX_PATH_SZ + 1];
  int cont_elem = 0;

  strcpy(buf_s, argv[1]);

  errno = 0;
  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    printf("01 erro no arq %s errno %d\n", argv[1], errno);
    return (2);
  }

  while (fgets(buf_s, MAX_PATH_SZ, fp) != NULL) {

    memset(vet_pos, 0, sizeof(vet_pos));
    memset(vet_len, 0, sizeof(vet_len));
    memset(vet_ret, 0, sizeof(vet_ret));
  
    len =  strlen(buf_s);
  
    buf_s[--len] = 0;
  
    for (i = 0; i < len; i++) {
      strcpy(buf_sub, &buf_s[i]);
      len_sub = strlen(buf_sub);
   
      // pelo menos duas letras para string
      for (j = len_sub; j > 1; j--) {
        strncpy(buf_sub_sub, buf_sub, j);
        buf_sub_sub[j] = 0;
  
        vet_pos[cont_elem] = i;
        vet_len[cont_elem] = j;
        vet_ret[cont_elem] = is_palim(buf_sub_sub);
  
        cont_elem++;
//        printf("SUBSTRING [%s]\n", buf_sub_sub);
      }
  
    }
  
    pos_max = 0;
  
    for (k = 0; k < cont_elem; k++) {
  //    printf("RETURNS pos %d len %d ret %d\n", vet_pos[k], vet_len[k], vet_ret[k]);
      if (vet_ret[k] > vet_ret[pos_max])
        pos_max = k;
    }
  
  
    if (vet_ret[pos_max] > 1) {
      strncpy(buf_palim, &buf_s[vet_pos[pos_max]], vet_len[pos_max]);
      buf_palim[vet_len[pos_max]] = 0;
  
      printf("RESULT string %s PALINDROME %s RETURNS pos %d len %d ret %d\n", buf_s, buf_palim, vet_pos[pos_max], vet_len[pos_max], vet_ret[pos_max]);
    }
    else {
      printf("RESULT string %s Nao ha palindrome\n", buf_s);
    }
  
  }

  fclose(fp);

  return 0;
}
