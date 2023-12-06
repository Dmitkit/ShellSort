#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main()
{
   int N = 1;

   while (N <= 10000){
   vector <int> A(N, 0);//сортируемый массив

   mt19937 mt(time(nullptr));

   for (int i = 0; i < N; ++i){
       A[i] = (mt() % 1000);}
   int k = log(N)/log(3) + 1; // +1 чтобы точно знать, что N < 3^k

   vector <int> S((k*k + k)/2); //масиив 3-гладких чисел (формула суммы арифметической прогрессии)

   int i = 0;//индекс элемента в массиве
   int l = 1; //счётчик проходов по строкам из чисел от 2^n до 3^n, у которых сумма степеней равна n
   int sum = 1;//сумма степеней простых множителей 3-гладких чисел
   S[i] = 1;
   while (sum <= k - 1){
       for (int j = 0; j <= sum; j++){
           S[++i] = pow(2, (sum - j)) * pow(3, j);}
       sum++;}

//    vector <int> B(A.size());
//    B = A;                      //массив для сортировки стандартной
//    auto t1 = std::chrono::high_resolution_clock::now();
//    sort(B.begin(), B.end());           //время стандартной сортировки
//    auto t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
//    cout << N << " "/*<< " elapsed time : " */<< duration.count() << "\n";

   auto t1 = std::chrono::high_resolution_clock::now();
   for (S[i]; S[i] > 0; i--) { //cортировка Шелла
       for (int j = S[i]; j < N; ++j){
           for (int l = j - S[i]; l >= 0 && A[l] > A[l + S[i]]; l -= S[i]){
               int temp = A[l];
               A[l] = A[l + S[i]];
               A[l + S[i]] = temp;}}}
   auto t2 = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);//время моей сортировки
   cout << N << " " << duration.count() << "\n";

   N++;
   }

    return 0;
}
