/*
 * string.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#include "string.h"

namespace GT{

char toStringIntbuffer[BUFFSIZE]; // static buffer, no other allocations needed

const char* toString(const int &input){
	string s;
	int t;
	if(input < 0)
		t = -input;
	else
		t = input;

	int i = LAST_BUFF_INDEX - 1;
	toStringIntbuffer[LAST_BUFF_INDEX] = 0;

	do{
		toStringIntbuffer[i] =  t%10 + '0';
		--i;
		t/=10;
	}while(t > 0);

	if(input < 0)
		toStringIntbuffer[i] = '-';
	else
		toStringIntbuffer[i] = ' ';

	return &toStringIntbuffer[i];
}

const char* toStringHex(const int &input){
	string s;
	int t;
	int h;
	if(input < 0)
		t = -input;
	else
		t = input;

	int i = 9;
	toStringIntbuffer[10] = 0;

	do{
		h = t%16;
		if(h > 9)
			toStringIntbuffer[i] =  t%16 + '7';
		else
			toStringIntbuffer[i] =  t%16 + '0';

		--i;
		t/=16;

	}while(t > 0);

	toStringIntbuffer[i] = 'x';
	--i;
	toStringIntbuffer[i] = '0';
	--i;

	if(input < 0)
		toStringIntbuffer[i] = '-';
	else
		toStringIntbuffer[i] = ' ';

	return &toStringIntbuffer[i];
}

vector<string> split(const string &src, const string &delimiters){
	vector<string> list;
	string substr;

	int p = 0;
	int s = 0;

	p = src.find_first_of(delimiters,s);

	while(p != -1){
		if(s != p){
			list.push_back(src.substr(s,p-s));
		}

		s = p + 1;
		p = src.find_first_of(delimiters,s);
	}

	if(s < src.size()){
		list.push_back(src.substr(s));
	}

	return list;
}

vector<string> splitWithEmpty(const string &src, const string &delimiters){
	vector<string> list;
	string substr;

	int p = 0;
	int s = 0;

	p = src.find_first_of(delimiters,s);

	while(p != -1){
		if(s != p){
			list.push_back(src.substr(s,p-s));
		}
		else
			list.push_back("");

		s = p + 1;
		p = src.find_first_of(delimiters,s);
	}

	if(s < src.size()){
		list.push_back(src.substr(s));
	}

	return list;
}

string replaceAll(const string &src, const string &toReplace, const string &replacingString)
{
	string ret = src;

	for(size_t pos = 0; ;pos += replacingString.length())
	{
		pos = ret.find(toReplace, pos);
		if( pos == string::npos ) //reached end of string
			break;
		ret.erase(pos, toReplace.length());
		ret.insert(pos, replacingString);
	}

	return ret;
}

};
