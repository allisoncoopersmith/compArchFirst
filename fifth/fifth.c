#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
int x;

  for (x=1; x<argc; x++) {
    char* input_str = argv[x];
    for (char * t = input_str; *t != 0; t++) {
      if (*t =='a'|| *t =='e' || *t =='i' || *t =='o' || *t =='u' ||
          *t =='A' || *t =='E' || *t =='I' || *t =='O' || *t =='U') {
            printf("%c", *t);
      }

    }

  }
  printf("\n");
  return 0;
}
