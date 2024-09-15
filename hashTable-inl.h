/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->maxLoadFactor = 0.75;
    this->capacity = 10;
    this->loadFactor = this->size/this->capacity;

    
    LinearDictionary<K,V>* dList = new LinearDictionary<K,V>[capacity];
    this->list = dList;
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->maxLoadFactor = maxLoadFactor;
    this->capacity = 10;
    LinearDictionary<K,V>* dList = new LinearDictionary<K,V>[capacity];
    this->list = dList;
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    //delete this->list;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return this->list->isEmpty();
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key,this->capacity);
   
    this->list[index].insert(key,value);
    
    this->size++;
    
    if(this->loadFactor > this->maxLoadFactor){
        expand();
        this->loadFactor = this->size/this->capacity;

    }
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key,capacity);
    return list[index].update(key,value);
    this->loadFactor = this->size/this->capacity;

};


template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key,capacity);
    return list[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
   int index = hash(key,capacity);
    return list[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int index = hash(key,capacity);
    list[index].remove(key);
    this->loadFactor = this->size/this->capacity;

    size--;
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    
   vector<K> target2 = vector<K>();
    for(int i =0; i< capacity; i++){
        vector<K> currentKey = list[i].getKeys();
        target2.insert(target2.end(), currentKey.begin(), currentKey.end());
            

    }
    return target2;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
     vector<pair<K,V>> target2 = vector<pair<K,V>>();
    for(int i =0; i< capacity; i++){
        vector<pair<K,V>> currentKey = list[i].getItems();
        target2.insert(target2.end(), currentKey.begin(), currentKey.end());
            

    }
    return target2;;
}

template <typename K, typename V>
void HashTable<K, V>::expand() {
    int newCapacity = this->capacity * 2;
    this->loadFactor = this->size/this->capacity;

    LinearDictionary<K,V>* newList = new LinearDictionary<K,V>[newCapacity];
    vector<pair<K,V>> oldItems = this->list->getItems();
    int newIndex = 0;
    for(int i = 0; i < oldItems.size(); i++){
        newIndex = hash(oldItems[i].first,newCapacity);
        newList[newIndex].insert(oldItems[i].first,oldItems[i].second);
    }

    delete this->list;
    this->list = newList;    

}

// TODO: put any other definitions here