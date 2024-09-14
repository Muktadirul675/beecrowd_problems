#include <iostream>
 
using namespace std;
 
int main() {
 
    int n; cin >> n;
    int hour = n/3600;
    n -= hour * 3600;
    int minutes = n / 60;
    n -= minutes * 60;

    printf("%d:%d:%d\n",hour,minutes,n); 
 
    return 0;
}