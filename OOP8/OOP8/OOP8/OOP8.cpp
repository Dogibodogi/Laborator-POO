#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
template <typename T> class Compare {
public:
    bool operator() (const T& a, const T& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};
map<string, int> countWords(const string& text) {
    map<string, int> wordCount;
    string separators = " ,?!.";

    string currentWord = "";
    for (char ch : text) {
        if (separators.find(ch) == string::npos) {
            currentWord += tolower(ch);
        }
        else if (!currentWord.empty()) {
            wordCount[currentWord]++;
            currentWord.clear();
        }
    }

    return wordCount;
}
void printWordCount(const map<string, int>& wordCount) {
    for (const auto& it : wordCount) {
        cout << it.first << ": " << it.second << endl;
    }
}
void printWordQueue(const map<string, int>& wordCount) {
    typedef pair<string, int> wordPair;
    priority_queue<wordPair, vector<wordPair>, Compare<wordPair>> wordQueue;

    for (const auto& it : wordCount) {
        wordQueue.push(make_pair(it.first, it.second));
    }

    while (!wordQueue.empty()) {
        cout << wordQueue.top().first << " => " << wordQueue.top().second << endl;
        wordQueue.pop();
    }
}

int main() {
    string inputBuffer;
    string text = "";
    ifstream fin("input.txt");
    while (getline(fin, inputBuffer)) {
        text += inputBuffer + "\n";
    }
    fin.close();

    map<string, int> wordCount = countWords(text);
   
    printWordCount(wordCount);
    cout << endl;
    printWordQueue(wordCount);

    return 0;
}