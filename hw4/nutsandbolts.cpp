#include "nutsandbolts.h"
using std::swap;
class bolt;


nut::nut(int s) : size(s)
{}

nut::nut()
{}

int nut::getSize() const
{
  return size;
}

bool nut::operator==(const bolt & b)
{
  return (size == b.getSize());
}

bool nut::operator>(const bolt & b)
{
  return (size > b.getSize());
}

bool nut::operator<(const bolt & b)
{
  return (size < b.getSize());
}

nut nut::operator=(const nut & n)
{
  size=n.getSize();
}



bolt::bolt(int s) : size(s)
{}

int bolt::getSize() const
{
  return size;
}

bool bolt::operator==(const nut & n)
{
  return (size == n.getSize());
}

bool bolt::operator>(const nut & n)
{
  return (size > n.getSize());
}

bool bolt::operator<(const nut & n)
{
  return (size < n.getSize());
}

bolt bolt::operator=(const bolt & b)
{
  size=b.getSize();
}

// struct nutAndBolt
// {
//   int _n;
//   int _b;
//   nutAndBolt(nut n, bolt b) : _n(n.getSize()), _b(b.getSize())
//   {}
//   bool check()
//   {
//     return _n == _b;
//   }
// };

//must give same number of nuts and bolts, and with matching sizes
// vector<nutAndBolt> combine(vector<nut> & nuts, vector<bolt> & bolts)
// {
//   //vector to hold combined nuts and bolts
//   vector<nutAndBolt> nabs;
//   int bb = 0;
//   int bm = bolts.size()/2;
//   //like quicksort, but compare bolts around nut
//   for(auto n : nuts)
//   {
//     if(n == bolts[bb])
//     if(bolts[bb] > n && bolts[bm] < nut )
//
//   }
//
//   return nabs;
// }

// void combine(vector<nut> & nuts, vector<bolt> & bolts)
// {
//   if(nuts.size() > 0)
//   {
//     int pivot = partition(nuts, bolts);
//     combine(vector(nuts.begin(), nuts.begin()+pivot), vector(bolts.begin(), bolts.begin()+pivot));
//     combine(vector(nuts.begin()+pivot, nuts.end()), vector(bolts.begin()+pivot, bolts.end()));
//   }
// }
//
// int partition(vector<nut> & nuts, vector<bolt> & bolts)
// {
//   auto i = nuts.begin();
//
//   for(auto j = i; j != nuts.end(); j++)
//   {
//
//   }
//
// }

int partition(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi);

void quicksort(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
{
  if(lo < hi)
  {
    int p = partition(nuts, bolts, lo, hi);
    quicksort(nuts, bolts, lo, p-1);
    quicksort(nuts, bolts, p+1, hi);
  }
}

int partition(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
{
  //choose a bolt for comparison
  auto compBolt = bolts[hi];
  int pivot = lo-1;
  //partition nuts
  for(int j = lo; j < hi; j++)
  {
    if(nuts[j] < compBolt)
    {
      ++pivot;
      swap(nuts[pivot], nuts[j]);
    }
  }

  //needed comparison because nuts are partitioned
  auto compNut = nuts[pivot+1];
  int i = lo-1;
  //partition bolts using comparison nut
  for(int j = lo; j < hi; j++)
  {
    if(bolts[j] < compNut)
    {
      ++i;
      swap(bolts[i], bolts[j]);
    }
  }

  //swap ends if needed
  if(nuts[hi] < compBolt)
    swap(nuts[pivot+1], nuts[hi]);
  if(bolts[hi] < compNut)
    swap(bolts[i+1], bolts[hi]);

  return pivot+1;
}


//my debug
// int partition(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
// {
//   auto compBolt = bolts[hi]; //choose a bolt for comparison
//   int pivot = lo-1;
//
//   //partition nuts
//   for(int j = lo; j < hi; j++)
//   {
//     if(nuts[j] < compBolt)
//     {
//       ++pivot;
//       swap(nuts[pivot], nuts[j]);
//     }
//   }
//
//   auto compNut = nuts[pivot+1]; //needed comparison because nuts are partitioned
//   // nut compNut;
//   // for(auto n : nuts)
//   //   if(n == compBolt)
//   //     compNut = n;
//
//   if(lo == 0 && hi == nuts.size()-1){
//   cout<<compBolt.getSize()<<" - ";
//   cout<<compNut.getSize()<<"\n";}
//
//   int i = lo-1;
//   //partition bolts using comparison nut
//   for(int j = lo; j < hi; j++)
//   {
//     if(bolts[j] < compNut)
//     {
//       ++i;
//       swap(bolts[i], bolts[j]);
//     }
//   }
//
//   if(lo == 0 && hi == nuts.size()-1){  cout<<pivot<<" "<<i<<"\n";
//   cout<<nuts[pivot+1].getSize()<<" "<<bolts[i+1].getSize()<<"\n";}
//
//   if(nuts[hi] < compBolt)
//     swap(nuts[pivot+1], nuts[hi]);
//
//   if(bolts[hi] < compNut)
//     swap(bolts[i+1], bolts[hi]);
//
//   if(lo == 0 && hi == nuts.size()-1){  cout<<pivot<<" "<<i<<"\n";
//   cout<<nuts[pivot+1].getSize()<<" "<<bolts[i+1].getSize()<<"\n";}
//
//   return pivot+1;
// }
// int partition(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
// {
//   auto pivotNut = nuts[hi];
//   auto pivotBolt = bolts[hi];
//   int iNut = lo-1;
//   int iBolt = lo-1;
//   for(int j = lo; j < hi; j++)
//   {
//     if(bolts[j] < pivotNut)
//     {
//       ++iBolt;
//       swap(bolts[iBolt], bolts[j]);
//     }
//
//     if(nuts[j] < pivotBolt)
//     {
//       ++iNut;
//       swap(nuts[iNut], nuts[j]);
//     }
//   }
//
//   if(nuts[hi] < bolts[iBolt+1])
//     swap(bolts[iBolt+1], bolts[hi]);
//   if(bolts[hi] < nuts[iNut+1])
//     swap(nuts[iNut+1], nuts[hi]);
//
//
//   return (nuts[iNut] < bolts[iBolt]) ? iNut+1 : iBolt+1;
// }
// int partitionNuts(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
// {
//   auto pivotBolt = bolts[hi];
//   int iNut = lo-1;
//
//   for(int j = lo; j < hi; j++)
//   {
//     if(nuts[j] < pivotBolt)
//     {
//       ++iNut;
//       swap(nuts[iNut], nuts[j]);
//     }
//   }
//
//   if(bolts[hi] < nuts[iNut+1])
//     swap(nuts[iNut+1], nuts[hi]);
//
//   return iNut;
// }
//
// int partitionBolts(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
// {
//   auto pivotNut = nuts[hi];
//   int iBolt = lo-1;
//
//   for(int j = lo; j < hi; j++)
//   {
//     if(bolts[j] < pivotNut)
//     {
//       ++iBolt;
//       swap(bolts[iBolt], bolts[j]);
//     }
//   }
//
//   if(nuts[hi] < bolts[iBolt+1])
//     swap(bolts[iBolt+1], bolts[hi]);
//
//   return iBolt;
// }
//
//
// int partition(vector<nut> & nuts, vector<bolt> & bolts, int lo, int hi)
// {
//   int iNut = lo-1, iBolt = lo-1;
//   if(nuts[hi] > bolts[hi])
//   {
//     iBolt = partitionBolts(nuts, bolts, lo, hi);  //nuts is correct pivot
//   }
//   else
//   {
//     iNut = partitionNuts(nuts, bolts, lo, hi); //or bolts is
//   }
//
//   int pivot = 0;
//   for(int i = hi-1; i > 0; i--)
//   {
//     if(nuts[hi] > bolts[hi])
//     {
//       if(!(bolts[i] < nuts[hi]))  // >=
//       {
//         pivot = i;
//         break;
//       }
//     }
//     else
//     {
//       if(!(nuts[i] < bolts[hi]))  // >=
//       {
//         pivot = i;
//         break;
//       }
//     }
//   }
//
//   if(nuts[hi] > bolts[hi])
//     iBolt = partitionBolts(nuts, bolts, lo, pivot);
//   else
//     iNut = partitionNuts(nuts, bolts, lo, pivot);
//
//   return (nuts[iNut] > bolts[iBolt]) ? iNut+1 : iBolt+1;
// }

int main()
{
  bolt b0(1), b1(6), b2(2), b3(1), b4(5);
  nut n0(5), n1(2), n2(1), n3(6), n4(1);

  vector<nut> nuts = {n0,n1,n2,n3,n4};
  vector<bolt> bolts = {b0,b1,b2,b3,b4};

  quicksort(nuts, bolts, 0, nuts.size()-1);

  for(auto n : nuts)
    cout<<n.getSize()<<"\n";

  for(auto b : bolts)
    cout<<b.getSize()<<"\n";

  // vector<nutAndBolt> nabs = combine(nuts, bolts);
  //
  // for(auto nab : nabs)
  //   if(nab.check())
  //     cout<<"good combo\n";
  //   else
  //     cout<<"bad combo\n";

  return 0;
}
