#include"test.h"


ListNode::ListNode()
{
	Prev = nullptr;
	Next = nullptr;
	Rand = nullptr;
}

ListNode::~ListNode()
{
	if (Next != 0) { Next->Prev = Prev; };
	if (Prev != 0) { Prev->Next = Next; };
}

ListNode::ListNode(ListNode* p, ListNode* n, ListRand* const th, const std::string d)
{
	Prev = p;
	Next = n;
	if (p != 0) { p->Next = this; };
	if (n != 0) { n->Prev = this; };
	this->Data = d;
	Rand = th->randomNode();

}

ListNode* ListRand::randomNode()
{
	srand(time(0));
	int r_i = rand() % Count + 1;
	int i = 0;
	ListNode* ans = &Head;
	do
	{
		ans = ans->Next;
		i++;
	} while (i != r_i);
	return ans;
}

void ListRand::IndexateList()
{
	ListNode* p = Head.Next;
	int i = 0;
	while (p != &Tail) {
		i++;
		p->Data += '_' + std::to_string(i);
		p = p->Next;
	};
	
}

void ListRand::UnindexateList()
{
	ListNode* p = Head.Next;
	while (p != &Tail) {
		auto it = p->Data.find_last_of('_');
		p->Data.erase(it, p->Data.length());
		p = p->Next;
				
	};
}

void ListRand::Serialize(std::ofstream& f)
{
	this->IndexateList();
	for (ListNode* p = Head.Next; p != &Tail; p = p->Next)
	{
		auto it = p->Rand->Data.find_last_of('_');
		std::string str;
		str.assign(p->Rand->Data, it + 1);
		f << p->Data << ':' << str << std::endl;
	}
	this->UnindexateList();
	f.close();
}

void ListRand::Deserialize(std::ifstream& f)
{
	std::deque<int> rands;
	std::deque<ListNode*> pl;
	std::string line;
	if (f.is_open())
	{
		while (std::getline(f, line))
		{
			auto it = line.find_last_of(':');
			std::string str;
			str.assign(line, it + 1);
			rands.push_back(std::stoi(str));
			str.assign(line, 0, it);
			this->AddNodeToTail(str);
		}
		this->UnindexateList();

		ListNode* p = Head.Next;

		while (p != &Tail) {
			pl.push_back(p);
			p = p->Next;
		};
		p = Head.Next;
		int i = 0;
		while (p != &Tail) {
			p->Rand = pl[rands[i] - 1];
			i++;
			p = p->Next;
		};

		f.close();
	}

	else std::cout << "Unable to open file";


}

void ListRand::AddNode(std::string d)
{
	Count++;
	new ListNode(&Head, Head.Next, this, d);
	
}

void ListRand::AddNodeToTail(std::string d)
{
	Count++;
	new ListNode(Tail.Prev, &Tail,this, d);
}

ListRand::ListRand()
{
	Head = ListNode();
	Tail = ListNode();
	Head.Next = &Tail;
	Tail.Prev = &Head;
	Count = 0;

}

ListRand::~ListRand()
{
	ListNode* p = Head.Next;
	while (p->Next != 0) {
		Head.Next = p->Next;
		delete p;
		p = Head.Next;
	}

}

void ListRand::PrintAll()
{
	ListNode* p = Head.Next;
	while (p->Next != nullptr) {
		std::cout << p->Data << " rand to " << p->Rand->Data << std::endl;
		p = p->Next;
	}
	std::cout << "________________________" << std::endl;
}


