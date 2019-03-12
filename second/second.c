#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

node* makeNode(int data,node* head){
  struct node* newnode=malloc(sizeof(node));
  newnode->data=data;
  newnode->next=head;
  return newnode;
}

void sort(node* head, int size) {
  struct node* tempNode = NULL;
  int k, l, temp;
  int count=0;
  int numbers[size];
  while (head !=NULL) {
    numbers[count] = head->data;
    count++;
    tempNode = head->next;
    free(head);
    head = tempNode;
  }
  free(tempNode);
  for(k=0;k<size-1;k++){
    for(l=k+1;l<size;l++){
      if(numbers[l]<= numbers[k]){
        temp=numbers[l];
        numbers[l]=numbers[k];
        numbers[k]=temp;
      }
    }
  }
  int ptr = 0;
  printf("%d\n", count);
  printf("%d\t", numbers[0]);
  for (k=1; k<count; k++) {
    if (numbers[k] == numbers[ptr]) {
      continue;
    }
    printf("%d\t", numbers[k]);
    ptr=k;
  }
  printf("\n");

}

int main(int argc, char** argv){
  struct node* head=NULL;
  struct node* ptr=NULL;
  struct node* prev=NULL;
//  boolean found = false;
  int currNum, count=0;
  char currChar;
  if (argc != 2) {
    printf("error\n");
    return 0;
  }

  FILE *fl;
  fl=fopen(argv[1],"r");

  if(fl==NULL){
    printf("error\n");
    return 0;
  }

  while(fscanf(fl,"%c\t%d\n",&currChar,&currNum)!=EOF){


    if(currChar=='i'){
      head=makeNode(currNum,head);
      count++;
    }

    else if(currChar=='d' && count > 0){

        ptr=head->next;
        prev=head;
        if (prev->data == currNum) {
          free(head);
          head=ptr;
          count--;
          continue;
        }
        while(ptr!=NULL){
          if(ptr->data==currNum){
            prev->next=ptr->next;
            free(ptr);
            count--;
            break;

        }
        prev=ptr;
        ptr=ptr->next;
      }

    }
  }


  fclose(fl);
  if (count==0) {
    printf("%d\n", 0);
    return 0;
  }
  sort(head, count);
  return 0;
}
