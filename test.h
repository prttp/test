#pragma once
#include<string>
class ListNode
{
    ListNode* Prev;
    ListNode* Next;
    ListNode* Rand; // ������������ ������� ������ ������
    std::string Data;
};


class ListRand
{
public:
    ListNode Head;
    ListNode Tail;
    int Count;
    void Serialize(std::ostream& stream)
    {
    }

    public void Deserialize(FileStream s)
    {
    }
}
