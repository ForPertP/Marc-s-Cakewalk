#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end(), greater<int>());

    long long miles = 0;
    for (int i = 0; i < calorie.size(); ++i)
    {
        miles += calorie[i] * (1LL << i);
    }

    return miles;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split(rtrim(calorie_temp_temp));

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }

    long result = marcsCakewalk(calorie);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}
