/*
Utilizzando i sottoprogrammi, implementare un programma che esegua le seguenti
operazioni su un vettore, costituito dai seguenti sottoprogrammi.
a) Leggere da tastiera un vettore di interi V e il suo riempimento r.
b) Stampare gli elementi del vettore V.
c) Stampare gli elementi del vettore V in ordine inverso.
d) Richiedere il valore di un numero intero x e verificare se esiste nel vettore V. Nel caso in cui
l'elemento esista restituire la sua posizione.
e) Calcolare la sommatoria degli elementi di posto pari e la sommatoria degli elementi di
posto dispari e memorizzare in un vettore VP gli elementi con valore pari e in un vettore VD
gli elementi con valore dispari.
*/

#include <iomanip>
#include <iostream>
using std:: endl;
using std:: cin;
using std:: cout;

void lettura(int, int[]);
void stampa(int, int[]);
int ricerca(int, int, int[]);
int sommatoria_pari(int, int[]);
int sommatoria_dispari(int, int[]);
void vettore_el_pari(int*, int, int[], int[]);
void vettore_el_dispari(int*, int, int[], int[]);

int main(){
    int n, pos_el, x, VP[50], n_p=0, n_d=0, VD[50];

    cout<<"Quanti elementi conterra' l'array?"<<endl;
    cin>>n;
    int array[n];

    lettura(n, array);
    stampa(n, array);

    cout<<endl<<endl<<"Inserire elemento da cercare nell'array:"<<endl;
    cin>>x;
    pos_el= ricerca(x, n, array);

    if(pos_el != -1)
        cout<<endl<<"Elemento trovato nell'indice' "<<pos_el<<".";
    else
        cout<<endl<<"Elemento non trovato.";

    cout<<endl<<endl<<"La sommatoria degli elementi di posto pari e': "<<sommatoria_pari(n, array);
    cout<<endl<<"La sommatoria degli elementi di posto dispari e': "<<sommatoria_dispari(n, array);

    vettore_el_pari(&n_p, n, array, VP);
    cout<<endl<<endl<<"Array con soli elementi pari: ";
    stampa(n_p, VP);

    vettore_el_dispari(&n_d, n, array, VD);
    cout<<endl<<endl<<"Array con soli elementi dispari: ";
    stampa(n_d, VD);





}

void lettura(int n, int array[]){
    cout<<"Inserisci "<<n<<" elementi dell'array:"<<endl;
    for(int i= 0; i<n; i++)
        cin>>array[i];
}

void stampa(int n, int array[]){
    for(int i= 0; i<n; i++){
    cout<<endl<<"Elemento array["<<i<<"]= "<<array[i];
    }
}

int ricerca(int x, int n, int array[]){

    for(int i=0; i<n; i++)
        if(x==array[i])
            return i;
    return -1;
}

int sommatoria_pari(int n, int array[]){
    int somma=0;
    for (int i = 0; i < n; i=i+2)
        somma += array[i];
    return somma;
}

int sommatoria_dispari(int n, int array[]){
    int somma=0;
    for (int i = 1; i < n; i=i+2)
        somma += array[i];
    return somma;
}

void vettore_el_pari(int *n_p, int n, int a[], int VP[]){
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2 == 0){
            VP[*n_p]= a[i];
            (*n_p)++;
        }
    }
}

void vettore_el_dispari(int *n_d, int n, int a[], int VD[]){
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2 != 0){
            VD[*n_d]= a[i];
            (*n_d)++;
        }
    }
}