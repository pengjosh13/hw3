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
  unsigned aryThing;
  size_t saize = 0;
  std::vector<T> thisHeap;
	PComparator pcomp;
	void trickleUp(unsigned upIndex);
	void trickleDown(unsigned downIndex);
	bool leaf(unsigned leafIndex);


};

// Add implementation of member functions here

template <typename T, typename PComparator>
bool Heap<T, PComparator>::leaf(unsigned leafIndex){
	if (((aryThing * leafIndex) + 1) >= saize){
		return true;
	}
	return false;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(unsigned upIndex){
  unsigned parentIndex;
  if (upIndex == 0){
    parentIndex = 0;
  }else{
    parentIndex = (upIndex - 1) / aryThing;
  }
	while (parentIndex >= 0 && pcomp(thisHeap[upIndex], thisHeap[parentIndex])){
		std::swap(thisHeap[parentIndex], thisHeap[upIndex]);
		upIndex = parentIndex;
		parentIndex = (upIndex - 1) / aryThing;
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(unsigned downIndex){
	if (leaf(downIndex)){
		return;
	}

	unsigned smol = aryThing * downIndex + 1;
  unsigned rrr = smol;
  while (rrr < thisHeap.size() - 1 && rrr < (aryThing * downIndex + aryThing)){
    rrr++;
    if (pcomp(thisHeap[rrr], thisHeap[smol])){
      smol = rrr;
    }
  }

	if(pcomp(thisHeap[smol], thisHeap[downIndex])){
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
  saize++;
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

  return thisHeap[0];
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
  thisHeap[0] = thisHeap[saize - 1];
  thisHeap.pop_back();
  saize--;
  trickleDown(0);




}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	if (thisHeap.empty()){
		return true;
	}else{
		return false;
	}
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
	return thisHeap.size();

}



#endif

