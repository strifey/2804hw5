#ifndef utility_h
#define utility_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include "user.h"

using std::vector;
using std::string;
using std::istream_iterator;
using std::back_inserter;
using std::ifstream;
using std::unordered_map;

template<typename T>
vector<T> file_to_vector(std::string filename);

template<typename T>
void sort_and_print(vector<T>);

template<typename T>
vector<T> file_to_vector(string filename){
	vector<T> retV;
	ifstream fr(filename);
	std::copy(istream_iterator<T>(fr), istream_iterator<T>(),
		back_inserter(retV));
	return retV;
}

template<typename T>
void sort_and_print(vector<T> vec){
	std::sort(vec.begin(), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	return;
}

std::unordered_map<std::string, User> user_vector_to_map(vector<User>);

bool check_login(std::unordered_map<std::string, User> user_map, 
		std::string uid, std::string pwd);

int countDupPasswords(vector<User>, std::string pwd);

bool hasID(std::string uid, vector<User> usr_vec);

int getTotalLoggedHours(vector<User>);
#endif
