/*
	build.cpp
	Sam Erie
	serie@alaska.edu
	CS 411
	HW 2
	Exhaustive Search Algorithm Demo
	Function definitions for build.h
*/

#include "build.h"

//  *** Global Functions ***

int build(int w, int e, const vector<Bridge> & bridges)
{
  return BridgeBuilder(bridges).getMaxToll();
}


vector<vector<Bridge>> concatVecs(const vector<vector<Bridge>> & a, const vector<vector<Bridge>> & b)
{
  vector<vector<Bridge>> sum;
  for(auto as : a)
    sum.push_back(as);
  for(auto bs : b)
    sum.push_back(bs);
  return sum;
}

//  *** BridgeBuilder Class ***

//  *** private functions ***

//exhaustively builds every valid subset the set of all bridges
vector<vector<Bridge>> BridgeBuilder::buildSubset()
{
  vector<vector<Bridge>> subsets;
  for(auto i = 0; i < bridges.size(); i++)
  {
    vector<int> prevEdges;
    subsets = concatVecs(subsets, buildSubsetRecurse(i, i, prevEdges));
  }
  return subsets;
}

//recursively builds all potential bridges (paths) starting at some root
vector<vector<Bridge>> BridgeBuilder::buildSubsetRecurse(int edgeIdx, int startEdge, const vector<int> & prevEdges)
{
  vector<vector<Bridge>> subset;
  vector<Bridge> set;
  Bridge lastEdge;
  int prevIdx = edgeIdx;
  vector<int> tempEdges = prevEdges;  //the edgelist for subset with new bridge
  bool bridgeFail = false;

  for(auto p : prevEdges)
  {
    set.push_back(bridges[p]);
    if(bridgesOverlap(bridges[edgeIdx], bridges[p]))
    {
      bridgeFail = true;
      break;
    }
  }

  if(!bridgeFail)
    lastEdge = bridges[edgeIdx];

  ++edgeIdx;
  if(edgeIdx==bridges.size())
    edgeIdx = 0;

  if(edgeIdx != startEdge)
  {
    if(!bridgeFail)
    {
      subset.push_back(set);
      //add one without edge
      subset = concatVecs(subset, buildSubsetRecurse(edgeIdx, startEdge, prevEdges));
      //add one with
      tempEdges.push_back(prevIdx);
      subset = concatVecs(subset, buildSubsetRecurse(edgeIdx, startEdge,tempEdges));
    }
    else  //just add one without
      subset = concatVecs(subset, buildSubsetRecurse(edgeIdx, startEdge, prevEdges));
  }
  else
  {
    if(lastEdge.size()>0)
      set.push_back(lastEdge);
    subset.push_back(set);
  }
  return subset;
}

//returns true if bridges overlap
bool BridgeBuilder::bridgesOverlap(const Bridge & a, const Bridge & b)
{
  if(a[0] == b[0] || a[1] == b[1])
    return true;
  if(a[0]<b[0] && a[1]>b[1])
    return true;
  if(a[0]>b[0] && a[1]<b[1])
    return true;

  return false;
}

//  *** public CTOR & functions

BridgeBuilder::BridgeBuilder(const vector<Bridge> & b) : bridges(b)
{}

//returns the maximum toll amount from all configurations of bridges (subsets)
int BridgeBuilder::getMaxToll(const vector<vector<Bridge>> & subsets)
{
  int max = 0;

  for(auto subset : subsets)
  {
    int toll = 0;
    for(auto bridge : subset)
      toll += bridge[2];

    if(toll > max)
      max = toll;
  }
  return max;
}


int BridgeBuilder::getMaxToll()
{
  vector<vector<Bridge>> subsets = buildSubset();
  return getMaxToll(subsets);
}
