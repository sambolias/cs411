#pragma once

#include<vector>
using std::vector;
#include<iterator>
using std::iterator_traits;
#include<iostream>
using std::cout;

template<typename RAIter>
int contigSum(RAIter first, RAIter last);

template<typename RAIter>
int sumOfSequence(RAIter first, RAIter last);

template<typename RAIter>
int contigSumRecurse(RAIter first, RAIter last);

template<typename RAIter>
int contigSum(RAIter first, RAIter last)
{

  int gcs = contigSumRecurse(first, last);
  if(gcs<0)
    gcs=0;

    cout<<gcs<<"\n";
  return gcs;
}

template<typename RAIter>
int contigSumRecurse(RAIter first, RAIter last)
{
  if(first+1==last)
    return *first;

  auto mid = first + (last-first)/2;

  int b = 0;
  int c = 0;
  int d = sumOfSequence(first, last);
  if(first != mid )
    b = contigSumRecurse(first, mid);
  if(last != mid)
    c = contigSumRecurse(mid, last);



  int a=0;

  if(d>b && d>c)
    a=d;
  else if(b>d && b>c)
    a=b;
  else if(c>b && c>d)
    a=c;

  // if(b+c > a)
  //   if(b>c)
  //     a=contigSumRecurse(first, last-1);
  //   else
  //     a=contigSumRecurse(first+1, last);
  return a;
}

template<typename RAIter>
int sumOfSequence(RAIter first, RAIter last)
{
  int sum=0;
  for(auto i = first; i != last; i++)
  {
    sum += *i;
  }
  //cout<<sum<<"\n";
  return sum;
}
