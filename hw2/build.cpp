#include "build.h"

int build(int w, int e, const vector<Bridge> & bridges)
{
  return BridgeBuilder(w, e, bridges).getMaxToll();
}

//looks up weight of edge, returns -1 if edge doesn't exist
int BridgeBuilder::getWeight(int w, int e)
{
  for(auto bridge : bridges)
  {
    if(bridge[0] == w && bridge[1] == e)
      return bridge[2];
  }
  return -1;
}

BridgeBuilder::BridgeBuilder(int w, int e, const vector<Bridge> & b) : westCount(w), eastCount(e)
{
  bridges = b;
}

int BridgeBuilder::getMaxToll()
{
  return 1; //TODO
}
