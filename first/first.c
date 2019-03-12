#include<stdio.h>
#include<stdlib.h>



int main(int argc,char**argv){

int num;

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

fscanf(fl,"%d\n",&num);

int even[num];
int odd[num];
int evenCount=0;
int oddCount=0;
int i;
for(i=0;i<num;i++){
  int temp;
   fscanf(fl,"%d\t",&temp);

    if (temp % 2 ==0) {
    even[evenCount]=temp;
    evenCount++;
    }
    else {
    odd[oddCount]=temp;
    oddCount++;

    }
  }
  fclose(fl);
  int tempEven=0;
  int k;
  int l;
  for(k=0;k<evenCount-1;k++){
    for(l=k+1;l<evenCount;l++){
      if(even[l]<even[k]){
        tempEven=even[l];
        even[l]=even[k];
        even[k]=tempEven;
      }
    }
  }

    int tempOdd=0;
    int f;
    int g;
    for(f=0;f<oddCount-1;f++){
      for(g=f+1;g<oddCount;g++){
        if(odd[g]>odd[f]){
          tempOdd=odd[g];
          odd[g]=odd[f];
          odd[f]=tempOdd;
        }
      }
    }





  int b;
    for (b=0; b<oddCount; b++) {
//      printf("This integer is %d\n", even[b]);
    even[evenCount] = odd[b];
    evenCount++;
    }
  int w;
  for(w = 0; w<num; w++){
      printf("%d\t", even[w]);

    }
  printf("\n");

  return 0;

}
