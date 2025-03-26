#pragma once
class Songs
{
	char* song_title;
	char* singer;
	char* genre;
	double duration;
public:
	Songs();
	Songs(char* songtitle, char* singerr, char* gernree, double time);
	int lengthOfName(char* str);
	char* getname();
	char* getsinger();
	char* getgenre();
	int getduration();
	Songs& operator=(const Songs& obj);

	//~Songs();

};

