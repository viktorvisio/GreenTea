/*
C++ server for web-driven administration with module support.
Copyright (C) 2014  Vladimír Bartošík, Martin Kuzma

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "file.h"
#include <sys/stat.h>

namespace GT{

void getFilesInDirectory(const string &root, list<string> &fileNames, bool recursive, bool absolutePaths)
{
	DIR* directory;
	struct dirent* dirEntity;
	struct stat st;

	if(stat(root.c_str(), &st) == 0)
	{
		if(S_ISREG (st.st_mode))
			fileNames.push_back(root);
		else
			if(S_ISDIR (st.st_mode))
			{
				directory = opendir(root.c_str());

				if(directory != NULL)
				{
					while((dirEntity = readdir(directory)) != NULL)
						if(strcmp(dirEntity -> d_name,".") == 0 || strcmp(dirEntity -> d_name,"..") == 0)
							continue;
						else
						{
							if(lstat((root + (string)dirEntity -> d_name).c_str(), &st) == 0)
							{
								if(absolutePaths)
									fileNames.push_back(root + (string)dirEntity -> d_name);
								else
									fileNames.push_back((string)dirEntity -> d_name);
								if(S_ISDIR (st.st_mode) && recursive)
									getFilesInDirectory((root + (string)dirEntity -> d_name + "/"), fileNames, recursive, absolutePaths);
							}
						}

					closedir(directory);
				}
			}
	}
}

string readTextFile(const string &file_name){
	std::ifstream stream;
	std::string line;
	string ret_string;
	stream.open(file_name.c_str(),std::fstream::in);

	while(getline(stream, line)){
		ret_string.append(line);
	}

	stream.close();

	return ret_string;
}

list<string> readTextFileLines(const string &file_name){
	std::ifstream stream;
	list<string> list;
	std::string line;
	stream.open(file_name.c_str(),std::fstream::in);

	while(getline(stream, line)){
		list.push_back(line);
	}

	stream.close();

	return list;
}



void vecPairToMap(map< string, string>* dst, const vector<string>* src){
	if(src->size() % 2 != 0)
		return;

	string key;
	string value;

	vector<string>::const_iterator it = src->begin();


	for(;it != src->end();it++){
		key = (*it);
		it++;
		value = (*it);
		(*dst)[key] = value;
	}
}

};

