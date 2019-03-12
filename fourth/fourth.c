#include<stdio.h>
#include<stdlib.h>

int main(int argc,char**argv){
  int firstRow;
  int firstColumn;
  int secondRow;
  int secondColumn;
  int a, b, c, d, e, k, l, x, y;

  if (argc < 2) {
  printf ("Error\n");
  return 0;
  }

  FILE* fl;
  fl=fopen(argv[1],"r");

  if (fl == NULL) {
    printf("error\n");
    return 0;
  }

  fscanf(fl,"%d\n",&firstRow);
  fscanf(fl,"%d\n",&firstColumn);

  int first [firstRow][firstColumn];
  for (x=0; x<firstRow; x++){
    for (y=0; y<firstColumn; y++) {
      fscanf(fl, "%d\n", &first[x][y]);
    /*  if (y= firstColumn-1) {
      fscanf(fl, "%d\n", &first[x][y]);
     }
     else {
       fscanf(fl, "%d", &first[x][y]);
     } */
    }
  }
  fscanf(fl,"%d\n",&secondRow);
  fscanf(fl,"%d\n",&secondColumn);

  int second [secondRow][secondColumn];

  if (firstColumn != secondRow) {
    printf ("bad-matrices\n");
    return 0;
  }
  int result [firstRow][secondColumn];
  for (k=0; k<secondRow; k++){
    for (l=0; l<secondColumn; l++) {
      fscanf(fl, "%d\n", &second[k][l]);
    }
  }
  fclose(fl);
  int sum=0;
  for (a = 0; a < firstRow; a++) {
        for (b = 0; b < secondColumn; b++) {
          for (c = 0; c < secondRow; c++) {
            sum = sum + first[a][c]*second[c][b];
          }

          result[a][b] = sum;
          sum = 0;
        }
      }
  for (d = 0; d < firstRow; d++) {
      for (e = 0; e < secondColumn; e++) {
        printf("%d\t", result[d][e]);

    }
    printf("\n");

  }

  return 0;


}
