#include <iostream>
#include <iomanip>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    char stringa[20];
    bool palind= true;
    int n=0, i=0;

    cout<<"Inserisci una stringa e verificare se palindroma:"<<endl;
    cin>>stringa;

    while(*(stringa+i) != '\0'){
        i++;
        n++;
    }
    
    for(int i=0; i<(n/2); i++){
        if(*(stringa+i) != *(stringa+(n-1-i))){
            palind= false;
            break;
        }
    }

    if(palind == true)
        cout<<endl<<"La stringa e' palindroma.";
    else
        cout<<endl<<"La stringa non e' palindroma.";
}