#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;


template <typename T>
class Vector {

 private:

  size_t sz;
  T* buf;  

 public:

  Vector(size_t sz) : sz(sz), buf(new T[sz]) {}

  Vector(initializer_list<T> L) : sz(L.size()), buf(new T[L.size()]) {
    size_t i = 0;
    for (auto &x : L) {
        buf[i++] = x;
    }
  }

  ~Vector() {
    // delete[] buf;
  }

  Vector(const Vector & v) : sz(v.sz), buf(new T[v.sz]) {
    for (size_t i = 0; i < sz; ++i) {
        buf[i] = v.buf[i];
    }
  }

  size_t size() const {
    return sz;
  }

  T & operator [] (const int i) {
    if (i < 0 || i >= sz) throw out_of_range("Index out of bounds.");
    return buf[i];
  }

  T operator [] (const int i) const {
    if (i < 0 || i >= sz) throw out_of_range("Index out of bounds.");
    return buf[i];
  }

  T operator * (const Vector & v) const {
    T dot_product = 0;

    for (size_t i = 0; i < sz; i++) {
      T num1 = (i < sz) ? buf[i] : 0;
      T num2 = (i < v.size()) ? v[i] : 0;
      dot_product += (num1 * num2);
    }
    return dot_product;
  }

  Vector operator + (const Vector & v) const {
    size_t new_size = max(sz, v.size());
    Vector<T> v3(new_size);

    for (size_t i = 0; i < new_size; i++) {
      T num1 = (i < sz) ? buf[i] : 0;
      T num2 = (i < v.size()) ? v[i] : 0;
      v3[i] = num1 + num2;
    }
    return v3;
  }

  const Vector & operator = (const Vector & v) {
    delete[] buf;
    sz = v.size();
    buf = new T[sz];

    for (size_t i = 0; i < sz; i++) {
      buf[i] = v[i];
    }
    return *this;
  }

  bool operator == (const Vector & v) const {
    if (sz != v.size()) return false;
    for (size_t i = 0; i < sz; i++) {
      if (buf[i] != v[i]) return false;
    }
    return true;
  }

  bool operator != (const Vector & v) const {
    if (sz != v.size()) return true;
    for (size_t i = 0; i < sz; i++) {
      if (buf[i] != v[i]) return true;
    }
    return false;
  }


  /**

   * Multiplies each element in current vector with the passed integer and returns a new vector.

   * ex: V1 = 20 * V2; it is important that 20 is on the left!

   * 20 * [1, 2, 3] = [20, 40, 60]

   * @param scale integer to multiple each element of vector v

   * @param v Vector on the right to perform multiplication on

   * @return new vector where index i is the result of v[i] * scale

  */

  inline friend Vector operator * (const int scale, const Vector & v) {
    Vector<T> mult(v.size());
    for (size_t i = 0; i < mult.size(); i++) {
      mult[i] = v[i] * scale;
    }
    return mult;
  }



  /**

   * Adds each element in the current vector with the passed integer and returns a new vector.

   * ex: V1 = 20 + V2; it is important that 20 is on the left!

   * 20 + [1, 2, 3] = [21, 22, 23]

   * @param adder integer to add to each element of vector v

   * @param v Vector on the right to perform addition on

   * @return new vector where index i is the result of v[i] + adder

  */

  // inline friend Vector operator + (const int adder, const Vector & v) {}


  /**

   * Allows the << operator to correctly print out the vector.

   * ex: cout << V2; -> (v[0], v[1], v[2], ... v[sz-1])

   * @param o ostream to print the elems of the array, usage is o << thingToPrint;

   * @param v vector that will be printed out

   * @return the ostream passed in

  */

  inline friend ostream& operator << (ostream & o, const Vector & v) {
    o << "(";
    for (size_t i = 0; i < v.sz; i++) {
        o << v.buf[i];
        if (i != v.sz - 1) {
            o << ", ";
        }
    }
    o << ")";
    return o;
  }
};

#endif