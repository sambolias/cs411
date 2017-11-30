#include"inversions.hpp"
#include<vector>
using std::vector;
#include<iostream>
using std::cout;
#include <cstddef>
using std::size_t;

int main()
{

    vector<int> a = {1,2,4,3,-8,0};

    for(auto i : a)
      cout<<i<<"\n";

     cout<<"\n\n--Sorted--\n\n";

   size_t inversion = 0;
   mergeSort(a.begin(), a.end(), inversion);


    for(auto i : a)
      cout<<i<<"\n";

      cout<<inversion<<" inversions\n";
}
