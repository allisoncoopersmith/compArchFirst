#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *makeNode(int data){
    struct node *newNode =  (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int data) {
  struct node *newNode = makeNode(data);
  struct node *curr = root;
  struct node *parent = NULL;

  while (curr != NULL) {
    parent = curr;
    if (curr->data <= data) {
      curr = curr->right;
    }
    else {
      curr = curr->left;
    }
  }
  if (parent->data <= data) {
    parent->right =newNode;
  }
  else {
    parent->left = newNode;
  }
  return root;
}

void printTree (struct node *root){
    if (root != NULL)
    {
        printTree(root->left);
        printf("%d\t", root->data);
        struct node *temp = root->right;
        free(root);
        printTree(temp);
    }
}
int iterativeSearch(struct node *root, int newValue) {
    while (root != NULL) {
        if (newValue > root->data){
            root = root->right;
        }
        else if (newValue < root->data) {
            root = root->left;
        }
        else {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv){
  struct node *root = NULL;
  int currNum;
  char currChar;
  if (argc < 2) {
  printf ("error\n");
  return 0;
  }



  FILE* fl;
  fl=fopen(argv[1],"r");

  if (fl == NULL) {
    printf("error\n");
    return 0;
  }
  fscanf(fl,"%c\t%d\n",&currChar,&currNum);

  root = makeNode(currNum);


while(fscanf(fl,"%c\t%d\n",&currChar,&currNum)!=EOF){
    if (iterativeSearch(root, currNum)==1) {
      continue;
    }
    root = insert(root, currNum);
  }
  fclose(fl);
  printTree(root);
  return 0;
}
