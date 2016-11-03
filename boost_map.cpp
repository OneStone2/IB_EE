#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <boost/container/map.hpp>
using namespace std;

boost::container::map<string,int> data;
vector<string> test1;
vector<string> test2;
vector<string> test3;

double getUnixTime()
{
    struct timespec tv;
    if (clock_gettime(CLOCK_REALTIME, &tv) != 0) return 0;
    return (tv.tv_sec + (tv.tv_nsec / 1000000000.0));
}

string gen() {
    string s;
    for (int i=0;i<7;i++) s+='a'+rand()%26;
    return s;
}

int find(string s) {
	return data[s];
}

void insert(string s) {
	data[s]=0;
}

void erase(string s) {
	data.erase(s);
}

int main() {
        srand(time(0));
        cout << "Input structure size" << endl;
        int n;
        cin >> n;
        cout << "Input no of testcases" << endl;
        int t;
        cin >> t;
        for (int i=0;i<n;i++) {
            string h=gen();
            data[h]=rand()%100000;
            if (i<t) test1.push_back(h);
        }
        random_shuffle(test1.begin(),test1.end());
        double t1=getUnixTime();
        for (int i=0;i<1;i++) {
            int k=0;
            for (int j=0;j<t;j++) {
                find(test1[k]);
                k++;
                if (k==n) k=0;
            }
        }
        cout << getUnixTime()-t1 << endl;
        data.clear();
        for (int i=0;i<n-t/2;i++) {
            data[gen()]=rand()%100000;
        }
        for (int i=0;i<t;i++) {
            string h=gen();
            test2.push_back(h);
            test3.push_back(h);
        }
        random_shuffle(test2.begin(),test2.end());
        random_shuffle(test3.begin(),test3.end());
        double t2=getUnixTime();
        for (int i=0;i<t;i++) {
            insert(test1[i]);
        }
        cout << getUnixTime()-t2 << endl;
        double t3=getUnixTime();
        for (int i=0;i<t;i++) {
            erase(test3[i]);
        }
        cout << getUnixTime()-t3 << endl;
}
