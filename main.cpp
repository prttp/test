#include"test.h"

int main() {

	ListRand test;
	test.AddNode("abc");
	test.AddNode("def");
	test.AddNode("ghi");
	test.AddNode("klm");
	test.AddNode("nop");
	test.AddNode("qrs");
	test.PrintAll();
	std::ofstream f;
	f.open("test.txt");
	test.Serialize(f);
	test.PrintAll();
	ListRand test2;
	std::ifstream i;
	i.open("test.txt");
	test2.Deserialize(i);
	test2.PrintAll();
	return 0;
}