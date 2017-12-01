// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <iostream>
#include <queue>
using std::priority_queue;
#include <utility>
using std::pair;
#include <vector>
using std::vector;

//builds EncodingNode tree and encodings map
void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
  //populate vector of leaf nodes
  vector<shared_ptr<EncodingNode>> nodes;
  for(auto leaf : theweights)
    nodes.push_back(make_shared<EncodingNode>(leaf));

  //put EncodingNodes in priority_queue
  //sorted descending by weight of root (combined weight of leaves)
  auto comp = [](const shared_ptr<EncodingNode> &a,
                 const shared_ptr<EncodingNode> &b)
                 {return a->weight > b->weight;};
  priority_queue<shared_ptr<EncodingNode>, vector<shared_ptr<EncodingNode>>,
                                           decltype(comp)> q(nodes.begin(),
                                           nodes.end(), comp);

  //don't try to build from empty priority_queue
  if(q.size() == 0)
  {
    return;
  }

  //build tree from priority_queue
  //take two lowest weight nodes and attach them to new root
  //then place new root in priority_queue
  while(q.size() > 1)
  {
    auto left = q.top();
    q.pop();
    auto right = q.top();
    q.pop();

    auto root = make_shared<EncodingNode>();
    root->attachLeft(left);
    root->attachRight(right);
    q.push(root);
  }

//set head to tree root
  head = q.top();
//recursively map all leaf encodings
  mapEncodings(head, "");

}

//recursively tracks encoding up to leaf then stores in encodings map
void HuffCode::mapEncodings(const shared_ptr<EncodingNode> & node, string encoding)
{
  if(node->isLeaf)
    encodings[node->value[0]] = encoding;
  else
  {
    if(node->left != NULL)
      mapEncodings(node->left, encoding + "0");

    if(node->right != NULL)
      mapEncodings(node->right, encoding + "1");
  }
}

//encodings saved in map encodings
string HuffCode::encode(const string & text) const
{
    string word;

    for(auto c : text)
    {
      word += encodings.at(c);
    }

    return word;
}

//traverse tree of EncodingNodes
string HuffCode::decode(const string & codestr) const
{

  string word;

  auto curr = head;
  for(auto b : codestr)
  {

    if(b == '0')
      curr = curr->left;
    else
      curr = curr->right;

    if(curr->isLeaf)
    {
      word += curr->value;
      curr = head;
    }

  }
    return word;
}


// *** EncodingNode Struct Definitions **

//ctors
EncodingNode::EncodingNode(pair<char,int> node) : value(string(1,node.first)), weight(node.second), isLeaf(true)
{}
EncodingNode::EncodingNode() : weight(0), isLeaf(false)
{}

//functions
void EncodingNode::attachLeft(const shared_ptr<EncodingNode> & node)
{
  left = node;
  weight += node->weight;
}

void EncodingNode::attachRight(const shared_ptr<EncodingNode> & node)
{
  right = node;
  weight += node->weight;
}
