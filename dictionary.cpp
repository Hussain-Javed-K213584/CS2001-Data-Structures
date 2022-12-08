#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "hashmap.h"
using namespace std;

Dictionary::Dictionary()
{
    dict_size = 0;
}
bool Dictionary::check(string word)
{
    return loader.lookup(word);
}
bool Dictionary::load(string dictionary)
{
    ifstream read_obj(dictionary);
    if (!read_obj)
    {
        return false;
    }
    string word;
    while(getline(read_obj, word))
    {
        ++dict_size;
        for  (size_t i  = 0; i <  word.length(); i++) word[i] = tolower(word[i]);
        loader.insert(word);
    }
    read_obj.close();
    return true;
}

size_t Dictionary::size(void)
{
    return dict_size;
}