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

class EncodingNode
{
public:
  std::shared_ptr<EncodingNode> left;
  std::shared_ptr<EncodingNode> right;
  bool isLeaf;
  bool isGood;
  std::string value;

  EncodingNode();
  EncodingNode(const EncodingNode &_left, const EncodingNode &_right);
  EncodingNode(std::shared_ptr<EncodingNode> _left, std::shared_ptr<EncodingNode> _right);
  EncodingNode(std::shared_ptr<EncodingNode> _left, const EncodingNode& _right);
  EncodingNode(std::string _value);
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

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ***** HuffCode: data members *****
private:
  std::unordered_map<char, std::string> encodings;
  std::shared_ptr<EncodingNode> head;

};  // End class HuffCode





#endif //#ifndef FILE_HUFFCODE_H_INCLUDED
