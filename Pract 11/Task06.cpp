#include <iostream>

bool isSubsequence(const char* subsequence, const char* sequence) {
    //we work with elements from subseq
    //we get the fisrt and we loop seq until we find the element
    //same for all elements from subseq
    //if we reach \0 its a subseq
    const char* subPtr = subsequence; 
    const char* seqPtr = sequence;   

    while (*subPtr != '\0' && *seqPtr != '\0') {
        if (*subPtr == *seqPtr) {
            subPtr++;
        }
        seqPtr++;     
    }

    return *subPtr == '\0';
}

int main() {
    const int SIZE = 256;

    char subsequence[SIZE] = "bad";
    char sequence[SIZE] = "gabd";

    bool isPart = isSubsequence(subsequence, sequence);
    std::cout << std::boolalpha << isPart;
    
}
