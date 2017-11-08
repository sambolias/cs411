#include <iostream>
using std::cout;
#include <vector>
using std::vector;
using std::string;
#include <algorithm>
using std::swap;

//O(n^2)
int abSubsetsBruteForce(string s)
{
  int count = 0;

  for(int i = 0; i < s.length(); i++)
    if(s[i] == 'A')
      for(int j = i; j < s.length(); j++)
        if(s[j] == 'B')
          count++;

  return count;
}

//O(n)
int abSubsetsDandC(string s)
{
  int count = 0, as = 0;

  //decrease string
  for(int i = 0; i < s.length(); i++)
  {
    //keep track of As
    if(s[i] == 'A')
      as++;

    //for every B add an AB substring for every A to the left
    if(s[i] == 'B')
      count += as;
  }

  return count;
}


int main()
{

  vector<string> sets = {"CABAAXBYA", "AABAB", "BACJKBALBALAB"};

  for(auto s : sets)
  {
    cout<<s<<" had "<<abSubsetsBruteForce(s)<<" A-B subsets\n";
    cout<<s<<" had "<<abSubsetsDandC(s)<<" A-B subsets\n";
  }

  return 0;
}
