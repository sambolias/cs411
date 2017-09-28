/*
	build.h
	Sam Erie
	serie@alaska.edu
	CS 411
	HW 2
	Exhaustive Search Algorithm Demo
	Finds max toll from all possible configurations of bridges
  Passes all tests of build_test.cpp
*/
#pragma once

#include <vector>
using std::vector;
using Bridge = vector<int>;

//wrapper function for bridgebuilder class
int build(int w, int e, const vector<Bridge> & bridges);
//basic vector concatonation function
vector<vector<Bridge>> concatVecs(const vector<vector<Bridge>> & a, const vector<vector<Bridge>> & b);

//class to exhaustively build all possible configurations of bridges and
//return the maximum toll possible
class BridgeBuilder
{

private:

  vector<Bridge> bridges;

  vector<vector<Bridge>> buildSubset();
  vector<vector<Bridge>> buildSubsetRecurse(int edgeIdx, int startEdge, const vector<int> & prevEdges);
  bool bridgesOverlap(const Bridge & a, const Bridge & b);
  int getMaxToll(const vector<vector<Bridge>> & subsets);

public:

  BridgeBuilder(const vector<Bridge> & b);

  int getMaxToll();
};
