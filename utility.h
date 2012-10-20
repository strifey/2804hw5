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

template<typename T>
vector<T> file_to_vector(std::string filename);

template<typename T>
void sort_and_print(vector<T>);

std::unordered_map<std::string, User> user_vector_to_map(vector<User>);

//TODO figure out how to make check_login

int countDupPasswords(vector<User>, std::string pwd);

bool hasID(vector<User>, std::string uid);

//TODO figure out gettotalloggedhours
#endif
