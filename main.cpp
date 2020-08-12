#include <bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;


typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head, *tail;

} LinkedList;
void init(LinkedList *list)
{

    list->head=NULL;
    list->tail=NULL;
}

Node * newNode(int val)
{
    Node* n=(Node*)malloc(sizeof(8));
    n->data=val;
    n->next=NULL;
    return n;
}

int emptyy(LinkedList *list)
{
    if (list->head==NULL)
        return 1;
    else
        return 0;
}
void addTail(LinkedList *list,int value)
{
    Node *n=newNode(value);
    if(list->head==NULL)
            list->head=list->tail=n;
    else
    {
        Node *OldTail=list->tail;
        list->tail=n;
        OldTail->next=n;
    }
}
void addHead(LinkedList *list,int value) {
    Node *n=newNode(value);
    n->next=list->head;
       list->head=n;
           if(list->tail==NULL)
                    list->tail=n;
           }
void p(LinkedList*list,int i)
{LinkedList*temp=list;

    while(temp->head!=NULL)
    {
        printf("%d ",temp->head->data);
        temp->head=temp->head->next;
    }
 printf("\t at index %d  \n",i);
}
class DoubleHash {
    LinkedList l[13];
    int curr_size;
public:

    bool isFull()
    {
        return (curr_size == 13);
    }

    int hash1(int value)
    {
        return (value % 13);
    }

    DoubleHash()
    {
        curr_size = 0;
         init(&l[0]);
         init(&l[1]);
         init(&l[2]);
         init(&l[3]);
         init(&l[4]);
         init(&l[5]);
         init(&l[6]);
         init(&l[7]);
         init(&l[8]);
         init(&l[9]);
         init(&l[10]);
         init(&l[11]);
         init(&l[12]);

        for (int i = 0; i < 13; i++)
            addTail(&l[i],0);
    }
    void insertHash(int value)
    {
        if (isFull())
            return;
if(l[hash1(value)].head->data==0)
     l[hash1(value)].head->data=value;
else
             addTail(&l[hash1(value)],value);
        curr_size++;
    }

    // function to display the hash table
    void displayHash()
    {
        for (int i = 0; i < 13; i++) {

        p(&l[i],i);

        }
    }
};

int main()
{

  int a[] = { 18,41,22,44};
    int n = sizeof(a) / sizeof(int);
    DoubleHash h;
    for (int i = 0; i < n; i++) {
        h.insertHash(a[i]);
    }
h.displayHash();
return 0;

}


