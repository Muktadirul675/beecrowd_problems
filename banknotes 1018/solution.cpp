#include <iostream>
 
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     
     int notes[7] = {100,50,20,10,5,2,1};
     int n;  cin >> n;
     cout << n << endl;
     for(int i=0;i<7;i++){
         if(n >= notes[i]){
             int need = n / notes[i];
             n -= need * notes[i];
             printf("%d nota(s) de R$ %d,00\n",need,notes[i]);
         }else{
            printf("0 nota(s) de R$ %d,00\n",notes[i]);
         }
     }
 
    return 0;
}