#pragma once

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
using std::string;

class bolt;

class nut
{
  int size;

public:
  nut(int s);
  nut();

  int getSize() const;
  bool operator==(const bolt & b);
  bool operator>(const bolt & b);
  bool operator<(const bolt & b);

nut operator=(const nut & n);
};

class bolt
{
  int size;

public:
  bolt(int s);

  int getSize() const;
  bool operator==(const nut & n);
  bool operator>(const nut & n);
  bool operator<(const nut & n);
  bolt operator=(const bolt & n);

};
