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
  // while(std::cin.get() != 10)
  // {}
  BridgeBuilder b(w, e, bridges);
  return b.getMaxToll();
}


//builds a weighted adj matrix of bridge tolls
void BridgeBuilder::buildMatrix(const vector<Bridge> & b)
{
  //init tollMatrix to -1
  tollMatrix = vector<vector<int>>(westCities, vector<int>(eastCities, 0));
  for(auto bridge : b)
  {
    tollMatrix[bridge[0]][bridge[1]] = bridge[2];
  //  cout<<westCities<<" "<<eastCities<<"\n"<<bridge[0]<<" "<<bridge[1]<<" "<<bridge[2]<<"\n";
  }

  // for(auto w = 0; w < westCities; w++)
  // {
  //   for(auto e = 0; e < eastCities; e++)
  //   {
  //       cout<<tollMatrix[w][e]<<" ";
  //   }
  //   cout<<"\n";
  // }


}

BridgeBuilder::BridgeBuilder(int w, int e, const vector<Bridge> & b) : westCities(w),
                                                                       eastCities(e),
                                                                       maxToll(0)
{
  buildMatrix(b);
  calculateMaxToll();
}

void BridgeBuilder::calculateMaxToll()
{
  //fills empty positions in maxTollMatrix with maximum
  //toll you could get left or above this matrix position
  vector<int> maxInRange = vector<int>(westCities, 0);
  vector<int> maxInDomain = vector<int>(eastCities, 0);
  //init matrix with 0s
  maxTollMatrix = vector<vector<int>>(westCities, vector<int>(eastCities, 0));

  //dynamically calculate the maximum toll
  for(int w = 0; w < westCities; w++)
  {
    for(int e = 0; e < eastCities; e++)
    {
      //if there is a city here
      if(tollMatrix[w][e] > 0)
      {
        int maximum = max(
                    max((w>0 && e>0) ? maxTollMatrix[w-1][e-1] : 0,
                    (w-1>0 && e>0) ? maxTollMatrix[w-2][e-1] : 0),
                    (w>0 && e-1>0) ? maxTollMatrix[w-1][e-2] : 0
                    );
        maximum = tollMatrix[w][e] + maximum;
        maxTollMatrix[w][e] = maximum;
        //gives same output
      //  maxTollMatrix[w][e] = max(max(maxInRange[w], maxInDomain[e]), maximum);

        maxInRange[w] = max(maxInRange[w], maximum);
        //maxInRange[w] = max((w>0) ? maxInRange[w-1] : 0, max(maxInRange[w], maximum));
        maxInDomain[e] = max((e>0) ? maxInDomain[e-1] : 0, max(maxInDomain[e], maximum));
        // maxInRange[w] = max((w>0) ? maxInRange[w-1] : 0, maximum);
        // maxInDomain[e] = max((e>0) ? maxInDomain[e-1] : 0, maximum);
        //keep track of overall maximum toll
        maxToll = max(maxToll, maximum);
      }
      else
      {
      //  maxTollMatrix[w][e] = maxInDomain[e];
        maxTollMatrix[w][e] = max(maxInRange[w], maxInDomain[e]);
        // maxTollMatrix[w][e] = max(
        //                       (w>0) ? maxInRange[w-1] : 0,
        //                       (e>0) ? maxInDomain[e-1] : 0
        //                       );
      }
    }
  }
}

int BridgeBuilder::getMaxToll()
{
  return maxToll;
}
