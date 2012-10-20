#ifndef user_h
#define user_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class User {
	public:
		std::string fname, lname;

		User(std::string firstname, std::string lastname, 
				std::string user_id, std::string password)
			:fname(firstname), lname(lastname), uid_(user_id),
			pwd_(password), loginCount(0)
		{}
		std::string uid(){return uid_;}
		std::string pwd(){return pwd_;}
		int hours(){return loginCount;}
		bool login(std::string pwd);

		const std::vector<User> makeUsersFrom(std::vector<std::string>);

		friend bool operator<(const User& lhs, const User& rhs);
		friend std::ostream& operator<<(std::ostream& os, const User& user);

	private:
		std::string uid_, pwd_;
		int loginCount;
};
#endif
