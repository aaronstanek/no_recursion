#ifndef __NO_RECURSION_INCLUDED__
#define __NO_RECURSION_INCLUDED__

using namespace std;

template <class T> class no_recursion_element {
  public:
    no_recursion_element * prev;
    T data;
};

template <class T> class no_recursion_root {
  private:
    no_recursion_element<T> * poi;
    unsigned long depth;
  public:
    no_recursion_root();
    unsigned long get_depth();
    T * active();
    T * prev();
    T * push();
    void pop();
    ~no_recursion_root();
};

// template functions

template <class T> no_recursion_root<T>::no_recursion_root() {
  poi = new no_recursion_element<T>;
  depth = 1;
}

template <class T> unsigned long no_recursion_root<T>::get_depth() {
  return depth;
}

template <class T> T * no_recursion_root<T>::active() {
  return &(poi->data);
}

template <class T> T * no_recursion_root<T>::prev() {
  return &(poi->prev->data);
}

template <class T> T * no_recursion_root<T>::push() {
  no_recursion_element<T> * mi = new no_recursion_element<T>;
  (mi->prev) = poi;
  poi = mi;
  depth += 1;
  return &(poi->data);
}

template <class T> void no_recursion_root<T>::pop() {
  no_recursion_element<T> * mi = poi->prev;
  delete poi;
  poi = mi;
  depth -= 1;
}

template <class T> no_recursion_root<T>::~no_recursion_root() {
  while (depth!=0) {
    pop();
  }
}

#endif
