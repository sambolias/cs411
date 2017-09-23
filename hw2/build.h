#pragma once

#include <vector>
using std::vector;
using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> & bridges);
vector<vector<Bridge>> addVecs(const vector<vector<Bridge>> & a, const vector<vector<Bridge>> & b);

class BridgeBuilder
{
  vector<Bridge> bridges;
  int westCount, eastCount;

  vector<vector<Bridge>> buildSubset();
  vector<vector<Bridge>> buildSubsetRecurse(int edgeIdx, const vector<int> & prevEdges);
  bool bridgesOverlap(const Bridge & a, const Bridge & b);
  int getMaxToll(vector<vector<Bridge>> & subsets);

public:
  BridgeBuilder(int w, int e, const vector<Bridge> & b);
  BridgeBuilder();

  int getMaxToll();

};
