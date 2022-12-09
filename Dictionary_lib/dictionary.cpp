#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include "dictionary.h"
#include "../HashMap_lib/hashmap.h"
using namespace std;

void Dictionary::merge(std::vector<std::string> words, size_t low, size_t high, size_t mid)
{
    size_t left_arr = high - mid + 1;
    size_t right_arr = high - mid;

    // Temp vectors
    std::vector<std::string> left_vec, right_vec, tmp;

    for (size_t i = 0; i < left_arr; i++)
        left_vec.push_back(words[low + i]);
    for (size_t i = 0; i < right_arr; i++)
        right_vec.push_back(words[mid + 1 + i]);
    for (size_t i = 0; i < right_arr; i++)
        words.pop_back();
    size_t i = 0, j = 0, k = low;

    while (i < left_arr && j < right_arr)
    {
        if (left_vec[i] <= right_vec[j])
        {
            words.push_back(left_vec[i]);
            i++;
        }
        else
        {
            words.push_back(right_vec[j]);
            j++;
        }
        k++;
    }

    while (i < left_arr)
    {
        words.push_back(left_vec[i]);
        i++;
        k++;
    }

    while (j < right_arr)
    {
        words.push_back(right_vec[j]);
        j++;
        k++;
    }
}

void Dictionary::merge_sort(std::vector<std::string> words, size_t low, size_t high)
{
    if (low >= high)
        return;
    size_t mid = low + (high - low) / 2;
    merge_sort(words, low, mid);
    merge_sort(words, mid + 1, high);
    merge(words, low, high, mid);
}

void Dictionary::dict_sort(std::vector<std::string> words)
{
    // Uses merge sort
    size_t low = 0, high = words.size();
    merge_sort(words, low, high);
}

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
    while (getline(read_obj, word))
    {
        ++dict_size;
        for (size_t i = 0; i < word.length(); i++)
            word[i] = tolower(word[i]);
        loader.insert(word);
    }
    read_obj.close();
    return true;
}

size_t Dictionary::size(void)
{
    return dict_size;
}