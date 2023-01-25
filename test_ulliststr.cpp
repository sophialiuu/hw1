#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;

	list.push_back("oldfront");
	list.push_back("oldback");

	//EXPECT_TRUE(checkListContent(&list, {"oldfront", "oldback"}));

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");

	//EXPECT_TRUE(checkListContent(&list, {"newfront", "oldback"}));

	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront", "newfront"}));

	// now, the original head should get deleted
	list.pop_back();

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront"}));

	list.pop_front();

	//EXPECT_TRUE(checkListContent(&list, {}));

	list.push_front("newback");

	//EXPECT_TRUE(checkListContent(&list, {"newback"}));


}
