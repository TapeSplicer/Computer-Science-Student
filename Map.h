#ifndef MAP_H_
#define MAP_H_
#include "Map_Set.h"
#include "Pair.h"
using namespace std;

template <typename K, typename V>
class Map
{
    public:
        Map() {}

        V& operator [] (K index)
        {
            typename Set<Pair<K,V>>::iterator here;
            Pair<K,V> probe(index, V());
            here = theMap.insert(probe);
            return (*here).second;
        }

        void remove(K key)
        {
            Pair<K,V> probe;
            probe.first = key;
            theMap.remove(probe);
            return;
        }

        //return set of all keys of Set
        Set<K> keys()
        {
            Set<K> theKeys;
            typename Set<Pair<K,V>>::iterator itr = theMap.begin();
            for (; itr != theMap.end(); itr++)
                theKeys.insert((*itr).first);
            return theKeys;
        }

        //return set of all values of Set
        Set<V> values()
        {
            Set<V> theValues;
            typename Set<Pair<K,V>>::iterator itr = theMap.begin();
            for (; itr != theMap.end(); itr++)
                theValues.insert((*itr).second);
            return theValues;
        }

    private:
        Set<Pair<K,V>> theMap;
};
#endif