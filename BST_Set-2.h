// BST_Set_New.h
// by KV, Spring 2022, for CSE 2020;
// with additions to to copy constructor to properly handle parent pointers
// essentially class BinarySearchTree with iterators


#ifndef BSTSET_H
#define BSTSET_H

#include <algorithm>
#include <cassert>
using namespace std;       


template <typename T>
class Set
{
private:

    class  BinaryNode
	{
	public:
		T element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode* parent; // added to support iterators

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt), parent(nullptr) {}

		BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt,
			BinaryNode* par)
			: element(theElement), left(lt), right(rt), parent(par) { }

	};

public:

	class const_iterator
	{
	public:
		const_iterator() : current{ nullptr }
		{}

		const_iterator(BinaryNode* x) : current(x)
		{}

        const_iterator(const const_iterator& rhs)
            : current(rhs.current)
        {}

        const_iterator& operator =(const const_iterator& rhs)
        {
            current = rhs.current;
            return *this;
        }

		T operator *() const 
		{
			return current->element;
		}

		const_iterator& operator ++()
		{
			go_to_next();
			return *this;
		}

		const_iterator operator ++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator ==(const const_iterator& rhs) const
		{
			return current == rhs.current;
		}

		bool operator !=(const const_iterator& rhs) const
		{
			return !(*this == rhs);
		}

	protected:

		BinaryNode* current;

		void go_to_next()
		{
			if (current == nullptr)
				return;

			T currval = current->element;
			if (current->right == nullptr)
			{
				// current node has no right subtree
				// go to closest larger valued ancester
				current = current->parent;
				while (current != nullptr && current->element < currval)
					current = current->parent;
				return;
			}
			// current node has right subtree
			// go leftmost in that subtree
			current = current->right;
			while (current->left != nullptr)
				current = current->left;
			return;
		}

		friend class Set<T>;
	}; // end class iterator
 
 public:
	 
    Set( ) : root(nullptr) {}

    Set( const Set & rhs ) : root( nullptr )
    {
        /* This is old and has some issues ... 
        root = clone( rhs.root );
		// New, KV: after "fowards" cloning, establish he parent pointers
		reparent(root);  // defined under private: 
        */

        // this works:
        if (rhs.root != nullptr)
        {
            root = new BinaryNode(rhs.root->element, nullptr, nullptr, nullptr);
            root->left = clone1(rhs.root->left, root);
            root->right = clone1(rhs.root->right, root);
        }
    }
    
    ~Set( )
    {
        makeEmpty( );
    }

    Set & operator=( const Set & rhs )
    {
        /* old with some issues ...
        Set copy(rhs);
        std::swap( *this, copy );
	    //reparent(this->root); //NEW
        */

        // this works: 

        root = nullptr;
        if (rhs.root != nullptr)
        {
            root = new BinaryNode(rhs.root->element, nullptr, nullptr, nullptr);
            root->left = clone1(rhs.root->left, root);
            root->right = clone1(rhs.root->right, root);
        }

        return *this;
    }

    const T & findMin( ) const
    {
		assert(!isEmpty());
        return findMin( root )->element;
    }

    const T & findMax( ) const
    {
		assert(!isEmpty());
        return findMax( root )->element;
    }

    bool contains( const T & x ) const
    {
        return contains( x, root );
    }

    bool isEmpty( ) const
    {
        return root == nullptr;
    }

  void printSet() const // ostream & out = cout ) const
    {
        if( isEmpty( ) )
            cout << "Empty Set" << endl;
        else
            printSet( root);
    }

	void printInternal() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printInternal(root, 0);
	}
	
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    
    void insert( const T & x )
	{
	    insert( x, root, root);
    }
    
    void remove( const T & x )
    {
        remove( x, root );
    }

	// BST iterators

	const_iterator begin() const
	{
		BinaryNode* beg = leftmost(root);
		const_iterator itr(beg);
        return itr;
	}

	const_iterator end() const
	{
		const_iterator itr(nullptr);
		return itr;
	}


  int cardinality() const
  {
    return cardinality(root);
  }

  // union, intersect, and difference member fcts;

  Set<T> set_union(const Set& rhs)
  {
      Set<T> set3(*this);
      typename Set<T>::const_iterator itr = rhs.begin();
      for (; itr != rhs.end(); itr++)
          set3.insert(*itr);
      return set3;
  }

  Set<T> set_intersection(const Set& rhs)
  {
      Set<T> set3;
      typename Set<T>::const_iterator itr;
      for (itr = begin(); itr != end(); itr++)
          if (rhs.contains(*itr))
              set3.insert(*itr);

      return set3;
  }

  Set<T> set_difference(const Set& rhs)
  {
      Set<T> set3;
      typename Set<T>::const_iterator itr;

      for (itr = begin(); itr != end(); ++itr)
          if (!rhs.contains(*itr))
              set3.insert(*itr);

      return set3;
  }
  


  private:
    
    BinaryNode *root;

	
    void insert( const T & x, BinaryNode * & t, BinaryNode * & par)
    {
	   if( t == nullptr )
		{
            t = new BinaryNode( x, nullptr, nullptr, par );
		}
        else if( x < t->element )
            insert( x, t->left, t );
        else if( t->element < x )
            insert( x, t->right, t );
        else
            ;  // Duplicate; do nothing
    }
 
    void remove( const T & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            //t = ( t->left != nullptr ) ? t->left : t->right;
			if (t->left != nullptr)
			{
				t->left->parent = t->parent;
				t = t->left;
			}
			else
			{
				if (t->right != nullptr)
					t->right->parent = t->parent;
				t = t->right;
			}
            delete oldNode;
        }
    }

    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }

    bool contains( const T & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }

    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    void printSet( BinaryNode *t) const
    {
        if( t != nullptr )
        {
            printSet( t->left);
            cout << t->element << " "; //endl;
            printSet( t->right);
        }
    }

	void printInternal(BinaryNode *t, int offset) const
	{
		for (int i = 1; i <= offset; i++)
			cout << "..";
		if (t == nullptr)
		{
			cout << "#" << endl;
			return;
		}
		cout << t->element << endl;
		printInternal(t->left, offset + 1);
		printInternal(t->right, offset + 1);
		return;
	}

    // old ... some hard to trace issues .. 
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
        {
            BinaryNode* leftclone = clone(t->left);
            BinaryNode* rightclone = clone(t->right);
            return  new BinaryNode{ t->element, leftclone, rightclone, nullptr};
        }
    }

    // new clone function that works:
    BinaryNode* clone1(BinaryNode* toclone, BinaryNode* parent)
    {
        if (toclone == nullptr)
            return nullptr;

        BinaryNode* cl = new BinaryNode(toclone->element, nullptr, nullptr, parent);
        cl->left = clone1(toclone->left, cl);
        cl->right = clone1(toclone->right, cl);
        return cl;
    }

	// added for iterator implementation;

	BinaryNode* leftmost(BinaryNode* t) const
	{
	  if (t != nullptr)
	    while (t->left != nullptr)
	      t = t->left;
	  return t;
	}

  int cardinality (BinaryNode* t) const
  {
    if (t == nullptr)
      return 0;
    if (t->left == nullptr and t->right == nullptr)
      return 1;
    return 1 + cardinality(t->left) + cardinality(t->right);
  }

  // establish all parent pointers in
    // BST rooted in t
    // no longer needed with clone1() is used 
  void reparent(BinaryNode* t)
  {
      if (t == nullptr)
          return;
      if (t->left == nullptr && t->right == nullptr)
          return;
      if (t->left != nullptr)
      {
          t->left->parent = t;
          reparent(t->left);
      }
      if (t->right != nullptr)
      {
          t->right->parent = t;
          reparent(t->right);
      }
  }

};

#endif
