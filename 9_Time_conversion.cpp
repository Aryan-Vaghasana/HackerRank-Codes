#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    string period = s.substr(8, 2);   // AM or PM
    int hour = stoi(s.substr(0, 2));  // first two chars as int

    if (period == "AM") {
        if (hour == 12) {
            hour = 0; // midnight case
        }
    } else { // PM
        if (hour != 12) {
            hour += 12; // afternoon/evening case
        }
    }

    // format hour to always be two digits
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << s.substr(2, 6);
    return ss.str();
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
