# PageRanker

A high-performance document indexing and keyword search engine built in C++, featuring custom hash table implementations, relevance ranking, and PDF text processing.

## Overview

PageRanker is a lightweight information retrieval system designed to efficiently index large collections of documents and return ranked search results based on keyword relevance.

Unlike search systems that rely heavily on external libraries, PageRanker implements core data structures from scratch, including custom hash tables, dictionaries, and indexing mechanisms, providing full control over performance characteristics and memory usage.

The project demonstrates the complete search pipeline—from document ingestion and text extraction to indexing, ranking, and retrieval.

---

## Features

### Document Indexing

* Fast document parsing
* Inverted index generation
* Keyword frequency tracking
* Efficient storage structures

### Search Engine

* Keyword-based document retrieval
* Relevance scoring
* Ranked search results
* Multi-document indexing

### Custom Data Structures

* Hash table implementation
* Dictionary abstraction layer
* Collision handling strategies
* Optimized lookup performance

### PDF Processing

* Automated PDF-to-text conversion
* Searchable content extraction
* Document preprocessing pipeline

### Testing Framework

* Unit testing suite
* Manual testing utilities
* Validation datasets

---

## Architecture

```text
Documents / PDFs
        │
        ▼
Text Extraction
        │
        ▼
Tokenization
        │
        ▼
Keyword Indexing
        │
        ▼
Custom Hash Tables
        │
        ▼
Inverted Index
        │
        ▼
Ranking Engine
        │
        ▼
Search Results
```

---

## Core Components

### Hash Table

Custom implementation providing:

* Constant-time average lookups
* Efficient insertions
* Collision resolution
* Dynamic storage management

Files:

```text
hashTable.h
hashTable-inl.h
hashFunctions.cpp
hashFunctions.h
```

---

### Dictionary Layer

Abstraction built on top of the hash table implementation.

Files:

```text
linearDictionary.h
linearDictionary-inl.h
```

---

### Keyword Search Engine

Responsible for:

* Query processing
* Keyword matching
* Relevance calculation
* Ranked result generation

Files:

```text
keywordSearcher.cpp
keywordSearcher.h
```

---

### PDF Processing

Converts PDF documents into searchable text.

Files:

```text
textifyPDF.py
```

---

## Project Structure

```text
.
├── hashTable.h
├── hashTable-inl.h
├── hashFunctions.h
├── hashFunctions.cpp
├── keywordSearcher.h
├── keywordSearcher.cpp
├── linearDictionary.h
├── linearDictionary-inl.h
├── main.cpp
├── tests.cpp
├── manualTests.cpp
├── textifyPDF.py
├── test_data/
└── Makefile
```

---

## Building the Project

### Requirements

* C++17 or newer
* GNU Make

### Compile

```bash
make
```

### Run

```bash
./page-ranker
```

---

## Example Usage

```text
Search Query:
machine learning

Results:

1. Introduction_to_AI.pdf
   Relevance Score: 0.92

2. Neural_Networks.pdf
   Relevance Score: 0.87

3. Data_Science_Guide.pdf
   Relevance Score: 0.79
```

---

## Performance Goals

The system is designed to provide:

* Fast keyword lookups
* Low memory overhead
* Efficient indexing
* Scalable document retrieval

Custom-built data structures allow fine-grained optimization compared to generic container implementations.

---

## Future Improvements

* TF-IDF ranking
* BM25 retrieval
* Phrase search
* Boolean queries
* Fuzzy matching
* Incremental indexing
* Web-based search interface
* Parallel document indexing
* Distributed search architecture

---

## Technical Highlights

* Custom hash table implementation
* Inverted indexing architecture
* Relevance-based ranking
* Efficient keyword retrieval
* PDF text extraction pipeline
* Modular search engine design

---

## License

MIT License

---

## Author

Numer Ahmed

Software Engineer | Systems Programming | Information Retrieval | Search Infrastructure
