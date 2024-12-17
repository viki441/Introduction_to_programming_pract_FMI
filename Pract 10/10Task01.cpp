#include <iostream>
//const char* str is the same as const char str[]
int getLength(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        //izmestva razmera s edno napred
        str++;
    }
    return length;
}
int main()
{
    char myArr[] = { 'A', 'B', 'C','\0' };
    int length = getLength(myArr);
    std::cout << length;
}
