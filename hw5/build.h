/*
	build.h
	Sam Erie
	serie@alaska.edu
	CS 411
	HW 5
  11/15/2017
	Dynamic Programming Algorithm Demo
	Finds max toll from best possible configuration of bridges
  Passes all tests of build_test2.cpp
*/
#pragma once

#include<algorithm>
using std::max;
#include <vector>
using std::vector;
using Bridge = vector<int>;

//wrapper function for bridgebuilder class
int build(int w, int e, const vector<Bridge> & bridges);

//class to dynamically build all possible configurations of bridges and
//return the maximum toll possible
class BridgeBuilder
{

private:
  int westCities, eastCities;
  int maxToll;

  vector<vector<int>> tollMatrix; //tollMatrix[w][e]

  void buildMatrix(const vector<Bridge> & b);
  void calculateMaxToll();

public:
  BridgeBuilder(int w, int e, const vector<Bridge> & b);
  int getMaxToll();
};
