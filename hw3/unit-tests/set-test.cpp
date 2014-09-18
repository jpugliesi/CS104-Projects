#include <iostream>
#include <exception>
#include <stdexcept>
// Here we assume Set.h includes Map.h
#include "Set.h"

using namespace std;

int main()
{
  Set<double> setA;
  Set<double> setB;

  cout << "---------------------------------------------" << endl;
  cout << "| Now running unit tests for the Set class! |" << endl;
  cout << "---------------------------------------------" << endl;
  cout << endl;

  cout << "Set A is initially empty" << endl;
  cout << "Removing 0.0 from empty set A" << endl;
  setA.remove(0.0);

  cout << "Does set A contain 0.0? " << setA.contains(0.0) << endl;
  cout << "An empty set, set A, has size " << setA.size() << endl;

  cout << "Adding 0.0-9.0 to set A..." << endl;
  for (double i = 0.0; i < 10.0; ++i) {
    setA.add(i);
  }

  cout << "Set A of 10 elements has size " << setA.size() << endl;
  cout << "Does set A contain 10.0? " << setA.contains(10.0) << endl;

  setA.remove(0.0);
  setA.remove(1.0);
  setA.remove(2.0);

  cout << "After removing 3 elements from set A, sized 10, the set has size ";
  cout << setA.size() << endl;

  for (double i = 0.0; i < 10.0; ++i) {
    cout << "Does set A contain " << i << "? " << setA.contains(i) << endl;
  }

  cout << "Empty set B has size " << setB.size() << endl;

  setB.add(10.0);
  setB.add(11.0);
  setB.add(12.0);
  setB.add(13.0);

  cout << "Set B has size " << setB.size() << " after adding 4 items "<< endl;

  cout << "Merging set A and set B into set A" << endl;
  setA.merge(setB);

  cout << "Set A is now size " << setA.size() << endl;
  cout << "Set B is now size " << setB.size() << endl;

  for (double i = 0.0; i < 15.0; ++i) {
    cout << "Does set A contain " << i << "? " << setA.contains(i) << endl;
  }

  for (double i = 9.0; i < 15.0; ++i) {
    cout << "Does set B contain " << i << "? " << setB.contains(i) << endl;
  }

  return 0;
}
