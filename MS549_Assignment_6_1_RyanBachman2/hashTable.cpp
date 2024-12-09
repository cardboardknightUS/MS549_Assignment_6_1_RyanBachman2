/*
    Ryan Bachman
    University of Advancing Technology
    MS549 - Data Structures and Testing
    Fall 2024, Grad 2

    Assignment 6.1 - Project - Key Table
    hashTable.cpp
*/

#include "hashTable.h"

template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
    : table(size), tableSize(size) {}

template <typename K, typename V>
size_t HashTable<K, V>::hashFunction(const K& key) const
{
    return hash<K>()(key) % tableSize;
}

template <typename K, typename V>
void HashTable<K, V>::add(const K& key, const V& value) {
    size_t index = hashFunction(key);
    for (auto& pair : table[index])
    {
        if (pair.first == key)
        {
            pair.second = value; // Update existing key
            return;
        }
    }

    table[index].emplace_back(key, value); // Insert new key-value pair
}

template <typename K, typename V>
void HashTable<K, V>::remove(const V& value)
{
    for (auto& bucket : table)
    {
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->second == value)
            {
                bucket.erase(it); // Remove the key-value pair
                return; // Exit the function after successful removal
            }
        }
    }

    throw runtime_error("Value not found."); // Throw if value is not found
}

template <typename K, typename V>
pair<K, V> HashTable<K, V>::getByValue(const V& value) const
{
    for (const auto& bucket : table)
    {
        for (const auto& pair : bucket)
        {
            if (pair.second == value)
            {
                return pair; // Return the matching key-value pair
            }
        }
    }

    throw runtime_error("Value not found."); // Throw if value is not found
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getAll() const
{
    vector<pair<K, V>> allPairs;
    
    // Collect all of the key value pairs using a for loop.
    for (const auto& bucket : table)
    {
        for (const auto& pair : bucket)
        {
            allPairs.push_back(pair);
        }
    }

    // Sort the pairs by their keys.
    sort(allPairs.begin(), allPairs.end(), [](const pair<K, V>& a, const pair<K, V>& b)
        {
            return a.first < b.first;
        });

    return allPairs;
}

// Explicit template instantiation for <int, string>
template class HashTable<int, string>;