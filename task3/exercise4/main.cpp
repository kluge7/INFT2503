#include <string>
#include <iostream>

using namespace std;

int main() {
    // 4a
    string word1;
    string word2;
    string word3;

    cout << "Enter three words: ";
    cin >> word1 >> word2 >> word3;
    cout << "You entered: " << word1 << " " << word2 << " " << word3 << endl;

    // 4b
    string sentence = word1 + " " + word2 + " " + word3;
    cout << "The sentence is: " << sentence << endl;

    // 4c
    cout << "The length of the sentence " << sentence << " is: " << sentence.length() << endl;
    cout << "The length of the word " << word1 << " is: " << word1.length() << endl;
    cout << "The length of the word " << word2 << " is: " << word2.length() << endl;
    cout << "The length of the word " << word3 << " is: " << word3.length() << endl;
    
    // 4d
    string sentence2 = sentence;

    // 4e
    for(int i = 9; i < 12 && i < sentence2.length(); i++) {
        sentence2[i] = 'x';
    }
    cout << "Sentence2 is now: " << sentence2 << endl;

    // 4f
    string sentence_start;
    if (sentence.length() >= 5) {
        sentence_start = sentence.substr(0, 5);
    } else {
        sentence_start = sentence;
    }
    cout << "The first five characters of the sentence are: " << sentence_start << endl;
    
    // 4g
    string hallo = "hallo";
    if(sentence.find(hallo) != std::string::npos) {
        cout << "The sentence contains the word " << hallo << endl;
    } else {
        cout << "The sentence does NOT contain the word " << hallo << endl;
    }
    
    // 4h
    string search_word = "er";
    size_t pos = sentence.find(search_word);
    int amount = 0;
    if (pos == string::npos) {
        cout << "The word " << search_word << " was not found in the sentence " << sentence << endl;
    } else {
        while(pos != string::npos) {
            amount++;
            pos = sentence.find(search_word, pos + 1);
        }
        cout << "The word " << search_word << " was found " << amount << "times" << endl;
    }
}
