#pragma once

#include<vector>
using std::vector;
#include<iostream>
using std::cout;

#include <cstddef>
using std::size_t;
#include<iterator>
using std::advance;
using std::distance;
#include<algorithm>
using std::copy;
#include <type_traits>
using std::remove_reference;

template<typename RAIter>
size_t inversions(RAIter first, RAIter last);

template<typename RAIter>
void mergeSort(RAIter first, RAIter last, size_t & inversions);

template<typename RAIter>
void stableMerge(RAIter first, RAIter last, size_t & inversions);

template<typename RAIter>
size_t inversions(RAIter first, RAIter last)
{
  size_t inversion = 0;
  mergeSort(first, last, inversion);

  return inversion;
}


template<typename RAIter>
void mergeSort(RAIter first, RAIter last, size_t & inversions)
{
  //base case
  if(distance(first, last) < 2)
    return;


  auto mid = first;
  advance(mid, distance(first,last)/2);

  mergeSort(first, mid, inversions);
  mergeSort(mid, last, inversions);

  stableMerge(first, last, inversions);

}


template<typename RAIter>
void stableMerge(RAIter first, RAIter last, size_t & inversions)
{

  using Type = typename remove_reference<decltype(*first)>::type;
  vector<Type> buffer(distance(first, last));
  auto output = buffer.begin();

  auto left = first;
  auto right = first;
  advance(right, distance(first, last)/2);
  auto middle = right;

  while(left < middle && right < last)
  {
    if(*left < *right)
    {
      *output = *left;
      //inversions += distance(left, right);
      advance(left, 1);
    }
    else
    {
      *output = *right;
      // if(*right < *left)
      //   inversions += distance(left, middle);
      for(auto i = left; i < middle; i++)
        if(*right < *i)
          inversions++;
      advance(right, 1);
    }
    advance(output, 1);
  }

  copy(left, middle, output);
  copy(right, last, output);

  copy(buffer.begin(), buffer.end(), first);

  // while(output < buffer.end())
  // {
  //   if(left < middle && (*left < *right || right == last ))
  //   {
  //     *output = *left;
  //     if(*(right-1) < *left)
  //       for(auto i = right-1; i > middle; i--)
  //         if(*left < *i)
  //           inversions--;
  //     advance(left, 1);
  //   }
  //   else
  //   {
  //     *output = *right;
  //     if(*right < *left)
  //       inversions += distance(left, middle);
  //     // for(auto i = left; i < middle; i++)
  //     //   if(*right < *i)
  //     //     inversions++;
  //     advance(right, 1);
  //   }
  //   advance(output, 1);
  // }
  //
  // copy(buffer.begin(), buffer.end(), first);

}
