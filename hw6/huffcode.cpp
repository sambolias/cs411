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


void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
  //put weighted chars in priority_queue
  //sorted descending by weight
  auto comp = [](pair<char,int> a, pair<char,int> b){return a.second < b.second;};
  priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> q(theweights.begin(),
                                                    theweights.end(), comp);

  string enc = "";
  head = make_shared<EncodingNode>();
  auto node = head;
  auto next = make_shared<EncodingNode> ();

  while(!q.empty())
  {
  //  std::cout<<q.top().first<<" "<<q.top().second<<"\n";
    char c = q.top().first;
    string v(1, c);
  // std::cout<<v<<"\n";
    q.pop();
    if(q.empty())
    {
      node->value = v;
      node->isGood = true;
      node->isLeaf = true;
    //  node = make_shared<EncodingNode>(v);
      //node = EncodingNode(v);
      encodings[c] = enc;
      std::cout<<v<<" "<<encodings[c]<<"\n";
    }
    else
    {
    //  *node = make_shared<EncodingNode>(next, EncodingNode(v));
  //  node = EncodingNode(next, EncodingNode(v));
      node->left = next;
      node->right = make_shared<EncodingNode>(v);
      node->isGood = true;
      node->isLeaf = false;
      encodings[c] = enc+"1";
      std::cout<<v<<" "<<encodings[c]<<"\n";
      node = node->left;
      next = make_shared<EncodingNode> ();
      enc += "0";
    }

  }

}


string HuffCode::encode(const string & text) const
{
    string word;
    // if(head == NULL || !head->isGood)
    // {
    //   std::cout<<"what the fuck\n";
    // }
    std::cout<<"given: ";
    for(auto c : text)
    {
      std::cout<<c;
      word += encodings.at(c);
    }
    std::cout<<"\nreturned: "<<word<<"\n";
    return word;  // DUMMY RETURN
}


string HuffCode::decode(const string & codestr) const
{
  string word;
  // if(head == NULL || !head->isGood)
  // {
  //   std::cout<<"what the fuck\n";
  //   return "";
  // }
  auto curr = head;
  for(auto b : codestr)
  {
    // std::cout<<b;
    // if(!curr->isLeaf)
    // {
      if(b == '0')
        curr = curr->left;
      else
        curr = curr->right;
    //}

    if(curr->isLeaf)
    {
      // std::cout<<"hi";
      // std::cout<<curr->value;
      word += curr->value;
      curr = head;
    }

  }
    return word;  // DUMMY RETURN
}

EncodingNode::EncodingNode(const EncodingNode &_left, const EncodingNode &_right) : isLeaf(false), isGood(true)
{
  left = make_shared<EncodingNode>(_left);
  right = make_shared<EncodingNode>(_right);
}
EncodingNode::EncodingNode(shared_ptr<EncodingNode> _left, shared_ptr<EncodingNode> _right) : isLeaf(false), isGood(true)
{
  left = _left;
  right = _right;
}
EncodingNode::EncodingNode(shared_ptr<EncodingNode> _left, const EncodingNode& _right) : isLeaf(false), isGood(true)
{
  left = _left;
  right = make_shared<EncodingNode>(_right);
}
EncodingNode::EncodingNode(string _value) : value(_value), isLeaf(true), isGood(true)
{}
EncodingNode::EncodingNode() : isGood(false)
{}
