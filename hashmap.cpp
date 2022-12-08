#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include "hashmap.h"

ht_hash_table::ht_hash_table()
{
    this->size = 0;
    memset(table, 0x0, sizeof(table));
}

ht_node::ht_node()
{
    this->next = nullptr;
}

ht_node::ht_node(std::string str)
{
    this->str = str;
    this->next = nullptr;
}


unsigned long ht_hash_table::hash(std::string word)
{
    size_t hash_str = 0;
    size_t str_len = word.length();
    for (size_t i = 0; i < word.length(); i++)
    {
        hash_str += (long)pow(7, str_len - (i + 1)) * word[i];
        hash_str %= TABLE_SIZE;
    }
    return hash_str;
    
}
bool ht_hash_table::insert(std::string word)
{
    size_t key = hash(word);
    if (!table[key])
    {
        table[key] = new ht_node(word);
        if (!table[key])
            return false;
    }
    else
    {
        ht_node *temp = new ht_node();
        if (!temp)
            return false;
        temp->str = word;
        temp->next = nullptr;
        for (auto trav = table[key];; trav = trav->next)
        {
            if (trav->next == nullptr)
            {
                trav->next = temp;
                break;
            }
        }
    }
    size++;
    return true;
}
bool ht_hash_table::lookup(std::string word)
{
    for (size_t i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    size_t key = hash(word);
    if (!table[key])
        return false; // If table not initialized
    if (!table[key]->str.compare(word))
        return true;
    else
    {
        for (auto tmp = table[key]; tmp != nullptr; tmp = tmp->next)
        {
            if (!tmp->str.compare(word))
                return true;
        }
    }
    return false;
}

ht_hash_table::~ht_hash_table()
{
    std::cout << "Unloading the dictionary!" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        while (table[i] != NULL)
        {
            ht_node *tmp = table[i]->next;
            delete (table[i]);
            table[i] = tmp;
        }
    }
}