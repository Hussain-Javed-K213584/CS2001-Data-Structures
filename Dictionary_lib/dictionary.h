#pragma once

#include <string>
#include <vector>
#include "../HashMap_lib/hashmap.h"
class Dictionary
{
    ht_hash_table loader;
    size_t dict_size;
    void merge(std::vector<std::string> words, size_t low, size_t high, size_t mid);
    void merge_sort(std::vector<std::string> words, size_t low, size_t high);
public:
    Dictionary();
    bool check(std::string word);
    bool load(std::string dictionary);
    void dict_sort(std::vector<std::string> word);
    size_t size(void);
};

