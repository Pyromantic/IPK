/*
 * server_users_parser.cpp
 *
 *  Created on: Mar 27, 2015
 *      Author: majk
 */

#include "server_users_parser.h"

server_users_parser::server_users_parser
(vector <string> inquirySetter, vector <char> argFilter) {

	initialize(inquirySetter, argFilter);

	applyInquiry();

	applyFilter();

	 for (auto it(output.begin()); it < output.end(); ++it)
			cout << *it << endl;
};

server_users_parser::~server_users_parser() {

};

void server_users_parser::applyFilter() {

	if (!filter.size())
		return;

	for (auto it(offsets.begin()); it < offsets.end(); ++it)
		output.at(*it) = filterData(output.at(*it));
};

string server_users_parser::filterData (string data) {

	vector <string> exploded (explodeString (data));

	string final;

	for (auto it(filter.begin()); it < filter.end(); ++it)
		switch (*it) {
		case USER_NAME :
			final.append("," + exploded.at(*it));
			break;

		case UID :
			final.append("," + exploded.at(*it));
			break;

		case GID :
			final.append("," + exploded.at(*it));
			break;

		case WHOLE_NAME :
			final.append("," + exploded.at(*it));
			break;

		case HOME_DIR :
			final.append("," + exploded.at(*it));
			break;

		case LOG_SHELL :
			final.append("," + exploded.at(*it));
			break;
		}

	final.erase(final.begin());	// erase initiate char ','

	return final;
};

vector <string> server_users_parser::explodeString (string data) {

	vector <string> exploded;
	istringstream sstream(data);
	string token;

	while(getline(sstream, token, ':'))
	   exploded.push_back(token);

	exploded.erase(exploded.begin() + PASSWD);

	return exploded;
};

void server_users_parser::applyInquiry () {

	string switcher (getSwitcher());

	parseFile();
};

string server_users_parser::getSwitcher () {
	string switcher (*inquiry.begin());

	inquiry.erase(inquiry.begin());

	return switcher;
};

void server_users_parser::parseFile () {

	string line;

	vector <string> tmp (inquiry);

	int position(0);
	int offset(0);

	openPasswd();	// opens file

	while (!getline(file, line).eof()) {	// reads file line by line

		auto nameEnd (line.find(":"));		// finds firsts ':'

		string name(line.substr(FIRST_CHAR, nameEnd));	// substrings name

		position = 0;

		for (auto it (tmp.begin()); it < tmp.end(); ++it) {	// compares names to inquiry values
			if (!name.compare(*it)) {

				offset = (inquiry.size() - tmp.size()) + position;	// calculates offset

				offsets.push_back(offset);	// saves offset

				output.at(offset) = line;	// push to output

				tmp.erase(it);				// erase it for faster parsing
			}
			++position;
		}

		if (!tmp.size())	// if its nothing more to compare
			break;
	}

	closePasswd();	// close file
};

void server_users_parser::openPasswd () {
	file.open(path2passwd, ifstream::in);	// open passwd for reading

	if (file.is_open())		// if its open
		return;
};

void server_users_parser::closePasswd() {
	file.close();
};

void server_users_parser::initialize
(vector <string> inquirySetter, vector <char> argFilter) {

	filter = argFilter;
	inquiry = inquirySetter;

	for (auto it (inquiry.begin() + SWITCHER); it < inquiry.end() ; ++it)
		output.push_back(defaultLoginOutput + *it);
};

const char* server_users_parser::defaultLoginOutput {"Chyba: neznamy login "};

const char* server_users_parser::path2passwd {"/home/majk/secured/passwd"};
