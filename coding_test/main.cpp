#include <iostream>
#include "JewelShopping.h"
#include "RepByN.h"
#include "LittleFriends.h"
#include "BadUser.h"

using namespace std;

int main(void)
{
	BadUser p1(FileFormat("./BadUser.txt", { FileFormat::Types::List, FileFormat::Types::List, FileFormat::Types::Value }));
	JewelShopping p2(FileFormat("./JewelShopping.txt", { FileFormat::Types::List, FileFormat::Types::List }));
	RepN p3(FileFormat("./RepByN.txt", { FileFormat::Types::Value, FileFormat::Types::Value, FileFormat::Types::Value }));
	LittleFriends p4(FileFormat("./LittleFriends.txt", { FileFormat::Types::Value, FileFormat::Types::Value, FileFormat::Types::List, FileFormat::Types::Value }));

	p1.Run();
	p2.Run();
	p3.Run();
	p4.Run();

	return 0;
}