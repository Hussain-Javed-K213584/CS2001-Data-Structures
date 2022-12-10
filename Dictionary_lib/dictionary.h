#pragma once

#include <string>
#include <vector>
#include "../HashMap_lib/hashmap.h"
class Dictionary
{
    ht_hash_table loader;
    size_t dict_size;
    void merge(std::vector<std::tuple<std::string, size_t>> &words, size_t low, size_t high, size_t mid);
    void merge_sort(std::vector<std::tuple<std::string, size_t>> &words, size_t low, size_t high);
    void comb(std::string &word, std::vector<std::string> &s, size_t left, size_t right);
public:
    Dictionary();
    bool check(std::string word);
    bool load(std::string dictionary);
    void dict_sort(std::vector<std::tuple<std::string, size_t>> &word);
    std::string permute(std::string);
    size_t size(void);
};

