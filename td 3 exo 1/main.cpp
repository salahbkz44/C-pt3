#include <iostream>

using namespace std;


struct file{
    int val;
    file *suiv;
};
file *tete=nullptr;
file *QQ=nullptr;

bool vide(){
    if(tete==nullptr)
    {
        return true;
    }else{
        return false;
    }
}

int longueur(){
    int cntr=1;
    file *e=tete;
    if(vide())
    {
        return 0;
    }else{
        while(e!=QQ){
            cntr++;
            e=e->suiv;
        }
        return cntr;
    }
}

void adjq(int n){
    if(vide())
    {
        tete=new(file);
        tete->val=n;
        tete->suiv=nullptr;
        QQ=tete;
    }else{
        file *neew;
        neew=new(file);
        neew->val=n;
        neew->suiv=nullptr;
        QQ->suiv=neew;
        QQ=neew;
    }
}

void supt(){
    if(vide())
    {
        cout<<"file vide"<<endl;
    }else{
        file *x=tete;
        tete=tete->suiv;
        delete(x);
    }
}

int teete(){
    if(vide())
    {
        cout<<"file vide"<<endl;
    }else{
        return tete->val;
    }
}

void afficher(){
    file *e=tete;
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
    while(choix!=7){
            cout<<"\n1.vide\n2.longueur\n3.emfiler\n4.defiler\n5.la valeur de tete\n6.afficher\n7.quitter\nvotre choix:";
            cin>>choix;
            cout<<endl;

        switch(choix){
        case 1:
            if(vide()){
                cout<<"la file est vide"<<endl;
            }else{
                cout<<"la file n'est pas vide"<<endl;
            }break;
        case 2:
            cout<<"la longueur de la file est:"<<longueur()<<endl;break;
        case 3:
            cout<<"entrez la valeur ajouté:";
            cin>>n;
            adjq(n);break;
        case 4:
            supt();break;
        case 5:
            cout<<"la valeur de tete est:"<<teete()<<endl;break;
        case 6:
            afficher();break;
        }
    }
    return 0;
}
