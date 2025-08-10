// Just a simple hello world test
// g++ -std=c++11 -g -o ch4_t5_badwords.exe ch4_t5_badwords.cpp  2>&1 | tee tmp.txt

#include "std_lib_facilities.h"

vector<string> badwords = {"zero", "one", "two"};

int is_badw (string str) {
    for (int i=0; i<badwords.size(); ++i) {
        if (badwords[i] == str)
            return 1; // found a bad word
    }
    return 0;   // did not find a bad word
}

void print_bad_words() {
    cout << "Bad words using print_bad_words:\n";
    for (string w:badwords){
        cout << w << endl;
    }
}

void print_bad_words_2() {
    cout << "Bad words using print_bad_words_2:\n";
    for (int i=0; i<badwords.size(); ++i){
        cout << "i=="<<i << ": "<< badwords[i] << endl;
    }
}

int main ()
{
    print_bad_words();
    print_bad_words_2();
    cout << "Please enter several words. Ctrl-D when you are done.\n";
    vector<string> words;
    for (string temp; cin>> temp; ){ // read whitespace - separated words
        words.push_back(temp);
    }

    cout <<"Number of words: " << words.size() << endl;

    sort(words);

    for (int i=0; i<words.size(); ++i){
        string check_word = words[i];
        if ( (i==0) || (words[i-1]!=check_word) ) {  // is a new non-repeating word
            if (is_badw(check_word)){
                cout << "BLEEP\n";
            } else {
                cout << check_word << endl;
            }
        }
    }
}
