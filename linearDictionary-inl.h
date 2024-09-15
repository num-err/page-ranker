/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <stdexcept>

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {

    
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {

}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return v.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    if(v.size() > 0){
        return true;
    }
    return false;
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    for(int i=0 ; i< v.size();i++){
        if(v[i].first == key){
            throw std::runtime_error("key is a duplicate");
        }
    
    }
        pair<K,V> newp = pair<K,V>(key,value);
        v.push_back(newp);
        
    
    }




template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    for(int i=0 ; i< v.size();i++){
    if(v[i].first == key){
        v[i].second = value;
        return;
    }

    
    

    }
    throw std::runtime_error("key is a duplicate");

}
    


template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for(int i=0 ; i< v.size();i++){
        if(v[i].first ==key){
            return v[i].second;
        }
    }
    
    throw std::runtime_error("no keys to return");
}
    

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for(int i=0 ; i< v.size();i++){
        if(v[i].first ==key){
            return true;
        }
    }
    
    return false;
}
    


template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {

   if(v.size() == 0){
            throw std::runtime_error(
            "nothing to remove");
        }
        for(int i =0; i< v.size(); i++){
            if(v[i].first==key){

        v.erase(v.begin() + i, v.begin() + i + 1);
        }
    
    }
    
   
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> target = vector<K>();
    for(int i =0; i< v.size(); i++){
            target.push_back(v[i].first);
            

    }
    return target;
    

}
    

template <typename K, typename V> vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    return this->v;
    
}
