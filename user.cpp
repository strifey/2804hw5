#include "user.h"

using std::string;
using std::vector;
using std::getline;
using std::endl;

bool operator<(const User& lhs, const User& rhs){
	if(lhs.lname.compare(rhs.lname) == 0){
		if(lhs.fname.compare(rhs.fname) < 0)
			return true;
		return false;
	}
	else{
		if(lhs.lname.compare(rhs.lname) < 0)
			return true;
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const User& user){
	os<<user.fname<<", "<<user.lname<<"\t\t";
	os<<"UID: "<<user.uid()<<"\t\t";
	os<<"Pass: "<<user.pwd()<<"\t\t";
	os<<"Hours: "<<user.hours()<<endl;
	return os;
}

bool User::login(string pwd){
	if(pwd_.compare(pwd) == 0){
		++loginCount;
		return true;
	}
	return false;
}

const vector<User> User::makeUsersFrom(vector<string> user_list){
	vector<User> ret_usr_vec;
	for(string user_string : user_list){
		std::istringstream user_stream(user_string);
		string uid, lname, fname, pwd, loginCount = "";
		getline(user_stream, uid, ',');
		getline(user_stream, fname, ',');
		getline(user_stream, lname, ',');
		getline(user_stream, pwd, ',');
		getline(user_stream, loginCount, ',');
		int lcount = 0;
		std::istringstream lcnt_stream(loginCount);
		lcnt_stream>>lcount;
		ret_usr_vec.push_back(User(fname,lname,uid,pwd,lcount));
	}
	return ret_usr_vec;
}
