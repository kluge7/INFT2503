#include <iostream>
#include <string>

int main() {
    std::string word1 = "";
    std::cin >> word1;
    std::string word2 = "";
    std::cin >> word2;
    std::string word3 = "";
    std::cin >> word3;

    std::string sentence = word1+ " " + word2 + " " + word3;
    std::cout << sentence << std::endl;

    std::cout << "Length of sentence: " << sentence.length() << std::endl; 
    std::cout << "Length of word1: " << word1.length() << std::endl; 
    std::cout << "Length of word2: " << word2.length() << std::endl; 
    std::cout << "Length of word3: " << word3.length() << std::endl; 

    std::string sentence2 = sentence;
    
    for(int i = 10; i < 13; i++) {
        if(sentence2.length() < i) {
            break;
        }
        sentence2[i] = 'x';
    }
    std::cout << sentence << std::endl;
    std::cout << sentence2 << std::endl;

    std::string sentence_start = "";
    for(int i = 0; i < 5; i++) {
        if(sentence.length() < i) {
            break;
        }
        sentence_start += sentence[i];
    }

    std::cout << sentence << std::endl;
    std::cout << sentence_start << std::endl;

    if(sentence.find("hallo") != std::string::npos) {
        std::cout << "found!" << std::endl;
    }

    int amount = 0;
    int j = 0;
    for(int i = 1; i < sentence.length(); i++) {
        if(sentence[j] == 'e' && sentence[i] == 'r') {
            amount++;
        }
        j++;
    }

    std::cout << amount << std::endl;

    return 0;
}