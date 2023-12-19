/*  Jacob Kurbis (Z1945650)
    CSCI 340: Data Structures Section: 0003
    Assignment 10	  Due: 04/12/2023
	
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/


#include "htable.h"
#include <iomanip>

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...


/**
 * @brief: The constructor for the HT class
 *
 * @param hs: The size of the hash table
 *
 */
HT::HT(const unsigned &hs) 
{
  hsize = hs;//sets the size of the hash table
  hTable.resize(hsize);//resizes the hash table vector
}


/**
 * @brief: The destructor for the HT class
 *
 */
HT::~HT() 
{
  for(auto it = hTable.begin(); it != hTable.end(); ++it)
  {
    it->clear();//frees the memory for all list containers
  }

  hTable.clear();//clears the vector for the hash table
  pTable.clear();//clears the vector for the pointer table

}


/**
 * @brief: Inserts an entry into the hash table
 *
 * @param e: The entry to be inserted
 *
 */
void HT::insert(const Entry &e) 
{
  int i = hash(e.key);//gets the hash value for the key
  list<Entry> &l = hTable[i];//gets the list at the hash value

  auto it = find_if(l.cbegin(), l.cend(), [&](const Entry &entry) {return entry.key == e.key;});//finds the entry in the list
  
  if(it != l.end())//if the entry is found
  {
    std::cout << " not inserted - duplicate key!!!" << std::endl;//prints the error message
    return;
  }

  l.push_front(e);//inserts the entry into the list
  pTable.push_back(&l.front());//inserts the pointer to the entry into the pointer table
  std::cout << " entry =  " << i << std::endl;//prints the subscript of the entry
  
}


/**
 * @brief: Searches for an entry in the hash table
 *
 * @param key: The key of the entry to be searched for
 *
 */
void HT::search(const string &key) 
{
  int i = hash(key);//gets the hash value for the key
  list<Entry> &l = hTable[i];//gets the list at the hash value

  auto it = find_if(l.begin(), l.end(), [&](const Entry &entry) {return entry.key == key;});//finds the entry in the list

  if(it == l.end())//if the entry is not found
  {
    std::cout << " not in table!!" << std::endl;//prints the error message
    return;
  }
  
  //prints the entry, key, number, and description
  std::cout << std::fixed << std::left  << " ==> number: " 
            << std::fixed << std::right << setw(4) << it->num 
            << " - item:" << std::left << setw(24) << it->desc << std::endl; 

}


/**
 * @brief: Prints the subscript and the contents of all (and only) the active records in the hash table.
 *
 */
void HT::hTable_print() 
{
  std::cout << std::endl;
  for(unsigned i = 0; i < hTable.size(); ++i)//loops through the hash table
  {
    for(auto it = hTable[i].begin(); it != hTable[i].end(); ++it)//loops through the list at the hash value
    {
      //prints the subscript, key, number, and description
      std::cout << std::fixed << std::left << std::setw(4) << i 
                << ":" << it->key << "    - " << std::fixed << setw(7) 
                << it->num << "-  " << setw(24) << it->desc << std::endl;
    }
  }
}


/**
 * @brief: Sorts and prints the contents of all (and only) the active records in the hash table.
 *
 */
void HT::pTable_print() 
{
  sort(pTable.begin(), pTable.end(), [](Entry *p, Entry *q) {return p->key < q->key;});//sorts the pointer table

  for(auto it = pTable.begin(); it != pTable.end(); ++it)//loops through the pointer table
  {
    //prints the key, number, and description
    std::cout << std::fixed << std::left << setw(3) 
              << " " << (*it)->key << "  -  " << std::fixed 
              << std::right << setw(4) << (*it)->num << "  -  " 
              << std::left << setw(24) << (*it)->desc << std::endl;
  }
}