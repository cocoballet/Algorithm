#include <vector>
#include <map>
using namespace std;

vector<int> twosum(vector<int> &numbs, int tar) {
    vector<int> ret;
    map<int,int> mapp;
    for(int i = 0; i < numbs.size(); i++)
        mapp.insert(pair<int,int>(numbs[i], i));
    for(int i = 0; i < numbs.size(); i++) {
        int find_val = (tar - numbs[i]);
        map<int,int>::iterator iter = mapp.find(find_val);
        if((iter != mapp.end()) && (iter->second != i)) {
            ret.push_back(i);
            ret.push_back(iter->second);
            return ret;
        }
    }
}
