/*
    Ryan Bachman
    University of Advancing Technology
    MS549 - Data Structures and Testing
    Fall 2024, Grad 2

    Assignment 6.1 - Project - Key Table
    linearProbing.h
*/

#ifndef LINEARPROBING_H
#define LINEARPROBING_H

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
class LinearProbingHashTable {
public:
    LinearProbingHashTable(size_t size = 101); // Constructor with default size
    void add(const K& key, const V& value); // Add key-value pair
    void remove(const V& value); // Remove key-value pair by value
    V getByKey(const K& key) const; // Get value by key
    pair<K, V> getByValue(const V& value) const; // Get key-value pair by value
    vector<pair<K, V>> getAll() const; // Get all key-value pairs

private:
    size_t hashFunction(const K& key) const; // Hash function
    size_t findPosition(const K& key) const; // Find position for a key
    void resize(); // Resize the hash table when it becomes too full

    vector<pair<K, V>> table; // Hash table with optional elements
    vector<bool> occupied; // Tracks occupied slots
    size_t tableSize; // Size of the hash table
    size_t elementCount; // Number of elements in the table
    const double loadFactor = 0.7; // Max load factor before resizing
    const pair<K, V> deletedMarker = { K(), V() }; // Marker for deleted slots
};
#endif // LINEARPROBING_H