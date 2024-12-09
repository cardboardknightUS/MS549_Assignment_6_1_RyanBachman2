/*
    Ryan Bachman
    University of Advancing Technology
    MS549 - Data Structures and Testing
    Fall 2024, Grad 2

    Assignment 6.1 - Project - Key Table
    linearProbing.cpp
*/

#include "linearProbing.h"

// Constructor: Initializes the linear probing hash table with empty slots and default size.
template <typename K, typename V>
LinearProbingHashTable<K, V>::LinearProbingHashTable(size_t size)
    : table(size, deletedMarker), occupied(size, false), tableSize(size), elementCount(0) {}

// Hash function: Computes the index for a given key using std::hash and the modulus sign (%).
template <typename K, typename V>
size_t LinearProbingHashTable<K, V>::hashFunction(const K& key) const
{
    return hash<K>()(key) % tableSize;
}

// Find the position of a key using linear probing.
template <typename K, typename V>
size_t LinearProbingHashTable<K, V>::findPosition(const K& key) const
{
    size_t index = hashFunction(key);
    size_t start = index; // Saves the starting position to detect for infinite loops.

    // Probe until we find the key or an empty slot.
    while (occupied[index] && table[index].first != key)
    {
        index = (index + 1) % tableSize; // Move to the next slot and wrap around if needed.

        if (index == start)
        {
            throw runtime_error("Hash table is full."); // Throw a runtime error if the hash table is full.
        }
    }
    return index;
}

// Add a key-value pair to the hash table.
template <typename K, typename V>
void LinearProbingHashTable<K, V>::add(const K& key, const V& value)
{
    // Resize the table if the load factor exceeds the threshold. This is part of getting linear probing to work.
    if (static_cast<double>(elementCount) / tableSize > loadFactor)
    {
        resize();
    }

    size_t index = findPosition(key); // Find the position to insert/update the key-value pair.

    // If the slot is empty, mark it as occupied and increment the element count. Also a new addition with linear probing over the traditional hash table that I did.
    if (!occupied[index])
    {
        elementCount++;
        occupied[index] = true;
    }
    table[index] = { key, value }; // Insert or update the key-value pair.
}

// Remove a key-value pair based on its value.
template <typename K, typename V>
void LinearProbingHashTable<K, V>::remove(const V& value)
{
    for (size_t index = 0; index < tableSize; ++index)
    {
        // Find the matching value in the table.
        if (occupied[index] && table[index].second == value)
        {
            table[index] = deletedMarker; // Mark the slot as deleted so that it can be reused.
            occupied[index] = false; // Mark the slot as unoccupied so that it can be reused.
            elementCount--; // Decrease the element count to keep a consistent track of how many elements are in the program.
            return;
        }
    }
    throw runtime_error("Value not found."); // Throw an error if the value cannot be found in the hash table.
}

// Retrieve the value associated with a given key. Not really used here since I opted for getByValue instead. It'd be easier for and end user to remember the item than the key they're tied to anyways.
template <typename K, typename V>
V LinearProbingHashTable<K, V>::getByKey(const K& key) const
{
    // Find the position of the key.
    size_t index = findPosition(key);

    // Return the value if the key is found and the slot is occupied.
    if (occupied[index] && table[index].first == key)
    {
        return table[index].second;
    }
    throw runtime_error("Key not found."); // Throw an error if the value cannot be found in the hash table.
}

// Retrieve a key-value pair based on its value.
template <typename K, typename V>
pair<K, V> LinearProbingHashTable<K, V>::getByValue(const V& value) const
{
    for (size_t index = 0; index < tableSize; ++index)
    {
        // Find the matching value in the table.
        if (occupied[index] && table[index].second == value)
        {
            return table[index]; // Return the matching key-value pair.
        }
    }
    throw runtime_error("Value not found."); // Throw an error if the value cannot be found in the hash table.
}

// Retrieve all key-value pairs in the hash table, sorted by key.
template <typename K, typename V>
vector<pair<K, V>> LinearProbingHashTable<K, V>::getAll() const
{
    vector<pair<K, V>> allPairs;

    // Collect all occupied slots in the hash table.
    for (size_t index = 0; index < tableSize; ++index)
    {
        if (occupied[index])
        {
            allPairs.push_back(table[index]);
        }
    }

    // Sort by key
    sort(allPairs.begin(), allPairs.end(), [](const pair<K, V>& a, const pair<K, V>& b)
        {
            return a.first < b.first;
        });

    return allPairs;
}

// Resize the hash table to double its size and rehash all elements
template <typename K, typename V>
void LinearProbingHashTable<K, V>::resize()
{
    vector<pair<K, V>> oldTable = table; // Store the current table.
    vector<bool> oldOccupied = occupied; // Store the current occupied count.

    tableSize *= 2; // Double the table size so that more key-value pairs can be added.
    table.assign(tableSize, deletedMarker); // Reinitialize the table with empty slots so that it can be filled.
    occupied.assign(tableSize, false); // Reset the occupied markers.
    elementCount = 0; // Reset the element count.

    // Rehash all of the elements from the old table.
    for (size_t index = 0; index < oldTable.size(); ++index)
    {
        if (oldOccupied[index])
        {
            add(oldTable[index].first, oldTable[index].second);
        }
    }
}

// Explicit template instantiation for <int, string>
template class LinearProbingHashTable<int, string>;