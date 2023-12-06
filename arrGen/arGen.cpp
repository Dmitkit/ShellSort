#include <iostream>

using namespace std;

int main (){
    int seq [100];
    seq[0] = 1;
    seq[1] = 1;
    while (seq[1] <= 10){
    seq[1] += 1;
    int m = -101;
    while (m < 100){
    m++;
    double a = 1;
    while (a < 10){
    a += 0.1;
    if (m == 0.0){
        continue;
    }
    double k = 1/double(m);
    int i = 2;
    for (; i < 100; i++){
        seq[i] = a*seq[i-1] + seq[i-2]*k;
        if (seq[i] > 10000){
        break;}
    }
    if (seq[1] == seq[2] || i == 100){
        continue;
    }
    cout << m << '\n' << a << '\n' << i << '\n';
    cout << seq[0] << " " << seq[1];
    for (int j = 2; j < i; j++){
        cout << " " << seq[j];
    }
    cout << endl;}}}

    return 0;
}