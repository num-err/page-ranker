/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include "keywordSearcher.h"
#include <fstream>
#include <utility>
#include <string>
#include "hashTable.h"
#include <stdexcept>
#include "adts/stlMaxPriorityQueue.h"

using namespace std;

KeywordSearcher::KeywordSearcher() {
}

KeywordSearcher::~KeywordSearcher() {
    // TODO: KeywordSearcher::~KeywordSearcher
}

void KeywordSearcher::loadWords(string filename) {
    ifstream myFile;
    myFile.open(filename);
    string test = "";

    string pageString;
    int page = 0;
    while(!myFile.eof()){
        myFile >> test;

        if(test =="$$@@$$PAGE:"){
            myFile >> pageString;
            page = stoi(pageString);
        }
        else{
            //if word isn't there
            bool testingContains = this->table.contains(test);
            if(!(this->table.contains(test))){
                HashTable<int,int>* innerTable = new HashTable<int,int>();
                innerTable->insert(page,1);
                this->table.insert(test,innerTable);
            }
            else if(!(this->table.get(test)->contains(page))){ // if inner table has word but not page number
                
                   this->table.get(test)->insert(page,1);
            }
            else if((this->table.contains(test)) && (this->table.get(test)->contains(page))){ // inner table has word and page number so just need to update number of occurences at that page
                this->table.get(test)->update(page,this->table.get(test)->get(page) + 1);
            }

            
        }
    }

    myFile.close();
}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    
    vector<pair<int,int>> list;
     vector<pair<int,int>> listwo;
     vector<pair<int,int>> returnList;

    if(this->table.contains(word)){
        list = this->table.get(word)->getItems();
    } else
    {
        return list;
    }

    // swap
    for (int i = 0; i < list.size(); i++)
    {
        int temp = list[i].first;
        list[i].first = list[i].second;
        list[i].second = temp;
    }

    STLMaxPriorityQueue<int,int>* queue = new STLMaxPriorityQueue<int,int>(list); // occurence page
    

    int count = 0;

    for(int i = 0; i < list.size(); i++){
        int temp = queue->peekPriority();
            returnList.push_back(make_pair(queue->remove(), temp));
            count++;
            if(count == 10){
                break;
            }
    }

    return returnList;
}




