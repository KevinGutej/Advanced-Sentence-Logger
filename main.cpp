#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

string toUpperCase(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string getCurrentTime() {
    time_t now = time(nullptr);
    tm* localtm = localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtm);
    return string(buf);
}

void writeToFile(const vector<string>& sentences, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    file << "----- Writing Log -----" << endl;
    file << "Timestamp: " << getCurrentTime() << endl;

    for (const auto& sentence : sentences) {
        file << toUpperCase(sentence) << endl;
    }

    file << "------------------------" << endl;
    file.close();

    cout << "Data written successfully to " << filename << endl;
}

int main() {
    vector<string> userSentences;
    string input;

    for (int i = 1; i <= 2; ++i) {
        cout << "Please enter sentence " << i << ": ";
        getline(cin, input);
        userSentences.push_back(input);
    }

    userSentences.push_back("Addisional message");
    userSentences.push_back("NNFNAOISFNIOSAFSINFSFASNIOFSNIOFASNIOFASNIOFASNIOFAS");

    writeToFile(userSentences, "vector.txt");

    return 0;
}
