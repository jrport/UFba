#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node::node(int num){
        int val = num;
        next = nullptr;
    }
};

class llist{
    private:
    node* head;
    llist::llist(){
        head = nullptr;
    }
    void append(int elem){
        node* temp = nullptr;
        while (temp -> next)
        {
            temp = temp -> next;
        }
        temp -> next = new node(elem);
    }
    void remove(int elem){
        node* temp = head;
        while (temp -> next -> val != elem)
        {
            temp = temp -> next;
        }
        node* temp2 = temp ->next;
        temp -> next = temp2 -> next;
        temp2 -> next = nullptr;
    }
    void check(){
        int count1 = 0;
        int count2 = 0;
        node* temp1 = head;
        node* temp2 = head;
        while (temp1 -> next)
        {
            temp1 = temp1 -> next;
            count1 ++;
            while (temp2 != temp1){
                temp2 = temp2 ->next;
                count2 ++;
            }
            if (count1 != count2){
                cout << "CICLO";
                break;
            }
            count1 = 0;
            count2 = 0;
        }
        
    }
};

class stack{
};