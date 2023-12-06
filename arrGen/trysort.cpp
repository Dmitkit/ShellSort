#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

int main()
{
   int N = 1000;
   vector <int> A(N, 0);//сортируемый массив
   mt19937 mt(1234);
   for (int i = 0; i < N; ++i){
       A[i] = (mt() % 1000);}
   vector <int> B(N);
   B = A;
   vector <int> C(N);
   C = A;
   sort(C.begin(), C.end());
   for (int l = 0; l < 178705; l++){
        int m = 0;
        cin >> m;
        double a = 0;
        cin  >> a;
        int steps_size = 0;
        cin >> steps_size;
        vector<int> steps(100, 0);

        for (int i = 0; i < steps_size; i++){
            cin >> steps[i];
        }


        int k = steps_size - 1;
        auto t1 = std::chrono::high_resolution_clock::now();
        for (; k >= 0; k--) {
                for (int i = steps[k]; i < N; i += 1) { 
                    int temp = A[i]; 
                    int j;             
                    for (j = i; j >= steps[k] && A[j - steps[k]] > temp; j -= steps[k]) 
                        A[j] = A[j - steps[k]]; 
                    A[j] = temp; 
                } 
            } 
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);//время моей сортировки
        cout << "a = " << a << ", 1/k = " << m << ", steps[1] =  " << steps[1] << ", time=" << duration.count() << "\n";
        if (C != A){break;}
        A = B;}
    return 0;
}
