// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <memory>
#include <utility>


//nodes to build tree of encodings
//weight is sum of all subtrees/leaves
struct EncodingNode
{
  std::shared_ptr<EncodingNode> left;
  std::shared_ptr<EncodingNode> right;
  bool isLeaf;
  int weight;
  std::string value;

  EncodingNode();
  EncodingNode(std::pair<char,int> node);

  void attachLeft(const std::shared_ptr<EncodingNode> & node);
  void attachRight(const std::shared_ptr<EncodingNode> & node);
};

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> & theweights);

    void mapEncodings(const std::shared_ptr<EncodingNode> & node, std::string encoding);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ***** HuffCode: data members *****
private:
  std::unordered_map<char, std::string> encodings;
  std::shared_ptr<EncodingNode> head;

};  // End class HuffCode





#endif //#ifndef FILE_HUFFCODE_H_INCLUDED
