#include<bits/stdc++.h>
using namespace std;

///structure of node
class node
{
public:
    int data;
    node* next;
    node* prev;
};
///structure of doubly linked list
class doublyLinkedList
{
public:
    node* head;
    int sizee;

    doublyLinkedList()
    {
        head = NULL;
        sizee = 0;
    }
    node* createnewnode(int data)
    {
        node* newnode= new node;
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;

        return newnode;
    }
    void insertAtHead(int data)
    {
        sizee++;
        node* newnode = createnewnode(data);
        if(head==NULL)
        {
            head = newnode;
            return;
        }
        node* a=head;

        newnode->next=a;
        a->prev=newnode;
        head=newnode;
    }
    void insertAtanyIndex(int index, int data)
    {
        if(index > sizee)
        {
            return;
        }
        if(index == 0)
        {
            insertAtHead(data);
            return;
        }
        node* a =head;
        int curr_idx=0;
        while(curr_idx != index-1)
        {
            a=a->next;
            curr_idx++;
        }
        node* newnode= createnewnode(data);
        newnode->next=a->next;
        newnode->prev=a;
        a->next->prev=newnode;
        a->next=newnode;
        sizee++;
    }
    void deleteAtanyIndex(int index)
    {
        if(index >=sizee)
        {
            cout<< index << " doesn't exist.\n";
            return;
        }
        node* a=head;
        int curr_idx=0;
        while(curr_idx != index)
        {
            a= a->next;
            curr_idx++;
        }
        node* b= a->prev;
        node* c= a->next;

        if(b!=NULL) b->next=c;

        if(c!=NULL) c->prev=b;
        delete a;
        if(index==0)
        {
            head = c;
        }
        sizee--;
    }
    void reversePrint2(node* a)
    {
        if(a==NULL) return;
        reversePrint2(a->next);
        cout<< a->data << " ";
    }
    void reversePrint()
    {
        reversePrint2(head);
        cout<< "\n";
    }

    int getSize()
    {
        return sizee;
    }
    void traverse()
    {
        node* a=head;
        while(a!=NULL)
        {
            cout<< a->data << " ";
            a = a->next;
        }
        cout<< "\n";
    }
};
int main()
{
    doublyLinkedList dl;
    dl.insertAtHead(10);
    dl.insertAtHead(5);
    dl.insertAtHead(1);

    dl.traverse();
    dl.insertAtanyIndex(2,100); // 2 no position e 100 insert
    dl.traverse();
    dl.deleteAtanyIndex(3);
    dl.traverse();
    cout<< dl.getSize()<< "\n";
    dl.reversePrint();

    return 0;
}
