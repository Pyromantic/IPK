#include "client.h"

using namespace std;

int main(int argc, char** argv) {

	client_args args;

	try {
		args.argumentsParsing(argc, argv);
	} catch (const char* e) {
		cerr << e << endl;
		return 1;
	}

	vector <string> output;
	vector <unsigned int> offsets;

	try {
		client_communication_handle communicati(args.getPortNumber(), args.getHostname());

		communicati.sendArguments(args.getInquiry(), args.getFilter());

		output = communicati.getOutput();
		offsets = communicati.getOffsets();

	} catch (const char* e) {
		cerr << e << endl;
		return 2;
	}

	unsigned int position(0);

	for (unsigned int i(0); i < output.size(); ++i)
		if (position < offsets.size() &&
			i == offsets.at(position)) {
			++position;
			cerr << output.at(i) << endl;
		} else
			cout << output.at(i) << endl;
	return 0;
}
