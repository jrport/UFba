#include <iostream>

class node{
    public:
    node* next;
    int data,
    node(int n){
        data = n;
        next = nullptr;
    }
};

class linked_list{
    public:
    node* head;
    linked_list(){
        node* head = nullptr;
    }
    void append(int n){
        node* new_elem = new node(n);
        if (head == nullptr){
            head = new_elem;
        }
        else{
            node* temp = head;
            while (temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = new_elem;
        }
    }
    void remove(int index){
        node* temp = head;
        node* temp1 = nullptr;
        node* prox = nullptr;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        temp1 = temp -> next;
        prox = temp->next->next;
        temp->next = nullptr;
        temp->next = prox;
        temp1->next = nullptr;
    }
    void insert(int nelem,int index){
        node* new_elem = new node(nelem);
        node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        new_elem->next = temp->next;
        temp->next=new_elem;
    }
    void display(){
        if (head == nullptr){
            printf("LISTA VAZIA");
        }
        else{
            node* temp = head;
            std::cout<<"Lista:";
            while (temp->next!=nullptr){
                printf("%d",temp->data);
                temp = temp->next;
            }
        }
    }
};