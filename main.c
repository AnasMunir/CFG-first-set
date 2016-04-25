#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
/*the CFG
  S>ABe
  A>dB|eS|e
  B>AS|b
*/
typedef struct node {
    //int val;
    struct node * next;
    char arr[20];//the array to save CFG per line
    }node_t;
int main() {
    node_t * head = malloc(sizeof(node_t));
    node_t * current = malloc(sizeof(node_t));
    node_t * root = malloc(sizeof(node_t));
    head = current;
    
    FILE *fp;
    char c, temp; int i; bool flag = true;
    fp = fopen("cfg.txt", "r");
    while((c = fgetc(fp)) != EOF) {
        if(c == '\n') {
          current->next = malloc(sizeof(node_t));
          //current->next->next = NULL;
          current = current->next;
          current->next = NULL;  
          flag = true;
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
    while(root->next != NULL){
        for(i=0; i<20; i++) {
            printf("%c", root->arr[i]);
        }
        printf("\n");
        root = root->next;
    }
    fclose(fp);
}
