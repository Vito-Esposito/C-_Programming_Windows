/*
f) Verificare se esistono elementi nulli nella matrice e contemporaneamente
memorizzare gli elementi non nulli in un vettore V. Al termine stampare il numero
degli elementi nulli e il vettore V.
g) Dopo aver fatto la copia della matrice M, richiedere la posizione di una riga
(colonna) da eliminare dalla matrice copia (M_copia).
h) Calcolare la matrice trasposta
i) Verificare se la matrice è simmetrica
j) Copiare nei vettori VP e VS rispettivamente gli elementi della diagonale principale
e secondaria.
k) Memorizzare nei vettori MR e MC rispettivamente i minimi di ciascuna riga e di
ciascuna colonna.
*/

#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;

int main(){
    int n, m;

    cout<<"Inserire n righe e m colonne di una matrice: "<<endl;
    cin>>n;
    cin>>m;
    int matrice[n][m];

    cout<<endl<<"Riempi matrice: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= ";
            cin>>matrice[i][j];  
        }
    }

    cout<<endl<<"Stampa:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"matrice["<<i<<"]"<<"["<<j<<"]= "<<matrice[i][j]<<endl;
        }
    }

    cout<<endl<<"Ci sono elementi nulli?";
    int trovato= 0, cnt=0, vettore[20], k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrice[i][j] == 0){
                trovato= 1;
                cnt++;
            }
            else{
                vettore[k]= matrice[i][j];
                k++;
            }
        }
    }
    if(trovato == 1){
        cout<<endl<<"Elementi nulli trovati e ne sono "<<cnt<<".";
        cout<<endl<<"Vettore con gli elementi non nulli della matrice: "<<endl;
        for(int i=0; i<k; i++)
            cout<<"vettore["<<i<<"]= "<<vettore[i]<<endl;
    }
    else
        cout<<endl<<"Elementi nulli non trovati";

    int n_c=n, m_c=m;
    int matrice_copia[n_c][m_c];
    char risposta;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrice_copia[i][j]= matrice[i][j];
        }
    }
    cout<<endl<<"Eliminare riga (r) o colonna (c) della matrice copia? ";
    int r_c;
    cin>>risposta;
    while(risposta!='c' && risposta!='r'){
        cout<<"Riprova"<<endl;
        cin>>risposta;
    }
    if(risposta == 'r'){
        cout<<"Inserisci indice riga: "<<endl;
        cin>>r_c;

        for(int i=r_c; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                matrice_copia[i][j]= matrice_copia[i+1][j];
            }
        }
        n_c= n-1;
        cout<<endl<<"Stampa:"<<endl;
        for(int i=0; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                cout<<"matrice_copia["<<i<<"]"<<"["<<j<<"]= "<<matrice_copia[i][j]<<endl;
            }
        }
    }
    else if(risposta == 'c'){
        cout<<endl<<"Inserisci indice colonna: "<<endl;
        cin>>r_c;

        for(int i=0; i<n_c; i++){
            for(int j=r_c; j<m_c; j++){
                matrice_copia[i][j]= matrice_copia[i][j+1];
            }
        }
        m_c= m-1;
        cout<<endl<<"Stampa:"<<endl;
        for(int i=0; i<n_c; i++){
            for(int j=0; j<m_c; j++){
                cout<<"matrice_copia["<<i<<"]"<<"["<<j<<"]= "<<matrice_copia[i][j]<<endl;
            }
        }
    }
    





}