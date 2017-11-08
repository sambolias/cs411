#include <iostream>
using std::cout;
#include <vector>
using std::vector;
using std::string;

//by keeping track of sorts this
//algorithm only needs to visit
//each element once
//O(n)
int countSortBySort(const vector<vector<int>> & matrix)
{
  //keep track of downward sort
  vector<bool> colsSorted(matrix[0].size(), true);
  bool rowSorted;
  int count = 0;

  //traverse nxn matrix - O(n) where n = # of elements
  for(int y = 0; y < matrix.size(); y++)
  {
    rowSorted = true;
    for(int x = 0; x < matrix[0].size(); x++)
    {
      if(y > 0)
        if(matrix[y][x] < matrix[y-1][x])
          colsSorted[x] = false;

      if(x > 0)
        if(matrix[y][x] < matrix[y][x-1])
          rowSorted = false;
    }

    //tally sorted rows
    if(rowSorted)
      count++;
  }

  //tally sorted columns
  for(auto col : colsSorted)
    if(col)
      count++;

  return count;
}

int main()
{

  vector<int> one ={3,2,3,4,5};
  vector<int> two = {2,3,4,5,6};
  vector<int> three = {3,4,5,6,7};
  vector<int> four = {4,5,6,7,8};
  vector<int> five = {3,6,7,8,7};
  vector<vector<int>> mat = { one, two, three, four, five };

  cout<<countSortBySort(mat)<<" sorted rows and columns\n";

  return 0;
}
