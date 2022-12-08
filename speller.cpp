#include <iostream>
#include <string>
#include <ctime>
#include <sys/resource.h>
#include <fstream>
#include <iomanip>
#include "dictionary.h"

using namespace std;

class Speller
{
    // For benchmarking
    Dictionary dic;
    struct rusage before, after;
    double time_load = 0.0, time_check = 0.0;
    double calculate(const struct rusage *b, const struct rusage *a)
    {
        if (b == NULL || a == NULL)
        {
            return 0.0;
        }
        else
        {
            return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                      (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                     ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                      (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec))) /
                    1000000.0);
        }
    }

public:
    void start(const char* textFile, const char* dictionary = "dictionary/dict")
    {
        getrusage(RUSAGE_SELF, &before);
        bool is_loaded = dic.load(dictionary);
        getrusage(RUSAGE_SELF, &after);

        if (!is_loaded)
        {
            cout << "Could not load " << dictionary << endl;
            exit(1);
        }
        time_load = calculate(&before, &after); // Get the time for loading the dict

        ifstream read_f(textFile); // Open file in readmode
        if (!read_f)
        {
            cout << "Could not read " << textFile << endl;
            exit(1);
        }
        cout << "\nMISSPELLED WORDS\n\n";

        size_t index = 0, misspelling = 0, words = 0;
        string word;

        // Read letter by letter
        char c;
        while (read_f.get(c))
        {
            if (isalpha(c) || (c == '\'' && index > 0))
            {
                word += c;
                index++;
                // If string  too  long  to be a word
                if (index > 45)
                {
                    while (read_f.get(c) && isalpha(c))
                        ;
                    // to get new words
                    index = 0;
                }
            }
            // Ignore words with number
            else if (isdigit(c))
            {
                while (read_f.get(c) && isalnum(c))
                    ;
                index = 0;
            }
            // When we find the whole word
            else if (index > 0)
            {
                // Terminate current word

                words++;

                getrusage(RUSAGE_SELF, &before);
                bool misspelled = dic.check(word);
                getrusage(RUSAGE_SELF, &after);

                time_check += calculate(&before, &after);

                if (!misspelled)
                {
                    cout << word << "\n";
                    misspelling++;
                }

                index = 0;
                word = "";
            }
        }
        read_f.close();

        getrusage(RUSAGE_SELF, &before);
        size_t n = dic.size();
        getrusage(RUSAGE_SELF, &after);

        cout << "\nWORDS MISSPELLED:        " << misspelling << endl;
        cout << "WORDS IN DICTIONARY:       " << n << endl;
        cout << "WORDS IN TEXT FILE:        " << words  << endl;
        cout << "TIME TO LOAD:              " << setprecision(2) << time_load << endl;
        cout << "TIME TO CHECK:             " << setprecision(2) << time_check << endl;
        cout << "TOTAL TIME TAKEN:          " << setprecision(2) << time_load + time_check << endl;

    }
};

int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 2)
    {
        cout << "Usage: ./speller [DICTIONARY] textfile\n" << endl;
        return 1;
    }
    Speller s1;
    (argc == 3) ? s1.start(argv[1], argv[2]) : s1.start(argv[1]);
    return 0;
}