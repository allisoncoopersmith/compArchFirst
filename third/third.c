#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* makeNode(int data){
  struct node* newnode=malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

int search(struct node* hashtable[], int value) {
  int key;
  if (value < 0) {
    key = (value+10000) % 10000;
  }
  else{
  key = value%10000;
}
  if (hashtable[key]==NULL) {
    return 0;
  }
  struct node* ptr = hashtable[key];
  while (ptr != NULL) {
    if (ptr->data == value) {
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}
int checkCollision(struct node* hashtable[], int value) {
  int key;
  if (value < 0) {
    key = (value+ 10000) %10000;
  }
  else {
  key = value%10000;
  }
  if (hashtable[key]==NULL) {
    return 0;
  }
  return 1;

}
int freeNodes (struct node* hashtable[]) {
  int x;
  struct node* ptr=NULL;
  struct node* temp = NULL;
  for (x=0; x<10000; x++) {
      ptr = hashtable[x];
      while (ptr !=NULL) {
        temp = ptr->next;
        free(ptr);
        ptr=temp;
    }
  }
  return 0;
}


int main(int argc, char** argv){
  struct node* hashtable[10000] = {NULL};
  struct node* newNode=NULL;
  int collisionCount=0;
  int searchCount=0;
  char currChar;
  int currNum;
  int collisionChecker;
  int key;

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

    if (currChar == 's') {
      if (search(hashtable, currNum)==1) {
        searchCount++;
      }
    }
    else {
      if (currNum < 0) {
        key = (currNum+10000) % 10000;
      }
      else {
        key = currNum % 10000;

      }
      newNode = makeNode(currNum);
      collisionChecker = collisionCount;
      if (checkCollision(hashtable, currNum)==1) {
        collisionCount++;
      }
      if (collisionChecker == collisionCount) {
        hashtable[key] = newNode;
      }
      if (collisionChecker != collisionCount) {
        struct node* temp=hashtable[key];
        hashtable[key] = newNode;
        newNode->next = temp;
      }

    }
  }
  fclose(fl);
  freeNodes(hashtable);
  printf("%d\n", collisionCount);
  printf("%d\n", searchCount);
  return 0;
}
