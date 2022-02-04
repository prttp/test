#pragma once
#include<string>
#include<deque>
#include<fstream>
#include<iostream>
#include<time.h>


class ListNode
{
    ListNode* Prev;
    ListNode* Next;
    ListNode* Rand; // произвольный элемент внутри списка
    std::string Data;
    friend class ListRand;
public:
    ListNode();
    ~ListNode();
    ListNode(ListNode* p, ListNode* n, ListRand* const th, const std::string d);
   
};


class ListRand
{
    ListNode Head;
    ListNode Tail;
    int Count;
    ListNode* randomNode();
    void IndexateList();
    void UnindexateList();
    friend class ListNode;
public:

    void Serialize(std::ofstream& f);
    void Deserialize(std::ifstream& f);
    void AddNode(std::string d);
    void AddNodeToTail(std::string d);
    ListRand();
    ~ListRand();
    void PrintAll();
   
};
