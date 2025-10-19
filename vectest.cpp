#include "vector.h"

int main() // Here is a start:

{
    // Vector<int> v1{1, 2, 3};
    // Vector<int> v2 = 20 * v1;
    // cout << v2 << endl;

    // cout << "v1 = " << v1 << endl;
    // cout << "v2 = " << v2 << endl;
    // cout << "v3 = " << v3 << endl;

    // cout << "size of v1 = " << v1.size() << endl;
    // cout << "size of v2 = " << v2.size() << endl;
    // cout << "size of v3 = " << v3.size() << endl;

    // cout << "v2[2] = " << v2[2] << endl;
    // cout << "v1[-1] = " << v1[-1] << endl;
    // cout << "v2[4] = " << v2[4] << endl;


        Vector<int> intVec{1,3,5,7,9};

        Vector<double> doubleVec{1.5,2.5,3.5,4.5};

        Vector<int> iv{intVec};

        Vector<double> dv{doubleVec};

        cout << "intVec" << intVec << endl;

// "intVec(1, 3, 5, 7, 9)"

        cout << "iv" << iv << endl;

// "iv(1, 3, 5, 7, 9)"

        cout << "doubleVec" << doubleVec << endl;

// "doubleVec(1.5, 2.5, 3.5, 4.5)"

cout << "dv" << dv << endl;


// "dv(1.5, 2.5, 3.5, 4.5)"

return 0;

}