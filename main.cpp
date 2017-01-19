#include <iostream>
#include <stdlib.h>
using namespace std;

   typedef struct tree{  //typedef pentru a putea declara direct node * root; in loc de struct tree * rootl
    int key;//cheia
    tree *lft; //pointer spre dereapta
    tree *rgh; //pointer spre stanga
    tree *parent; //pointer spre parinte
    }node;

    node* miniTree(node* z) // structura arborelui face ca el minimul sa fie cea mai din stanga frunza
    {
    if(z->lft!=NULL)
        return miniTree(z->lft);//-> n loc de (*z).left
    else
        return z;
    }
    node *succesor(node *z) // succesorul este cel mai din stanga nod din partea dreapta a copiilor
    { //tipul este node* pt ca returneaza un pointer de tipul structurii tree z->rgh ii un pointer
        if(z->rgh!=NULL)//daca pointerul exista este diferit de null(nill)
            return z->rgh;//successorul este primul fiu din dreapta daca exista, dc nu si nu este nodul cu cheie max succesorul esteprimul parinte ce are nodul nostru urmas undeva ,in jos,in stanga
            node * y= (node*) malloc(sizeof(node)); // aloc memorie pt un pointer
            y=z->parent;//merg in sus pt a gasi succesorul, pana cand nodul nu mai este pe partea stanga a succesorului (tatal in acest caz);
            while(y!=NULL&&y->rgh==z) // verifi ce am zis mai sus, daca nodul tau ii in dreapta altui nod atunci acela nu este succesorul
            {
                z=y;
                y=y->parent;
            }
            return y;
    }
    void treeInsertion(node *z,node *x)
    {
        node *y=(node*)malloc(sizeof(node));
        y=NULL;
        while(x!=NULL)
            {
                y=x;
                if((z->key)>x->key)
                    x=x->rgh;
                else
                    x=x->lft;
            }
            z->parent=y;
        if(y->lft==NULL)
            y->lft=z;
        else
            y->rgh=z;
            cout<<z->parent<<" ";
    }

   void treeDeletion(node* z)
    {
        node * y= (node*)malloc(sizeof(node));
        node *x = (node*)malloc(sizeof(node));
        if(z->rgh==0||z->lft==NULL)
            y=z;
        else
            y=succesor(z);

            if(y->lft!=NULL)
                x=y->lft;
            else
                x=y->rgh;

            if (x!=NULL)
               {
                   if(y->parent!=NULL)
                x->parent=y->parent;
            else
                cout<<"x is the root";
               }
                if((y->parent)->lft!=NULL)
                    (y->parent)->lft=x;
                else
                    (y->parent)->lft=x;

                    if(y!=z)z->key=y->key;

    }
    node* keySearch(int a, node *root) //cauta o cheie in arbore pt eliminare iti trebuie nodul ca structura dar tu vezi doar cheia
    {                                   //functia returneaza nodul ca structura in functie de cheia ceruta
        node * y=(node*)malloc(sizeof(node));
        y=root;
        while(a!=y->key&&y!=NULL)
        if(y->key>a)
            y=y->lft;
            else
                y=y->rgh;
            return y;
    }
   void treeInorder(node* in)
   {

       if(in!=NULL)
        {
         treeInorder(in->lft);
       cout<<in->key<<" ";
        treeInorder(in->rgh);
        }
   }
int main()
{
    int a,i=1,n,b;
    cin>>n;
    cin>>b;
     node * root=(node*)malloc(sizeof(node));
     root->key=b;// rebuie initializat cu null ca singur nu se initializeaza
     root->lft=NULL;
     root->parent=NULL;
     root->rgh=NULL;
    while(i<n)
    {
        cin>>a;
        node * leaf=(node*)malloc(sizeof(node));
       leaf->key=a;
       leaf->lft=NULL;
       leaf->rgh=NULL;
        treeInsertion(leaf,root);
    i++;
    }
    treeInorder(root);
    treeDeletion(keySearch(4,root));
    cout<<"\n";
    treeInorder(root);
    return 0;
}
