/*You are working on a library management system, and you need to implement a Doubly
Linked List to manage the list of books in the library. Each node in the linked list represents a
book, and the list should be doubly linked to support navigation in both forward and backward
directions.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book{
    struct book *lp;
    struct book *rp;
    char title[50];
    char author[50];
    int year;
}book;

book * head = NULL;

void add_book(){
    book * newnode = (book*)malloc(sizeof(book));
    if(newnode==NULL){
        printf("\nMEMORY ALLOCATION FAILED!\n");
    }
    newnode->lp = NULL;
    newnode->rp = NULL;
    printf("Enter title of the book: ");
    scanf("%s", newnode->title);
    printf("Enter name of author of the book: ");
    scanf("%s", newnode->author);
    printf("Enter year of publication of the book: ");
    scanf("%d", &newnode->year);
    if(head == NULL){
        head=newnode;
    }
    else{
        book * temp = head;
        while(temp->rp != NULL){
            temp=temp->rp;
        }
        temp->rp = newnode;
        temp->lp = temp;
    }
}

void delete_book(){
    if(head == NULL){
        printf("\nLIBRARY IS EMPTY!\n");
    }
    char title[50];
    printf("\nEnter title of the book: ");
    scanf("%d", &title);
    book * temp = head;
    while(temp != NULL){
        if(strcmp(temp->title, title)==0){
            if(temp==head){
                head=temp->rp;
                if(head!=NULL){
                    head->lp=NULL;
                }
                free(temp);
                printf("Book %s is removed from the library.\n", title);
                return;
            }
            else{
                temp->lp->rp=temp->rp;
                if(temp->rp!=NULL){
                    temp->rp->lp=temp->lp;
                }
                free(temp);
                printf("Book %s is removed from the library.\n", title);
                return;
            }
        }
        temp=temp->rp;
    }
    printf("Book %s is removed from the library.\n", title);
}

void search(){
    if(head == NULL){
        printf("\nLIBRARY IS EMPTY!\n");
        return;
    }
    char title[50];
    printf("\nEnter the title of the book: ");
    scanf("%s", title);
    book * temp = head;
    while(temp != NULL){
        if(strcmp(temp->title, title)==0){
            printf("\nBOOK FOUND!\n");
            printf("Title: %s, Author: %s, Publication Year: %d\n",temp->title, temp->author, temp->year);
            return;
        }
        temp = temp->rp;
    }
    printf("Book %s is not found in the library.\n", title);
}

void display(){
    book * temp=head;
    int i=0;
    printf("LIBRARY:\n");
    while(temp!=NULL){
        printf("\nBook #%d\nTitle: %s, Author: %s, Publication Year: %d\n", i, temp->title, temp->author, temp->year);
        temp = temp->rp;
        i++;
    }
}

int main(){
    int op, key;
    while(1){
        printf("\nMENU\n1. Add a book\n2. Delete a book\n3. Display the library\n4. Search a book\n\nSelect an option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                add_book();
                break;
            case 2:
                delete_book();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                exit(0);
            default:
                printf("\nINVALID INPUT...\n");
                break;
        }
    }
}