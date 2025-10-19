#ifndef VECTOR_H

#define VECTOR_H

#include <iostream>

using namespace std;


/** ADVISED ORDER OF IMPLEMENTATION

 * 3. Write test cases that use some of the constructors and print those vectors out

 * 4. Write a test case for a function

 * 5. Implement the function and test until you are confident on its correctness

 * 6. Repeat from 4 until all methods are implemented and tested

 * 7. Implement the destructor last; if there are still errors,

      then you know it is due to memory management

*/


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



  /**

   * Destructs the current vector and deep copies the passed vector

   * ex: V1 = V2;

   * V1 could be an already existing vector, be sure to clean it up before the deep copy

   * @param v Vector on the right to deep copy

   * @return reference to the current object

  */

  // const Vector & operator = (const Vector & v) {}

 


  /**

   * Determines whether the current vector is equivalent to the passed vector

   * ex: bool isV1AndV2Same = V1 == V2;

   * @param v Vector on the right to compare current with

   * @return true if both vectors are deeply equivalent (elem by elem comparison)

   * and false otherwise

  */

  // bool operator == (const Vector & v) const {}



  /**

   * Determines whether the current vector is not equivalent to the passed vector

   * ex: bool isV1AndV2Different = V1 != V2;

   * @param v Vector on the right to compare current with

   * @return false if both vectors are deeply equivalent (elem by elem comparison)

   * and true otherwise

  */

  // bool operator != (const Vector & v) const {}


  /**

   * Multiplies each element in current vector with the passed integer and returns a new vector.

   * ex: V1 = 20 * V2; it is important that 20 is on the left!

   * 20 * [1, 2, 3] = [20, 40, 60]

   * @param scale integer to multiple each element of vector v

   * @param v Vector on the right to perform multiplication on

   * @return new vector where index i is the result of v[i] * scale

  */

  // inline friend Vector operator * (const int scale, const Vector & v) {}



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