#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int aryThing;
  size_t saize = 0;
  std::vector<T> thisHeap;
	PComparator pcomp;
	void trickleUp(int upIndex);
	void trickleDown(int downIndex);
	bool leaf(int leafIndex);


};

// Add implementation of member functions here

template <typename T, typename PComparator>
bool Heap<T, PComparator>::leaf(int leafIndex){
	if (((aryThing * leafIndex) + 1) >= thisHeap.size()){
		return true;
	}
	return false;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int upIndex){
	int parent = upIndex / aryThing;
	while (upIndex >= 1 && thisHeap[upIndex] < thisHeap[parent]){
		std::swap(thisHeap[parent], thisHeap[upIndex]);
		upIndex = parent;
		parent = upIndex / aryThing;
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int downIndex){
	if (leaf(downIndex)){
		return;
	}

	int smol = aryThing * downIndex;
	if((aryThing * downIndex) + 1){
		int rrr = smol + 1;
		if (thisHeap[rrr] < thisHeap[smol]){
			smol = rrr;
		}
	}
	if(thisHeap[downIndex] > thisHeap[smol]){
		std::swap(thisHeap[downIndex], thisHeap[smol]);
		trickleDown(smol);
	}
}







template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): aryThing(m), pcomp(c){

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
	thisHeap.push_back(item);
	trickleUp(thisHeap.size() - 1);

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw(std::out_of_range("Empty"));
    // ================================
    // throw the appropriate exception
    // ================================


  }

  return thisHeap[1];
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw (std::out_of_range("Empty"));
    // ================================
    // throw the appropriate exception
    // ================================


  }

  thisHeap[1] = thisHeap.back();
  thisHeap.pop_back();
  trickleDown(1);





}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	if (saize == 0){
		return true;
	}else{
		return false;
	}
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
	return saize;

}



#endif

