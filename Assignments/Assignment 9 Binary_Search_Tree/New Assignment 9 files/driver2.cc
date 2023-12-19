/********************************************************************************
 * More verbose driver program for 340 Assignment 9
 ********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>   // generate
//#include "bst.h"
#include "binarysearchtree.h"

const int default_seed = 1;
const int default_N = 50;
const int default_minx = 1;
const int default_maxx = 500;

const std::string found = "Leaf Found";
const std::string notfound = "Leaf Not Found";

const std::string removed = "Removed";
const std::string notremoved = "Not Removed";

template <typename T>
BinarySearchTree <T> *global_tree = nullptr; // not mt-safe, but I don't care for this

template <typename CONTAINER>
void print_container(CONTAINER c) {
  bool first = true;
  std::cout << "[ "; 
  for(auto i = c.begin(); i != c.end(); ++i) {
    if(!first) std::cout << ", ";
    else first = false;
    std::cout << *i; 
  }
  std::cout << " ]"; }

// Just print the value, space separated
template <typename T> 
void print_val(const T &x) { std::cout << x << " "; }

// Print the value, and add a star after it if the value exists as a node in *global_tree<T>
template <typename T> 
void print_val_aware(const T &x) { std::cout << x << (( global_tree<T> && global_tree<T>->Search(x) ) ? "*" : "") << " "; }

template <typename T>
void print_tree_status(BinarySearchTree <T> & tree) {  // would make this param const, but requirements of initial program did not force a const implementation of Inorder
  std::cout << "    Size: " << tree.getSize() << " ; Height: " << tree.getHeight() << "\n"; 
  std::cout << "    Inorder: ";
  tree.Inorder(print_val_aware<int>);
  std::cout << "\n\n";
}

void print_label(std::string label) {
  std::cout << "    " << label << "\n    ";
  int n = label.size(); 
  for(int i=0; i<n; ++i) std::cout << "-";
  std::cout << "\n";
}
  
int main(int argc, char *argv[]) {
  // start off with default values for potentially externally-supplied items
  int seed = default_seed;
  int N = default_N;
  int minx = default_minx;
  int maxx = default_maxx;

  // check command line arguments
  // argv[1] <-- changes number of elements, if present
  // argv[2] <-- changes random number seed, if present
  // argv[3] <-- changes random number minimum, if present
  // argv[4] <-- changes random number maximum, if present
  if(argc > 1) N    = atoi(argv[1]); 
  if(argc > 2) seed = atoi(argv[2]);
  if(argc > 3) minx = atoi(argv[3]);
  if(argc > 4) maxx = atoi(argv[4]);

  std::cout << "Testing with " << N << " elements between " << minx << " and " << maxx << " and using " << seed << " as the random seed.\n"; 

  srand(seed); // initialize random number generator with supplied seed
  

  BinarySearchTree <int> tree;
  global_tree<int> = &tree; // allow the print_val_aware function access to this tree in order to mark leaf nodes 
                       //
  std::vector <int> v(N); 

  // fill a vector with elements to insert 
  if(seed != -1) { // if seed not -1, use random numbers
    generate(v.begin(), v.end(), [minx,maxx] () { return rand()%(maxx-minx+1) + minx; });
  }
  else { // if seed == -1, use sequence instead 
    int val=0; 
    generate(v.begin(), v.end(), [&val, minx,maxx] () { return (val++) % (maxx-minx+1) + minx; } );
  }
  std::cout << "Generated: ";
  print_container(v); 
  std::cout << std::endl;
  
  int n = v.size();
  int step_width = std::to_string(n).size(); // find out how many digits maximum value is 
  int val_width = std::to_string(maxx).size(); // find out how many digits maximum value is 

  // insert all of the numbers into the BinaryTree
  std::cout << "Inserting generated numbers into tree in order:\n";
  for(auto x: v) {
    tree.Insert(x); 
  }

  // print out inorder, preorder, postorder to test tree insertion
  print_label("After inserting all");
  print_tree_status(tree); 

  //std::cout << "  Preorder: ";
  //tree.Preorder(print_val<int>);
  //std::cout << "  Postorder: ";
  //tree.Postorder(print_val<int>);
  

  int remaining = tree.getSize(); // find out how many we have
  int pass = 1;

  while(remaining > 0) {   
    std::cout << "Starting pass " << pass << "\n";
    for(int i=0; i<n; ++i ) {
      bool did_it = false; // did we change the tree? 
      std::cout << "  S/R Step " << std::setw(step_width) << i
        << ": val(" << std::setw(val_width) << v[i] << ") - "
        << (tree.Search(v[i]) ? found : notfound ) << " - "
        << ((did_it = tree.Remove(v[i])) ? removed : notremoved) << "\n";

      if(did_it) {
        --remaining;
        if(remaining > 0) {
          print_label("Tree after removing " + std::to_string(v[i]) + " for step " + std::to_string(i)); 
          print_tree_status(tree); 
        }
        else { 
          std::cout << "  Last remaining node removed, ending loop.\n";
          break; // we don't have anything left
        }
      }

    }

    std::cout << "  All removal attempts finished for pass " << pass << "\n";
    print_label("Tree after removal pass " + std::to_string(pass));
    print_tree_status(tree); 
    ++pass; // increase pass number
  }
  
  std::cout << "Nothing remains to be removed. Finished.\n";

}
