#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class LinkedList
{
public:

    node *head;
    int sizee; //for maintaining the size

    LinkedList()
    {
        head=NULL;
        sizee=0; //initially size=0;
    }
    ///create new node
    node *createNewNode(int value)
    {
        node *newNode= new node;
        newNode->data=value;
        newNode->next=NULL;
        return newNode;
    }

    void insertAtHead(int value)
    {
        sizee++; //if we insert anything then size will be increase automatically
        node *a=createNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        ///if head is not NULL
        a->next = head;
        head = a;
    }
    void insertAtanyIndex(int index,int value)
    {
        if(index==0)
        {
            insertAtHead(value);
            return;
        }
        sizee++;
        node* a=head;
        int curr_index=0;
        while(curr_index != index-1)
        {
            a= a->next;
            curr_index++;
        }
        node* newNode = createNewNode(value);
        newNode->next= a->next;
        a->next=newNode;
    }

    ///prints the linked list value
    void Traverse()
    {
        node *a=head;
        while(a!=NULL)
        {
            cout<< a->data<< " ";
            a = a->next;
        }
        cout << "\n";
    }
    int SerachDistinctValue(int value)
    {
        node* a=head;
        int index=0;
        while(a != NULL)
        {
            if(a->data == value)
            {
                return index;
            }
            a= a->next;
            index++;
        }
        return -1;
    }
    void SearchAllValue(int value)
    {
        node* a=head;
        int index=0;
        while(a != NULL)
        {
            if(a->data == value)
            {
                cout<< value << " is found at "<< index << "\n";
            }
            a= a->next;
            index++;
        }
    }
    int getSize()
    {
        return sizee;
    }
    void deleteAtHead()
    {
        if(head==NULL) return;
        sizee--;

        node *a= head;
        head= a->next;
        delete a;
    }
    void deleteAtAnyPos(int index)
    {
        if(index<0 || index>sizee-1)
            return;
        if(head==NULL)
        {
            deleteAtHead();
            return;
        }
        sizee--;

        node* a= head;
        int curr_index=0;
        while(curr_index != index-1)
        {
            a= a->next;
            curr_index++;
        }
        node* b= a->next;
        a->next= b->next;
        delete b;
    }
    void insetAfterValue(int value,int data)
    {
        node* a=head;
        while(a!=NULL)
        {
            if(a->data==value)
            {
                break;
            }
            a= a->next;
        }
        if(a== NULL)
        {
            cout<< value<< "doesn't exist in linked-list.\n";
            return;
        }
        sizee++;
        node* newNode= createNewNode(data);
        newNode->next= a->next;
        a->next =newNode;
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
};
int main()
{
    LinkedList l;

    l.insertAtHead(10);
    l.insertAtHead(30);
    l.insertAtHead(20);
    l.insertAtHead(50);
    l.insertAtanyIndex(0,100);

    l.Traverse();

    cout<< "10 is found at "<<l.SerachDistinctValue(10)<< "\n";
    cout<< "10 is found at "<<l.SerachDistinctValue(5)<< "\n";

    l.SearchAllValue(30);
    cout<< l.getSize()<< "\n";
    l.deleteAtHead();
    l.Traverse();
    cout<< l.getSize()<< "\n";

    l.deleteAtAnyPos(1);
    l.Traverse();
    cout<< l.getSize()<< "\n";
    l.insetAfterValue(30,999);
    l.Traverse();
    cout<< l.getSize()<< "\n";
    l.reversePrint();
    return 0;
}
