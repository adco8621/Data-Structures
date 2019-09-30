#include <fstream>
#include <iostream>

using namespace std;

// Uses an array of structs to parse a book, count and sort words, ignoring unique words,
// and displays probablilty of occurence of the N - N+10 most common words, not counting ignore words
// Struct array is dynamically allocated by hand using array doubling


struct wordItem{
    string word; // word
    int count;   // times ocurred in book
};

// Read a command line specified txt file of words to ignore
void getStopWords (const char *wordsFile, string wordsArr[]){
    ifstream words (wordsFile);
    string line;
    int i = 0;
    if (words.is_open()){
        while(getline(words, line)){
            wordsArr[i] = line;
            i++;
        }
    }
    else{
        cout << "Failed to open " << wordsFile << endl;
    }
}

// checks if word from book is a word to ignore
bool isStopWord (string word, string ignoreArr[]){
    for (int i = 0; i < 50; i++){
        if (word == ignoreArr[i]){
            return true;
        }
    }
    return false;
}

// counts total number of non-ignored words
int getTotalNumberNonStopWords (wordItem uniqueWords[], int length){
    int tot = 0;
    for (int i = 0; i < length; i++){
        tot += uniqueWords[i].count;
    }
    return tot;
}

// Sorts words from most common to least common
void arraySort(wordItem uniqueWords[], int length){
    for (int i = 0; i < length-1; i++){
        for (int j = 0; j < length - i - 1; j++){
            if (uniqueWords[j].count <= uniqueWords[j+1].count){
                wordItem temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j+1];
                uniqueWords[j+1] = temp;
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    // Print next 10 words after Nth word and their probability
    // float Probability = arr[i].count / tot

    cout << "Probability of next 10 words from rank " << N << endl <<
        "---------------------------------------" << endl;
    float prob;
    for (int i = N; i < N + 10; i++){
        prob = (float)uniqueWords[i].count/totalNumWords;
        printf("%.4f", prob);
        cout << " - " << uniqueWords[i].word << endl;
    }
}

// Dynamic array allocation
void dub(wordItem *& arr, int size) {

    wordItem *dbld = new wordItem[size*2];
    for (int i = 0; i < size; i++) {
        dbld[i] = arr[i];
    }
    delete[] arr;
    arr = dbld;
}

int main (int argc, char *argv[]){
    if (argc != 4){ // wrong number of arguments
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }

    string ignoreWords[50];

    getStopWords(argv[3], ignoreWords);

    wordItem *book;
    book = new wordItem[100];

    ifstream in (argv[2]);
    string word;
    int max = 100, current = 0, timesDubbed = 0;
    bool skip;

    while (in >> word){
        skip = false;
        if (isStopWord(word, ignoreWords)){ // check if word is to be skipped
                skip = true;
        }
        if (!skip){
            if (current == max){ // if array is at capacity, double it
                dub(book, max);
                max += max;
                timesDubbed++;
            }
            if (current > 0){ // 1 or more words in array
            int i = 0;
                for (i = 0; i < current; i++){
                    if (book[i].word == word){ // word areay exists in array
                        book[i].count++;
                        break;
                    }
                }
                if(i==current) // word not yet in array
                {
                        book[current].word = word;
                        book[current].count = 1;
                        current++;
                }
            }
            else{ // first word in array
                book[0].word = word;
                book[0].count = 1;
                current=1;
            }
        }
    }

    arraySort(book, current);

    int tot = getTotalNumberNonStopWords(book, current);

    cout << "Array doubled: " << timesDubbed << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << current << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << tot << endl;
    cout << "#" << endl;

    printNext10(book, stoi(argv[1]), tot);

    return 0;


}