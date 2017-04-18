#include <stdio.h>
#include <algorithm>
#include <functional>

class CharSorter {
public:
    CharSorter(bool isAscending = true, bool isCaseSensitive = true)
    : mIsAscending(isAscending)
    , mIsCaseSensitive(isCaseSensitive) {}
    
    bool operator()(char a, char b) {
        char first = a;
        char second = b;
        if (!mIsCaseSensitive) {
            first = tolower(first);
            second = tolower(second);
        }
        return mIsAscending ? first < second : second < first;
    }
    
private:
    bool mIsAscending;
    bool mIsCaseSensitive;
};

int main()
{
    
    char charArray[] = "abcdefghijklmnopqrstuvwxyz";
    std::sort(charArray, charArray+sizeof(charArray)-1, CharSorter(false));
    printf("%s\n", charArray);
    
    char name[] = "Amandeep Chawla";
    std::sort(name, name + sizeof(name)-1, CharSorter(true, false));
    printf("%s\n", name);
    std::sort(name, name + sizeof(name)-1, CharSorter());
    printf("%s\n", name);
}
