#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "user.h"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char*argv[]){
	if(argc < 5){
		cout<<"Not enough commands. Should be: \n\t loginProg testUser testPwd dupPwd testUID"<<endl;
		exit(1);
	}

}
