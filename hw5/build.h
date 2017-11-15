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

#include<iostream>
using std::cout;
#include<utility>
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
  vector<vector<int>> maxTollMatrix;
  vector<vector<int>> tollMatrix; //tollMatrix[w][e]

  void buildMatrix(const vector<Bridge> & b);
  void calculateMaxToll();


public:

  BridgeBuilder(int w, int e, const vector<Bridge> & b);

  int getMaxToll();
};
