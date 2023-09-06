#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    int s = q.size();
    int n = 0;
    for(int i = 0; i < s; i++) {
        if(q[i] > i + 3) {
            cout << "Too chaotic" << endl;
            return;    
        }
        if(q[i] <= i + 1) {
            int loops = i - q[i] + 2;
            for(int j = 0; j < loops; j++) {
                if(i - 1 - j >= 0 && q[i] < q[i - 1 - j]) {
                    // cout << q[i] << " < " << q[i - 1 - j] << endl;
                    n ++;
                }
            }
        }
    }
    cout << n << endl;
}


void minimumBribesAlt(vector<int> q) {
    int bribeCounter = 0;
    int s = q.size();
    for(int i = 0; i < s; i++) {
        int bribes = 0;
        for(int j = i + 1; j < s; j++) {
            if(q[j] < q[i]) {
                bribes++;
                cout << q[i] << " > " << q[j] << endl;
            }
            if(bribes > 2) {
                cout << "Too chaotic" << endl;
                return;   
            }
        }
        bribeCounter += bribes;
    }
    cout << bribeCounter << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
