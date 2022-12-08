#pragma once
#include <iostream>
#include <string>
#define TABLE_SIZE 500000

class ht_node
{
    std::string str;
    ht_node();
    ht_node(std::string str);
    ht_node* next;
    friend class ht_hash_table;
};

class ht_hash_table
{
    size_t size;
    ht_node *table[TABLE_SIZE];
    unsigned long hash(std::string word);

public:
    ht_hash_table();
    bool lookup(std::string word);
    bool insert(std::string word);
    std::string operator[](size_t index);
    ~ht_hash_table();
};