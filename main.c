#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
/*the CFG
  S>ABe
  A>dB|aS|e
  B>cS|b
*/
typedef struct node {
    //int val;
    struct node * next;
    char arr[7];//the array to save CFG per line
    }node_t;
void print_list(node_t * root);
void first_set(node_t * root,char c);
char c, temp; int i=0; bool flag = true;
 
    /*node_t * head = malloc(sizeof(node_t));
    node_t * current = malloc(sizeof(node_t));
    node_t * root = malloc(sizeof(node_t));
    head = current;*/ 

int main() {
    node_t * head = malloc(sizeof(node_t));
    node_t * current = malloc(sizeof(node_t));
    node_t * root = malloc(sizeof(node_t));
    head = current;
    
    FILE *fp;
    //char c, temp; int i=0; bool flag = true;
    fp = fopen("cfg.txt", "r");
    while((c = fgetc(fp)) != EOF) {
        if(c == '\n') {
          current->next = malloc(sizeof(node_t));
          //current->next->next = NULL;
          current = current->next;
          current->next = NULL;  
          flag = true; i=0;
        }else if(c == '>' || c == ' '){continue;}
        else if(c == '|'){
            current->next = malloc(sizeof(node_t));
            current = current->next;
            i = 0;
            current->arr[i] = temp;
            i++;
            continue;
        }
         else {
            current->arr[i] = c;
            i++;
            current->next = NULL;
            if(flag){
                temp = c;
                flag = false;
            }
           // continue;
        }
    }
    root = head;
    first_set(root,'B');
    //print_list(root);
    fclose(fp);
}
void print_list(node_t * root) {
    while(root->next != NULL){
        for(i=1; i<7; i++) {
            printf("%c", root->arr[i]);
        }
        printf("\n");
        root = root->next;
    }
}
void first_set(node_t * root,char c){
    node_t * shoot = root;
    while(shoot->next != NULL){
        if(shoot->arr[i] == c){
            if(!(isupper(shoot->arr[i+1]))){
                //first_set(shoot,shoot->arr[i+1]);
                  printf("First of %c is {%c}\n",c,shoot->arr[i+1]);
                  //break;  
                } else{
                     first_set(shoot,shoot->arr[i+1]);
              }
          }
          shoot = shoot->next;
    }
}