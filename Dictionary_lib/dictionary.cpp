#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "dictionary.h"
#include "../HashMap_lib/hashmap.h"
using namespace std;

void Dictionary::merge(std::vector<std::tuple<std::string, size_t>> &words, size_t low, size_t high, size_t mid)
{
    vector<std::tuple<std::string, size_t>> temp;

	int i, j;
	i = low;
	j = mid + 1;

	while (i <= mid && j <= high) {

		if (std::get<0>(words[i]) <= std::get<0>(words[j])) {
			temp.push_back(words[i]);
			++i;
		}
		else {
			temp.push_back(words[j]);
			++j;
		}

	}

	while (i <= mid) {
		temp.push_back(words[i]);
		++i;
	}

	while (j <= high) {
		temp.push_back(words[j]);
		++j;
	}

	for (int i = low; i <= high; ++i)
		words[i] = temp[i - low];
}

void Dictionary::merge_sort(std::vector<std::tuple<std::string, size_t>> &words, size_t low, size_t high)
{
    if (low >= high)
        return;
    size_t mid = (low+high)/2;
    merge_sort(words, low, mid);
    merge_sort(words, mid + 1, high);
    merge(words, low, high, mid);
}

void Dictionary::dict_sort(std::vector<std::tuple<std::string, size_t>> &word)
{
    // Uses merge sort
    size_t low = 0, high = word.size()-1;
    merge_sort(word, low, high);
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
void Dictionary::comb(std::string &word, std::vector<string> &s, size_t left, size_t right)
{
    if (left == right)
    {
        s.push_back(word);
        return;
    }
    else
    {
        for (size_t i = left; i <= right; i++)
        {
            std::swap(word[left], word[i]);

            comb(word, s, left+1, right);

            std::swap(word[left], word[i]);
        }
    }
}

std::string Dictionary::permute(std::string word)
{
    std::vector<std::string> possible;
    std::string valid;
    comb(word, possible, 0, word.length()-1);
    auto n = possible.size();
    for (auto i = 0; i < n; i++)
    {
        if(check(possible[i])){
            valid = possible[i];
            break;
        }
    }
    return valid;
}