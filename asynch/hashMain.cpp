// map::empty
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

//https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
using namespace std;

//constants


const int TABLE_SIZE = 128;

//constants end

class LinkedHashEntry {

private:

      int key;

      int value;

      LinkedHashEntry *next;

public:

      LinkedHashEntry(int key, int value) {

            this->key = key;

            this->value = value;

            this->next = NULL;

      }

 

      int getKey() {

            return key;

      }

 

      int getValue() {

            return value;

      }

 

      void setValue(int value) {

            this->value = value;

      }

 

      LinkedHashEntry *getNext() {

            return next;

      }

 

      void setNext(LinkedHashEntry *next) {

            this->next = next;

      }

};
 

class HashMap {

private:

      LinkedHashEntry **table;

public:

      HashMap() {

            table = new LinkedHashEntry*[TABLE_SIZE];

            for (int i = 0; i < TABLE_SIZE; i++)

                  table[i] = NULL;

      }

 

      int get(int key) {

            int hash = (key % TABLE_SIZE);

            if (table[hash] == NULL)

                  return -1;

            else {

                  LinkedHashEntry *entry = table[hash];

                  while (entry != NULL && entry->getKey() != key)

                        entry = entry->getNext();

                  if (entry == NULL)

                        return -1;

                  else

                        return entry->getValue();

            }

      }

 

      void put(int key, int value) {

            int hash = (key % TABLE_SIZE);

            if (table[hash] == NULL)

                  table[hash] = new LinkedHashEntry(key, value);

            else {

                  LinkedHashEntry *entry = table[hash];

                  while (entry->getNext() != NULL)

                        entry = entry->getNext();

                  if (entry->getKey() == key)

                        entry->setValue(value);

                  else
                        entry->setNext(new LinkedHashEntry(key, value));

            }

      }

 

      void remove(int key) {

            int hash = (key % TABLE_SIZE);

            if (table[hash] != NULL) {

                  LinkedHashEntry *prevEntry = NULL;

                  LinkedHashEntry *entry = table[hash];

                  while (entry->getNext() != NULL && entry->getKey() != key) {

                        prevEntry = entry;

                        entry = entry->getNext();

                  }

                  if (entry->getKey() == key) {

                        if (prevEntry == NULL) {

                             LinkedHashEntry *nextEntry = entry->getNext();

                             delete entry;

                             table[hash] = nextEntry;

                        } else {

                             LinkedHashEntry *next = entry->getNext();

                              delete entry;

                             prevEntry->setNext(next);

                        }

                  }

            }

      }

 

      ~HashMap() {

            for (int i = 0; i < TABLE_SIZE; i++)

                  if (table[i] != NULL) {

                        LinkedHashEntry *prevEntry = NULL;

                        LinkedHashEntry *entry = table[i];

                        while (entry != NULL) {

                             prevEntry = entry;

                             entry = entry->getNext();

                             delete prevEntry;

                        }

                  }

            delete[] table;

      }

};


/*
class userInput {
	private:
		int key1;
		int value1;
	
	public:
		hashE(int key1, int value1)	//hash entry
		{
			this->key1 = key1;
			this->value1 = value1;
		}
	
	int getKey1()
	{
		return key1;	
	}	
	
	int getValue1()
	{
		return value1;
	}
		
};

class hashMap1{
	
};

/*int hash(const char* str)
{
	int hash = 404;
	int c;
	
	while(*str != '\0')
	{
		hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
	}
	
	return hash % MAX_TABLE
}
*/

int main(int argc, char** argv) 
{
/*string three, four;
	unordered_map<string, string> hashTable;
	hashTable.emplace("one", "two");
	cout << "Enter two strings ";
	cin>>three, four;
	hashTable.emplace(three, four);
	cout << "one + one = " << hashTable["one"] <<endl;	
	cout << "test: " << hashTable[three]<<endl;*/

	HashMap.put(69,420);
	cout << HashMap.get(69) <<endl; 

	
	return 0;
}


