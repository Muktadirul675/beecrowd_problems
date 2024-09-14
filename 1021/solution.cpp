#include <iostream>
 
using namespace std;
 
int main() {
 
    int notes[6] = {100,50,20,10,5,2};
    int coins[6] = {100,50,25,10,5,1};
    
    double n;
    cin >> n;
    
    cout << "NOTAS:" << endl;
    for(int i=0;i<6;i++){
        int note = notes[i];
        int count = n / note;
        n -= count * note;
        printf("%d nota(s) de R$ %d.00\n",count,note);
    }
    cout << "MOEDAS:" << endl;
    cout << n << endl;
    n = n * 100; cout << n << endl;
    for(int i=0;i<6;i++){
        double coin = coins[i];
        int count = n / coin;
        n = n % coin;
        printf("%d moeda(s) de R$ %d\n",count,coin);
    }
 
    return 0;
}