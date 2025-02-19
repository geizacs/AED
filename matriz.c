#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
    int lin;
    int col;
    int** v;
};


float acessa_matriz (Matriz *mat, int i, int j) {

  return mat->v[i][j];

}

// Atribui v a um elemento da matriz dado por i e j
void atribui_matriz (Matriz *mat, int i, int j, int v) {

  mat->v[i][j] = v;

}

int** aloca_matriz (int n_lin, int n_col) {
  int i;

  int** mat = (int**) malloc (n_lin * sizeof(int*));
  for (i=0;i < n_lin;i++)
      mat[i] = (int*) malloc (n_col * sizeof(int));

  return mat;
}

Matriz* mat_cria (int m, int n) {
    Matriz* mat =  (Matriz*) malloc(sizeof(Matriz));

    mat->v = aloca_matriz(m, n);
    mat->lin = m;
    mat->col = n;

    return mat;
}

/*void imprime_matriz (int** mat, int n_lin, int n_col) {

  int i,j;
  for (i=0;i < n_lin;i++) {
    for (j=0;j < n_col;j++)
      printf ("%d ", mat[i][j]);
    printf ("\n");
  }
}

void imprime_matriz_arquivo (int** mat, int n_lin, int n_col) {
  FILE *sai;
  sai = fopen ("arqsaida.txt", "w");
  //Verifica se arquivo de saida foi aberto corretamente
  if (!sai) {
    printf ("Erro na abertura de saida.txt");
    exit (1);
  }
  int i,j;
  for (i=0;i < n_lin;i++) {
    for (j=0;j < n_col;j++)
      fprintf (sai,"%d ", mat[i][j]);
    fprintf (sai,"\n");
  }
}
*/

void libera_matriz (Matriz* mat, int n_lin) {

  int i;

  for (i=0;i < n_lin;i++)
      free (mat->v[i]);
  free (mat);

}
