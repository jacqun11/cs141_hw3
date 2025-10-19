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
    delete[] buf;
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

  inline friend Vector operator * (const int scale, const Vector & v) {
    Vector<T> mult(v.sz);
    for (size_t i = 0; i < mult.sz; i++) {
      mult[i] = v[i] * scale;
    }
    return mult;
  }

  inline friend Vector operator + (const int adder, const Vector & v) {
    Vector<T> add(v.sz);
    for (size_t i = 0; i < add.sz; i++) {
      add[i] = v[i] + adder;
    }
    return add;
  }

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