#include "user.h"

using std::string;

bool operator<(const User& lhs, const User& rhs){
	return false;
}

std::ostream& operator<<(std::ostream& os, const User& user){
	return os;
}

bool User::login(string pwd){
	if(pwd == pwd_){
		++loginCount;
		return true;
	}
	return false;
}

//TODO Implement makeUsersFrom
