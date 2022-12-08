#pragma once

#include <string>
#include "hashmap.h"
class Dictionary
{
    ht_hash_table loader;
    size_t dict_size;
public:
    Dictionary();
    bool check(std::string word);
    bool load(std::string dictionary);
    size_t size(void);
};

