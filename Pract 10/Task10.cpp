#include <iostream>
#include <cctype>
using namespace std;

bool compareWords(const char* word1, const char* word2) {
    while (*word1 && *word2) {
        if (tolower(*word1) != tolower(*word2)) {
            return false;
        }
        word1++;
        word2++;
    }
    return *word1 == '\0' && *word2 == '\0';
}

void addOrUpdateWord(const char* word, char words[][50], int* frequency, int& wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (compareWords(word, words[i])) {
            frequency[i]++;
            return;
        }
    }

    int i = 0;
    while (word[i] != '\0') {
        words[wordCount][i] = word[i];
        i++;
    }
    words[wordCount][i] = '\0';

    frequency[wordCount] = 1;   
    wordCount++;               
}

const char* findMostCommonWord(const char* inputArray) {
    const int MAX_WORDS = 100;    
    const int WORD_LENGTH = 50;  
    char words[MAX_WORDS][WORD_LENGTH] = {};
    int frequency[MAX_WORDS] = { 0 };          
    int wordCount = 0;                     

    char currentWord[WORD_LENGTH] = { 0 };     
    int currentLength = 0;                   

    while (*inputArray != '\0') {
        if (isalpha(*inputArray)) { 
            currentWord[currentLength++] = tolower(*inputArray);
        }
        else if (currentLength > 0) {
            currentWord[currentLength] = '\0'; 
            addOrUpdateWord(currentWord, words, frequency, wordCount); 
            currentLength = 0;
        }
        inputArray++;
    }

    if (currentLength > 0) {
        currentWord[currentLength] = '\0';
        addOrUpdateWord(currentWord, words, frequency, wordCount);
    }

    int maxFrequency = 0;
    int mostCommonIndex = -1;
    for (int i = 0; i < wordCount; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostCommonIndex = i;
        }
    }

    return (mostCommonIndex != -1) ? words[mostCommonIndex] : nullptr;
}

int main() {
    const char inputArray[] = {
        'H', 'e', 'l', 'l', 'o', ',', ' ',
        'H', 'E', 'L', 'L', 'O', '!', ' ',
        'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', '\0'
    };

    const char* mostCommonWord = findMostCommonWord(inputArray);

    if (mostCommonWord) {
        cout << "The most common word is: " << mostCommonWord << endl;
    }
    else {
        cout << "No words found in the input." << endl;
    }
}
