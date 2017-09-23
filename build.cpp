#include "build.h"

int build(int w, int e, const vector<Bridge> & bridges)
{
  return BridgeBuilder(w, e, bridges).getMaxToll();
}

class BridgeBuilder
{
  vector<Bridge> bridges;
  int westCount, eastCount;

  BridgeBuilder(int w, int e, const vector<Bridge> & b) : westCount(w), eastCount(e)
  {
    bridges = b;
  }

  int getMaxToll()
  {
    return 1; //TODO
  }

  //looks up weight of edge, returns -1 if edge doesn't exist
  int getWeight(int w, int e)
  {
    for(auto bridge : bridges)
    {
      if(bridge[0] == w && bridge[1] == e)
        return bridge[2];
    }
    return -1;
  }

};
