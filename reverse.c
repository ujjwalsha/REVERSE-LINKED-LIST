#include<stdio.h>
#include<stdlib.h>

//REVERSE THE LINKED LIST 

struct node{
    int info;
    struct node* ptr;
};

struct node* START =NULL;

struct node4* createNode(){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void insert_end(){
struct node* temp, *t;

    temp = createNode();
    printf("enter your number : ");
    scanf("%d", &temp->info);

    temp->ptr = NULL;
    if(START == NULL)
        START = temp;
    else{
        t = START;
        while(t->ptr != NULL)
            t = t->ptr;
        t->ptr= temp;
    }
}

void reverse(){
   struct node* prev = NULL;
    struct node* curr = START;
    struct node* forward = NULL;
    while(curr != NULL){
        forward = curr->ptr;
        curr->ptr = prev;
        prev = curr;
        curr = forward;
    }
    START = prev;

}

void display(){
    struct node* t;
    if(START == NULL)
     printf("list is empty");

    else{
        t = START;
        while(t!=NULL){
            printf(" %d", t->info);
            t = t->ptr;
        }
    }
}

void main(){
    int choice;
    while(1){
        printf("\n1 insert the element ");
        printf("\n 2. display the list  ");
        printf("\n 3. reverse the list  ");
        printf("\n 4. exiting the program ");

        printf("\n enter your choice ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            insert_end();
            break;

            case 2:
            display();
            break;

            case 3:
            reverse();
            break;

            case 4:
            exit(0);

            default:
            printf("invalid choice");
        }

    }
}