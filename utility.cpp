#include "utility.h"


//template<typename T>
//vector<T> file_to_vector(string filename){
	//vector<T> retV;
	//ifstream fr(filename);
	//std::copy(istream_iterator<T>(fr), istream_iterator<T>(),
		//back_inserter<T>(retV));
	//return retV;
//}

//template<typename T>
//void sort_and_print(vector<T> vec){
	//std::sort(vec.begin(), vec.end());
	//std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	//return;
//}

unordered_map<string, User> user_vector_to_map(vector<User> user_list){
	unordered_map<string, User> user_map;
	for(User c_user : user_list)
		user_map[c_user.uid()] = c_user;
	return user_map;
}

bool check_login(unordered_map<string, User> user_map, string uid, string pwd){
	//unordered_map<string,User>::const_iterator usr_it
	auto usr_it = user_map.find(uid);
	if(usr_it == user_map.end())
		return false;
	return user_map[uid].login(pwd);
}

int countDupPasswords(vector<User> usr_vec, string pwd){
	return (int) count_if(usr_vec.begin(), usr_vec.end(), 
			[pwd](User u){return !u.pwd().compare(pwd);});
}

bool hasID(string uid, vector<User> usr_vec){
	auto it = find_if(usr_vec.begin(), usr_vec.end(), 
			[uid](User u){return !u.uid().compare(uid);});
	if (it == usr_vec.end())
		return false;
	return true;
}

int getTotalLoggedHours(vector<User> usr_vec){
	int cnt = 0;
	for_each(usr_vec.begin(), usr_vec.end(),
			[&cnt](User u){cnt+=u.hours();});
	return cnt;
}
