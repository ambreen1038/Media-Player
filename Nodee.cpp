#include "Nodee.h"
#include <iostream>
using namespace std;
Nodee::Nodee(Songs data)//Parameterized Constructor
{

	next = nullptr;
	prev = nullptr;
	song = data;
}

