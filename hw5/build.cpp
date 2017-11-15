/*
	build.cpp
	Sam Erie
	serie@alaska.edu
	CS 411
	HW 5
	Dynamic Programming Algorithm Demo
	Function definitions for build.h
*/

#include "build.h"

//  *** Global Function ***

int build(int w, int e, const vector<Bridge> & bridges)
{
  BridgeBuilder b(w, e, bridges);
  return b.getMaxToll();
}

//  *** BridgeBuilder class ***

//ctor
//object holds max toll after it is constructed
BridgeBuilder::BridgeBuilder(int w, int e, const vector<Bridge> & b) : westCities(w),
                                                                       eastCities(e),
                                                                       maxToll(0)
{
  buildMatrix(b);
  calculateMaxToll();
}


//builds a weighted adj matrix of bridge tolls
void BridgeBuilder::buildMatrix(const vector<Bridge> & b)
{
  //init tollMatrix with 0s
  tollMatrix = vector<vector<int>>(westCities, vector<int>(eastCities, 0));
  for(auto bridge : b)
  {
    //in case of multiple tolls defined for a bridge
    int toll = tollMatrix[bridge[0]][bridge[1]];
    //store toll in adj mat
    tollMatrix[bridge[0]][bridge[1]] = max(toll, bridge[2]);
  }

}

//finds max toll using dynamic programming algorithm
void BridgeBuilder::calculateMaxToll()
{
  //init matrix with 0s
  auto maxTollMatrix = vector<vector<int>>(westCities, vector<int>(eastCities, 0));

  //dynamically calculate the maximum toll
  for(int w = 0; w < westCities; w++)
  {
    for(int e = 0; e < eastCities; e++)
    {
        //store maximum previous bridges that can be added to toll
        int maximum = (w>0 && e>0) ? maxTollMatrix[w-1][e-1] : 0;
        maximum = tollMatrix[w][e] + maximum;
        //or if row directly above or directly to left is bigger store it
        maximum = max(maximum, (w>0) ? maxTollMatrix[w-1][e] : 0);
        maximum = max(maximum, (e>0) ? maxTollMatrix[w][e-1] : 0);
        maxTollMatrix[w][e] = maximum;

        //keep track of overall maximum toll
        maxToll = max(maxToll, maximum);
    }
  }
}


int BridgeBuilder::getMaxToll()
{
  return maxToll;
}
