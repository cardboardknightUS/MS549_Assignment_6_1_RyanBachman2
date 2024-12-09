/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 6.1 - Project - Key Table
	hashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <utility> // For pair
#include <stdexcept> // For exceptions
#include <functional> // For hash

// Allows you to use iostream statements without the use of .
using namespace std;

template <typename K, typename V>
class HashTable {
public:
    HashTable(size_t size = 101); // Constructor with default size.
    void add(const K& key, const V& value); // Add key-value pair.
    void remove(const V& value); // Remove key-value pair by value.
    pair<K, V> getByValue(const V& value) const; // Get key by value.
    vector<pair<K, V>> getAll() const; // Get all key-value pairs.

private:
    size_t hashFunction(const K& key) const; // Hash function.
    vector<list<pair<K, V>>> table; // The hash table.
    size_t tableSize; // Size of the table.
};
#endif // HASHTABLE_H