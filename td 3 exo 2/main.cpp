#include <iostream>

using namespace std;

struct pile{
    int val;
    pile *suiv;
};

pile *sommet=nullptr;

bool vide(){
    if(sommet==nullptr)
    {
        return true;
    }else{
        return false;
    }
}

int hauteur(){
    int cntr=1;
    pile *e=sommet;
    if(vide())
    {
        return 0;
    }else{
        while(e->suiv!=nullptr){
            cntr++;
            e=e->suiv;
        }
        return cntr;
    }
}

void empiler(int n){
    if(vide())
    {
        sommet=new(pile);
        sommet->val=n;
        sommet->suiv=nullptr;
    }else{
        pile *neew;
        neew=new(pile);
        neew->val=n;
        neew->suiv=sommet;
        sommet=neew;
    }
}

void supt(){
    if(vide())
    {
        cout<<"file vide"<<endl;
    }else{
        pile *x=sommet;
        sommet=sommet->suiv;
        delete(x);
    }
}

void remplacer(int n){
      if(vide())
    {
        cout<<"file vide"<<endl;
    }else{
        sommet->val=n;
    }
}

int sommmet(){
    if(vide())
    {
        cout<<"file vide"<<endl;
    }else{
        return sommet->val;
    }
}

void afficher(){
    pile *e=sommet;
    if(vide())
    {
        cout<<"la file est vide";
    }else{
        while(e!=nullptr){
            cout<<e->val<<endl;
            e=e->suiv;
        }
    }
}
int main()
{
    int choix,n;
    while(choix!=8){
            cout<<"\n1.vide\n2.hauteur\n3.empiler\n4.depiler\n5.la valeur de sommet\n6.afficher\n7.remplacer\n8.quitter\nvotre choix:";
            cin>>choix;
            cout<<endl;

        switch(choix){
        case 1:
            if(vide()){
                cout<<"la pile est vide"<<endl;
            }else{
                cout<<"la pile n'est pas vide"<<endl;
            }break;
        case 2:
            cout<<"la hauteur de la pile est:"<<hauteur()<<endl;break;
        case 3:
            cout<<"entrez la valeur ajoute:";
            cin>>n;
            empiler(n);break;
        case 4:
            supt();break;
        case 5:
            cout<<"la valeur de sommet est:"<<sommmet()<<endl;break;
        case 6:
            afficher();break;
        case 7:
            cout<<"entrez la nouvelle valeur de sommet:";
            cin>>n;
            remplacer(n);
        }
    }
    return 0;
}

