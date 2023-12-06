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
   vector<int> steps(int(log2(10000)));
   steps[0] = 1;
   while (N <= 10000){
   vector <int> A(N, 0);//сортируемый массив

   mt19937 mt(time(nullptr));

   for (int i = 0; i < N; ++i){
       A[i] = (mt() % 1000);}
   int k = int(log2(N));
   if (steps[k] == 0){
       steps[k] = (2 << (k - 1)) - 1;
   }
   auto t1 = std::chrono::high_resolution_clock::now();
   for (; k >= 0; k--) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = steps[k]; i < N; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = A[i]; 
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= steps[k] && A[j - steps[k]] > temp; j -= steps[k]) 
                A[j] = A[j - steps[k]]; 
              
            //  put temp (the original a[i]) in its correct location 
            A[j] = temp; 
        } 
    } 
   auto t2 = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);//время моей сортировки
   cout << N << " " << duration.count() << "\n";
   N++;
   }
    return 0;
}
