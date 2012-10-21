#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "user.h"
#include "utility.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

void usage() {
  cout<<"Wrong argument count"<<endl<<"1 - test user id for login"<<endl<<"2 - test user password for login"<<endl;
  cout<<"3 - password to count for duplicates"<<endl<<"4 - uid to find"<<endl;
}

int main(int argc, char** argv)
{
    cout << "STL Homework" << endl;
    if (argc != 5) {
       usage();
       return 0;
    }
    string testUid(argv[1]);
    string testPwd(argv[2]);
    string dupPwd(argv[3]);
    string id2find(argv[4]);

    cout<<"Arguments: login test for: "<<testUid<<", "<<testPwd<<endl;
    cout<<"dup password check: "<<dupPwd<<" id to find: "<<id2find<<endl;
    //read the text file into a vector of strings
    vector<string> vec = file_to_vector<string>("test.txt");
    //method that takes in a vector, sorts and prints it
    cout<<"------------------------------------------------------"<<endl;
    cout<<"         SORTED STRING VECTOR"<<endl;
    sort_and_print(vec);
    cout<<endl;
    //go through the vector and create the user objects
    vector<User> users = User::makeUsersFrom(vec);
    cout<<"------------------------------------------------------"<<endl;
    cout<<"          SORTED USER LIST"<<endl;
    sort_and_print((users));
    cout<<endl;
    //store them in an appropriate data structure
    unordered_map<string, User> user_map = user_vector_to_map(users);
    cout<<endl;
    //implement login method to look up id, check password
    cout<<"Testing Login for uid = "<<testUid<<" and pwd = "<<testPwd<<endl;
    if (check_login(user_map, testUid, testPwd)) {
       cout<<"Good login for test"<<endl;
    } else {
       cout<<"Bad login for test"<<endl;
    }

    //method to count the number of users with a given password
    int cnt = countDupPasswords(users, dupPwd);
    cout<<"Number of people with password = "<<dupPwd<<" is: "<<cnt<<endl;
    //method to find if any of the users have a particular id
    bool found = hasID(id2find, users);
    if (found) {
       cout<<"Found user: "<<id2find<<endl;
    } else {
       cout<<"User not found"<<endl;
    }
    //method to sum up total logged in hours
    int total_hours = getTotalLoggedHours(users);
    cout<<"Total logged hours were: "<<total_hours<<endl;

    return 0;
}
