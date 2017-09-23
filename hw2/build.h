#pragma once

#include <vector>
using std::vector;
using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> & bridges);

class BridgeBuilder
{
  vector<Bridge> bridges;
  int westCount, eastCount;
  
  //looks up weight of edge, returns -1 if edge doesn't exist
  int getWeight(int w, int e);

public:
  BridgeBuilder(int w, int e, const vector<Bridge> & b);

  int getMaxToll();

};
