#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

int main()
{
   int N = 2;
   vector<int> steps = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
   while (N <= 10000){
   vector <int> A(N, 0);//сортируемый массив

   mt19937 mt(time(nullptr));

   for (int i = 0; i < N; ++i){
       A[i] = (mt() % 1000);}
   //vector <int> B(A.size());
//    B = A;
//    sort(B.begin(), B.end());
   int k = steps.size();
   while (N < steps[k]){k--;}
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
   cout << N << " " << duration.count() << "\n";
   //if (B != A){cout << "WRONG";}
   N++;
   }
    return 0;
}
