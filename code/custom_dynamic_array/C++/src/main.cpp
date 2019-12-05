#include "../include/dynarray.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Dynarray<std::string> dyn;

	dyn.push("salut");
	dyn.push("ça");
	dyn.push("va");
	dyn.push("mec");
	dyn.push("?");

	dyn.insert("!", 4);
	dyn.del(2);
	dyn.remove("mec");

	dyn.print();

	return 0;
}