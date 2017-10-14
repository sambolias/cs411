#pragma once

#include<iterator>
using std::advance;
using std::distance;
#include<algorithm>
using std::max;


struct seqValues
{
  int gcs;
  int gcsLt;
  int gcsRt;
  int sum;
};

template<typename RAIter>
int contigSum(RAIter first, RAIter last);

template<typename RAIter>
int sumOfSequence(RAIter first, RAIter last);

template<typename RAIter>
seqValues contigSumRecurse(RAIter first, RAIter last);

template<typename RAIter>
int contigSum(RAIter first, RAIter last)
{
  seqValues gcs = contigSumRecurse(first, last);
  if(gcs.gcs<0)
    gcs.gcs=0;

  return gcs.gcs;
}

template<typename RAIter>
seqValues contigSumRecurse(RAIter first, RAIter last)
{
  //base cases
  if(first==last)
  {
    seqValues mt;
    mt.gcs=0;
    return mt;
  }

  if(distance(first,last)==1)
  {
    seqValues base;
    base.gcs = *first;
    base.gcsLt = (*first > 0)? *first : 0;
    base.gcsRt = (*first > 0)? *first : 0;
    base.sum = *first;

    return base;
  }

  //divide
  auto mid = first;
  advance(mid, distance(first, last)/2);

  seqValues left, right, seq;
  //recursive calls
  left = contigSumRecurse(first, mid);
  right = contigSumRecurse(mid, last);

  //conquer
  //this sum calc
  seq.sum=sumOfSequence(first,last);

  //this gcsLt calc
  int maximum=left.gcsLt;
  if(left.sum+right.gcsLt > maximum)
    maximum=left.sum+right.gcsLt;
  if(maximum<0)
    maximum=0;
  seq.gcsLt=maximum;

  //this gcsRt calc
  maximum=right.gcsRt;
  if(right.sum+left.gcsRt > maximum)
    maximum=right.sum+left.gcsRt;
  if(maximum<0)
    maximum=0;
  seq.gcsRt=maximum;

  //this gcs calc
  maximum=max(seq.gcsLt, seq.gcsRt);        //from lt or rt side
  maximum=max(maximum, left.gcs);            // or lt division
  maximum=max(maximum, right.gcs);            // or rt division
  maximum=max(maximum, seq.sum);               // or sum
  maximum=max(maximum, left.gcsRt+right.gcsLt); // or middle
  seq.gcs=maximum;

  return seq;
}

template<typename RAIter>
int sumOfSequence(RAIter first, RAIter last)
{
  int sum=0;
  for(auto i = first; i != last; i++)
  {
    sum += *i;
  }
  return sum;
}
