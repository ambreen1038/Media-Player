#include "Songs.h"
#include <iostream>
using namespace std;
Songs::Songs() //Default Constructor
{
	song_title = nullptr;
	singer = nullptr;
	genre = nullptr;
	duration = 0;
}
//Parameterized Constructor
Songs::Songs(char* songtitle, char* singerr, char* gernree, double time)
{
	int size = lengthOfName(songtitle);
	song_title = new char[size + 1];
	for (int i = 0;i < size;i++)
	{
		song_title[i] = songtitle[i];
	}
	song_title[size] = '\0';
	int size1 = lengthOfName(singerr);
	singer = new char[size1 + 1];
	for (int i = 0;i < size1;i++)
	{
		singer[i] = singerr[i];
	}
	singer[size1] = '\0';
	int size2 = lengthOfName(gernree);
	genre = new char[size2 + 1];
	for (int i = 0;i < size2;i++)
	{
		genre[i] = gernree[i];
	}
	genre[size2] = '\0';
	duration = time;

}
//Get length of names
int Songs::lengthOfName(char* str)
{
	int size = 0;
	for (int i = 0; str[i] != '\0';i++)
	{
		size++;

	}
	return size;

}
//Get song Title
char* Songs::getname()
{
	return this->song_title;
}
//Get singer Name
char* Songs::getsinger()
{
	return this->singer;
}
//Get genre
char* Songs::getgenre()
{
	return this->genre;
}
//Get duration of Song
int Songs::getduration()
{
	return this->duration;
}
//Overload Assignmnet Operator
Songs& Songs::operator=(const Songs& obj)
{
	song_title = obj.song_title;
	singer = obj.singer;
	genre = obj.genre;
	duration = obj.duration;
	return *this;
}
//Songs::~Songs()
//{
//	delete[] song_title;
//	song_title = nullptr;
//	delete[] singer;
//	singer = nullptr;
//	delete[] genre;
//	genre = nullptr;
//
//}
