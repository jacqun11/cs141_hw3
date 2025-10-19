#include "vector.h"

int main() // Here is a start:

{
    Vector<double> v1{1.1, 2.2, 3.3};
    Vector<int> v2{4, 5, 6};
    Vector<double> v3{2.5, 1.2, 2.2};
    Vector<int> v4(v2);
    Vector<double> v5{1.1, 2.2, 3.3};
    Vector<int> v6{7, 8};

    cout << (v1 != v5) << endl; // true
    cout << (v1 != v3) << endl; // false
    cout << (v2 != v4) << endl; // true
    cout << (v2 != v6) << endl; // false





    // cout << "v1 = " << v1 << endl;
    // cout << "v2 = " << v2 << endl;
    // cout << "v3 = " << v3 << endl;

    // cout << "size of v1 = " << v1.size() << endl;
    // cout << "size of v2 = " << v2.size() << endl;
    // cout << "size of v3 = " << v3.size() << endl;

    // cout << "v2[2] = " << v2[2] << endl;
    // cout << "v1[-1] = " << v1[-1] << endl;
    // cout << "v2[4] = " << v2[4] << endl;


//         Vector<int> intVec{1,3,5,7,9};

//         Vector<double> doubleVec{1.5,2.5,3.5,4.5};

//         Vector<int> iv{intVec};

//         Vector<double> dv{doubleVec};

//         cout << "intVec" << intVec << endl;

// // "intVec(1, 3, 5, 7, 9)"

//         cout << "iv" << iv << endl;

// // "iv(1, 3, 5, 7, 9)"

//         cout << "doubleVec" << doubleVec << endl;

// // "doubleVec(1.5, 2.5, 3.5, 4.5)"

// cout << "dv" << dv << endl;


// // "dv(1.5, 2.5, 3.5, 4.5)"


//         // add at least one test case for each method defined in Vector

return 0;

}