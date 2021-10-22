//program to merge two sorted linkedlist(external space)
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void push(node** head_ref,int data){
    node* temp = new node(data);
    //check if linkedlist is empty
    if(*head_ref==NULL){
        *head_ref=temp;
        return;
    }
    else{
        temp->next=*head_ref;
        *head_ref=temp;
        return;
    }
}

void print(node** head_ref){
    node* temp=*head_ref;
    //check if linkedlist is empty
    if(temp==NULL){
        cout<<"LinkedList is empty";
        return;
    }
    else{
        cout<<"LinkedList: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return;
    }
}

node* merge(node** head_ref1,node** head_ref2){
    node *a=*head_ref1,*b=*head_ref2;
    node* dummy; //dummy node to get started
    dummy->next=NULL; 
    node* c = dummy;
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){ //here we check if a->data < b->data this will complete both lists or any one list completely
            c->next = a;
            a = a->next;
        }
        else{
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }
    while(a!=NULL){  //if a has remaining elements we add it to dummy list till it becomes empty
        c->next = a;
        a = a->next;
        c = c->next;
    }
    while(b!=NULL){ //if b has remaining elements we add it to dummy list till it becomes empty
        c->next = b;
        b = b->next;
        c = c->next;
    }
    return dummy->next;  //finally we return dummy->next here since we have traveresed in linkedlist c till last
}

int main(){
    node *head1=NULL,*head2=NULL;
    int arr1[]={9,7,5,3,1};
    int arr2[]={8,6,4,2,0};
    for(int i=0;i<5;i++){
        push(&head1,arr1[i]);
    }
    for(int i=0;i<5;i++){
        push(&head2,arr2[i]);
    }
    node* head3=merge(&head1,&head2);
    print(&head3);
    return 0;
}