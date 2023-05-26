#include <iostream>
#include <set>

class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class linked_list {
    public:
    node* head;  
    linked_list(){
        head = nullptr;
    }
    void append(int new_num){
        node* new_val;
        new_val = new node(new_num);
        if (head == nullptr){
            head = new_val;
        }
        else{
            node* cur = head;
            while (cur->next!=nullptr){
                cur = cur->next;
            }
            cur -> next = new_val;
        }
    }
    void display(){
        if (head != nullptr) {
            node* cur = head;
            printf("Lista Encadeada:\n%d ",cur->data);
            while (cur->next!=nullptr){
                cur = cur->next;
                printf("%d ",cur->data);
            };
            std::cout<<"\n";
        }
        else {
            printf("Lista Vazia! \n");
        }
    }
    void free(){
        head = nullptr;
    }
    void insert_begin(int new_val){
        node* new_elem = new node(new_val);
        new_elem -> next = head;
        head = new_elem;
    }
    void insert_lista(int indice, int new_val){
        node* cur = head;
        node* new_elem = new node(new_val);
        if (indice>0){
            for (int i = 0; i<indice-1;i++){
                cur = cur->next;
            }
            new_elem->next = cur->next;
            cur -> next = new_elem;
        }
        else{
            insert_begin(new_elem->data);
        }
    }
    void no_repeat(){
        std::set <int> unique_elem;
        linked_list sem_rep;
        node *cur = head;
        while (cur->next != nullptr)
        {
            unique_elem.insert(cur->data);
            cur = cur->next;
        }
        for (int i:unique_elem){
            sem_rep.append(i);
        }
        head = sem_rep.head;
    }
};

class stack {
    public:
    node* head;
    stack(){
        head = nullptr;
    }
    void push(int new_val){
        node* new_elem = new node(new_val);
        if (head == nullptr) {
            head = new_elem;
        }
        else{
            node* cur = head;
            while (cur->next!=nullptr){
                cur = cur->next;
            }
            cur->next=new_elem; 
        }
    }
    void pop(){
        if (head == nullptr) {
            std::cout<<"Pilha Vazia!";
        }
        else{
            node* cur = head;
            while (cur->next->next!=nullptr){
                cur = cur->next;
            }
            printf("%d ",cur->next->data);
            cur -> next = nullptr;
            if (cur == head){
                printf("%d",head->data);
                }
        }
    }   
};

class double_list {
    public:
    node* head;
    double_list(){
        head = nullptr;
    };
    void display(){
        node * temp;
        temp = head;
        if (temp == nullptr){
            std::cout<<"Lista Vazia!";
        }
        else {
            std::cout<<"Lista Duplamente Encadeada: [";
            while (temp->next!=nullptr){
                printf("%d ",temp->data);
                temp = temp->next;
            }
        }
    };
    void append(int elem){
        node* new_elem;
        new_elem = new node(elem);
        if (head == nullptr){
            head = new_elem;
        }
        else{
            node* temp;
            temp = head;
            while (temp->next!=nullptr){
                temp = temp->next;
            }
            temp -> next = new_elem;
            new_elem -> prev = temp;
        }
    }
    void search_sub(node* sublist){ 
        node* search_node;
        node* main_node;
        node* lista_fim = head;
        linked_list* path;
        main_node = head;
        search_node = sublist;
        path = new linked_list;
        while (head ==)
    }
    void free_list (){
        head = nullptr;
    }
};

int main(){
}