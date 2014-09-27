#ifndef __MAP_H__
#define __MAP_H__

template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (keyType key, valueType value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (keyType key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    valueType get (keyType key, bool & success) const;
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

	void printAll () const;

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;
	 int m_size = 0;

     /* If you like, you can add further data fields and private
        helper methods. */
};

/**one method of implementing is to do it all in one file.  Or, you could 
easily just include a .cpp or .cxx file at the bottom with the implementation, if you prefer.  But that
is stylistically discouraged because you should generall never #include source files.  I've named it
.cxx to avoid that confusion.
Either way is fine. **/

#include "../src/MapImpl.cxx"

#endif