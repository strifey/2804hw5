#ifndef user_h
#define user_h

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

class User {
	public:
		std::string fname, lname;

		User() :fname(""), lname(""), uid_(""), pwd_(""), loginCount(0) {}

		User(std::string firstname, std::string lastname, 
				std::string user_id, std::string password, int lcount)
			:fname(firstname), lname(lastname), uid_(user_id),
			pwd_(password), loginCount(lcount)
		{}

		std::string uid() const {return uid_;}
		std::string pwd() const {return pwd_;}
		int hours() const {return loginCount;}
		bool login(std::string pwd);

		static const std::vector<User> makeUsersFrom(std::vector<std::string>);

		friend bool operator<(const User& lhs, const User& rhs);
		friend std::ostream& operator<<(std::ostream& os, const User& user);

	private:
		std::string uid_, pwd_;
		int loginCount;
};
#endif
