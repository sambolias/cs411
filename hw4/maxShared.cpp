#include <iostream>
using std::cout;
#include <vector>
using std::vector;
using std::string;
#include <algorithm>
using std::swap;
#include<map>
using std::map;

struct range
{
  double begin, end;

  range(double _b, double _e) : begin(_b), end(_e)
  {}

  bool contains(double c)
  {
    return c >= begin && c <= end;
  }
};

//O(nlogn)
//sorts ranges by start of range
vector<range> sortRanges(const vector<range> & ranges)
{
  vector<range> sorted;
  map<double, double> sortTree;

  //sort ranges in ascending order using map
  for(auto r : ranges)
    sortTree[r.begin] = r.end;

  //get back sorted ranges
  for(auto r : sortTree)
    sorted.push_back(range(r.first, r.second));

  return sorted;
}

//O(n)
//counts maximum number of ranges sharing common point
int countMaxShared(const vector<range> & ranges)
{
  int count = 0;
  int newCount = 0;
  int maxEnd = ranges[0].end;
  int prevI = 0;

  for(int i = 0; i < ranges.size(); i++)
  {
    range r = ranges[i];

    if(r.contains(maxEnd))
    {
      newCount++;
    }
    else
    {
        if(newCount > count)
          count = newCount;
        newCount = 0;

        //O(n)
        //find start of new max range
        while(!r.contains(ranges[prevI].end))
          prevI++;

        //count prev range and current pos
        newCount = i - prevI + 1;
        maxEnd = ranges[prevI].end;
    }
  }
  //check contents of newCount at end of vector
  if(newCount > count)
    count = newCount;
  return count;
}

int main()
{
  vector<range> ranges = {range(1.,4.), range(0.,3.), range(-1.,2.), range(3.6,5.)};
  ranges = sortRanges(ranges);

  for(auto r : ranges)
  {
    cout<<"("<<r.begin<<", "<<r.end<<")\n";
  }

  cout<<countMaxShared(ranges)<<" ranges share common point\n";

  vector<range> ranges2 = {range(3.3,9.), range(3.,9.), range(3.2,9.), range(2.,4.), range(1.,3.), range(3.1,9.)};
  ranges2 = sortRanges(ranges2);

  for(auto r : ranges2)
  {
    cout<<"("<<r.begin<<", "<<r.end<<")\n";
  }

  cout<<countMaxShared(ranges2)<<" ranges share common point\n";


  vector<range> ranges3 = {range(1,2), range(3,4), range(5,6), range(7,8)};
  ranges3 = sortRanges(ranges3);

  for(auto r : ranges3)
  {
    cout<<"("<<r.begin<<", "<<r.end<<")\n";
  }

  cout<<countMaxShared(ranges3)<<" ranges share common point\n";


  return 0;
}
