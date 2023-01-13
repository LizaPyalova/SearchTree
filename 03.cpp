#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct tnode {
	long long value;
	long long min;
	long long max;
	tnode() {
		value = 0;
		min = 0;
		max = 0;
	}
	tnode(long long val, long long mi, long long ma) {
		value = val;
		min = mi;
		max = ma;
	}
};


int main() {

	ifstream in("bst.in");
	ofstream out("bst.out");
	bool res = true;

	long long root = 0;
	long long count = 0;
	long long val = 0;
	long long par = 0;
	string side = "";
	string tmp1 = "";

	if (in.is_open()) {
		in >> count;
		if (count == 0 || count == 1) {
			res = true;
			out << "YES";
			out.close();
		}
		else {
			in >> root;
			tnode tmp;
			vector <tnode> tree(count, tmp);
			tree[0].value = root;
			tree[0].min = INT_MIN;
			tree[0].max = INT_MAX;
			for (int i = 1; i < count; i++) {
				in >> val;
				in >> par;
				in >> side;
				if (side == "R") {
					if (val < tree[par - 1].value || val >= tree[par - 1].max) {
						res=false;
						break;
					}
					else {
						tree[i].value = val;
						tree[i].min = tree[par - 1].value;
						tree[i].max = tree[par - 1].max;
					}
				}
				else {
					if (val >= tree[par - 1].value || val < tree[par - 1].min) {
						res = false; 
						break;
					}
					else {
						tree[i].value = val;
						tree[i].min = tree[par - 1].min;
						tree[i].max = tree[par - 1].value;
					}
				}
			}
		}
	}

	if (res == true) {
		out << "YES";
	}
	else {
		out << "NO";
	}
	out.close();
	in.close();
}
