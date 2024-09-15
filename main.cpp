/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <iostream>
#include <string>
#include <vector>

#include "keywordSearcher.h"

using namespace std;

int main(int argc, char** argv) {


    if(argc != 2){
      throw runtime_error("Incorrect amount of arguments");
    }

    try {

      string word = "initialized";
      KeywordSearcher searcher;
      searcher.loadWords(argv[1]);
      cout << "file loaded" << endl;
      while(word != "!"){
      
      cout << "Please enter a search word or '!' to quit: "; 
      cin >> word;
      if(word == "!"){
        cout << "Goodbye!" << endl;
        return 0;
      }
      vector<pair<int,int>> r = searcher.search(word);

      if(r.size() == 0){
        cout << word << " does not appear in the file" << endl;
        continue;
      }

      for(int i = 0; i < r.size();i++ ){
        cout << "page " << r[i].first << " (" << r[i].second << " occurrences" << ")"  << endl;
      }
        
      }
      

  } catch (runtime_error e) {
      throw runtime_error("Error");
  }
}
