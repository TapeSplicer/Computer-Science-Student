// Pair.h
// KV, Fall 2020 for class Map
#ifndef PAIR_H_
#define PAIR_H_
using namespace std;

template <typename K, typename V>
class Pair
{
 public:
  Pair() {}

  Pair(K thekey): first(thekey) {}

  Pair(K thekey, V theval): first(thekey), second(theval) {}

  Pair(const Pair& rhs): first(rhs.first), second(rhs.second) {}

  // NEW for Map 2022
  Pair& operator =(const Pair<K, V>& rhs) 
  {
      first = rhs.first;
      second = rhs.second;
      return *this;
  }

  bool operator == (const Pair<K,V>& rhs) const
  {
    return  first == rhs.first;
  }

  bool operator != (const Pair<K,V>& rhs) const
  {
    return first != rhs.first;
  }
  
  bool operator < (const Pair<K,V>& rhs) const
  {
    return first < rhs.first;
  }
  
  bool operator > (const Pair<K,V>& rhs) const
  {
    return first > rhs.first;
  }

  K key() { return first; }

  V& value() { return second; }
 
  K first;
  V second;
};
#endif