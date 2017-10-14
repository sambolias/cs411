#pragma once
/*
	inversions.hpp
	Sam Erie
	serie@alaska.edu
  10/14/17
	CS 411
	HW 3
	Divide & Conquer Algorithm Demo
	Counts inverted numbers in a list using D&C algorithm mergeSort
  Passes all tests of inversions_test.cpp
*/
#include<vector>
using std::vector;
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

// Inversion Counting MergeSort
// based on:
// merge_sort.cpp
// Glenn G. Chappell
// 9 Oct 2015

// stable merge sort with a pointer to count the number of inversions in a sequence

template<typename RAIter>
void mergeSort(RAIter first, RAIter last, size_t & inversions)
{
  //base case
  if(distance(first, last) < 2)
    return;

  auto mid = first;
  advance(mid, distance(first,last)/2);

  // divide
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

  // conquer
  while(left < middle && right < last)
  {
    if(*right < *left)
    {
      *output = *right;
      inversions += distance(left, middle); //this only works when the merge is stable
      advance(right, 1);                    //there is a horrendous way to make it
    }                                       //work for unstable merge, which can be
    else                                    //seen on my github past versions
    {
      *output = *left;
      advance(left, 1);
    }
    advance(output, 1);
  }

  copy(left, middle, output);
  copy(right, last, output);

  copy(buffer.begin(), buffer.end(), first);

}
