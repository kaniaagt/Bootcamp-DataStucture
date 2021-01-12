#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Carrick 100 -> Livia 99 -> Valencia 95

struct Node{
    char name[255];
    int score;
    Node *next; //menunjuk ke node selanjutnya
} *head, *tail; //global variabelnya, head dan tail
//head: menunjuk node pertama dalam linked list
//tail: menunjuk ke node terakhir dalam linked list


//char *name sama dengan char name[]
Node *createNode (const char *name, int score) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    //null supaya dia ga nunjuk ke garbage value
    return newNode;
}

//push head, push tail
void pushHead (const char *name, int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    //      jika tidak ada head, maka nodenya akan menjadi head dan tail
    //      jika ada head, node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(name, score); //buat dulu nodenya

    if(!head){ //jika tidak ada head
        head = tail = temp; //maka nodenya akan menjadi head dan tail
    } else { //jika ada head
        temp->next = head; //node menunjuk ke head yang lama
        head = temp; //node akan menjadi head yang baru
    }
}

void pushTail (const char *name, int score){
    Node *temp = createNode(name, score); //buat dulu nodenya

    if(!tail){ //jika tidak ada head
        head = tail = temp; //maka nodenya akan menjadi head dan tail
    } else { //jika ada head
        tail->next = temp; //tail akan menunjuk ke node
        tail = temp; //node akan menjadi tail yang baru
    }
}

void popHead() {
    if(!head){ //jika tidak ada head
        return; //langsung return aja
    } else if (head==tail) {
        free(head);
        head = tail = NULL;
    } else { //53 (head) -> 70 -> 40 -> 25
        Node *temp = head->next; //53 (head) -> 70 (temp) -> 40 -> 25
        head->next = NULL; //53 (head) -> NULL || 70 (temp) -> 40 -> 25
        free(head); //memori head yg lama bakal di alokasikan
        head = temp; //70 (head, temp) -> 40 -> 25
    }
    //karena temp itu local,
    //70 (head) -> 40 -> 25
}

void popTail() {
    if(!head){ //jika tidak ada head
        return; //langsung return aja
    } else if (head==tail) {
        free(head);
        head = tail = NULL;
    } else { //53 (head) -> 70 -> 40 -> 25 (tail)
        Node *temp = head; //53 (head, temp) - > 70 -> 40 -> 25 (tail)
        
        while (temp->next != tail){
            temp = temp->next;
        }
        //53 (head) - >70 -> 40 (temp) -> 25 (tail)
        temp->next = NULL;
        free(tail);
        tail = temp; //53 (head) -> 70 -> 40 (temp, tail) -> NULL
    }
}

void printList() {
    Node *curr = head; //53 (curr, head) -> 70 -> 40 (tail) -> NULL

    while(curr){
        if(curr == head){
            printf(" (head) ");
        } else if (curr == tail) {
            printf(" (tail) ");
        }
        printf("%s %d -> ", curr->name, curr->score);
        curr = curr->next;
    }
    puts("NULL");
}

int main(){
    pushHead("Carrick", 100); //Carrick (head, tail) -> N
    pushTail("Bryan", 90); //Carrick (head) -> Bryan(tail) -> N
    pushTail("Valencia", 95);// Carrick (head) -> Bryan -> Valencia (tail) -> N
    printList();

    return 0;
}