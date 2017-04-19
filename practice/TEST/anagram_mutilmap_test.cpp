// read from file
// creat map
// print map
// write to file (log?)

#include <iosteram>    //which to be include in c?
#include <fstream>     //which to be include in c?
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	char *dictname = argv[1];
	ifstream dict;
	string str;
	set<string> dict_set;
	mutilmap<string, string> dict_map;
	
	dict.open(dictname, ifstream::in);
	if(!dictname) {
		cerr << "can't open file;" << endl;
		return -1;
	}
	while(getline(dict, str)) {
		string sort_str = str;
		sort(sort_str.begin(), sort_str.end());
		dict_map.insert(make_pair(sort_str, str));
		dict_set.insert(sort_str);
	}
	dict.close();
	dict.clear();
	
	ofstream ret("sort_dict");
	if(!ret.open()) {
		cerr <<"ERROR happen;" << endl;
		return -2;
	}
	for(set<string>::iterator s_iter = dict_set.begin(); s_iter != set.end(); ++s_iter）{
		if(dict_map.count(*s_iter) > 1) {
			ret << dict_map.find(*s_iter) << endl;
		}
	}
	ret.close();
	ret.clear();
	
	return 0;
}
