// Author: Tim Whitfield
//
// Honor Pledge:
// 
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"

#include <iostream>

using namespace std;

int main (void)
{
    try
    {
        Array a1;
        cout << "a1" << endl;
        cout << a1.size () << endl;
        cout << a1.max_size () << endl;
        
        Array a2 (10);
        cout << "a2" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
        cout << "a2 values" << endl;
        for (size_t i = 0; i < a2.size (); i++)
        {
            cout << a2 [i] << endl;
        }
        
        Array a3 (7, 'c');
        cout << "a3" << endl;
        cout << a3.size () << endl;
        cout << a3.max_size () << endl;
        cout << "a3 values" << endl;
        for (size_t i = 0; i < a3.max_size (); i++)
        {
            cout << a3 [i] << endl;
        }

        Array * a4 = new Array (6, 'x');
        cout << "a4 (heap)" << endl;
        cout << a4->size () << endl;
        cout << a4->max_size () << endl;
        cout << "a4 values" << endl;
        for (size_t i = 0; i < a4->size (); i++)
        {
            cout << (*a4) [i] << endl;
        }
        delete a4;
        // uncomment to check deletion of characters
        // causes valgrind errors (reading from free'd memory)
        /*
        cout << "a4 values after deletion" << endl;
        for (size_t i = 0; i < a4->size (); i++)
        {
            cout << (*a4) [i] << endl;
        }
        */ 

        a3.fill ('f');
        cout << "a3 values after fill" << endl;
        for (size_t i = 0; i < a3.size (); i++)
        {
            cout << a3 [i] << endl;
        }

        a2 [1] = 's';
        a2.set (4, 'q');
        cout << "a2 values after a2 [1] = 's' and a2.set (4, 'q')" << endl;
        for (size_t i = 0; i < a2.size (); i++)
        {
            cout << a2 [i] << endl;
        }
        // uncomment to test exception handling
        // cout << a2 [1000] << endl;

        cout << "a2.get (3) returns " << a2.get (3) << endl;
        cout << "a2.get (4) returns " << a2.get (4) << endl;
        cout << "a2.find ('q') returns " << a2.find ('q') << endl;
        cout << "a2.find ('w') returns " << a2.find ('w') << endl;
        cout << "a2.find ('q', 2) returns " << a2.find ('q', 2) << endl;
        cout << "a2.find ('q', 7) returns " << a2.find ('q', 7) << endl;
        // uncomment to test exception handling
        // cout << "a2.get (11) returns " << a2.get (11) << endl;
        // cout << "when trying to set char at bad index..." << endl;
        // a3.set (14, 'a');
        // cout << "a2.find ('p', 37) returns " << a2.find ('p', 37) << endl;

        const Array & a5 = a2;
        cout << "const Array & a5 = a2" << endl;
        cout << a5.size () << endl;
        cout << a5.max_size () << endl;
        cout << "a5 values" << endl;
        for (size_t i = 0; i < a5.size (); i++)
        {
            cout << a5 [i] << endl;
        }
        // uncomment to test exception handling
        // cout << a5 [15] << endl;

        a1 = a2;
        cout << "a1 = a2" << endl;
        cout << a1.size () << endl;
        cout << a1.max_size () << endl;
        cout << "a1 values" << endl;
        for (size_t i = 0; i < a1.size (); i++)
        {
            cout << a1 [i] << endl;
        }

        Array a6 (a2);
        cout << "Array a6 (a2)" << endl;
        cout << a6.size () << endl;
        cout << a6.max_size () << endl;
        cout << "a6 values" << endl;
        for (size_t i = 0; i < a6.size (); i++)
        {
            cout << a6 [i] << endl;
        }

        cout << "a1 == a2 returns " << (a1 == a2) << endl;
        cout << "a1 != a2 returns " << (a1 != a2) << endl;
        cout << "a6 == a2 returns " << (a6 == a2) << endl;
        cout << "a6 != a2 returns " << (a6 != a2) << endl;
 
        a1.set (0, 'd');
        cout << "After setting a1 [0] to 'd'..." << endl;
        cout << "a1 == a2 returns " << (a1 == a2) << endl;
        cout << "a1 != a2 returns " << (a1 != a2) << endl;

        cout << "a2" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
        a2.resize (10);
        cout << "a2 after a2.resize (10)" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
        a2.resize (8);
        cout << "a2 after a2.resize (8)" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
        a2.resize (13);
        cout << "a2 after a2.resize (13)" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
        a2.resize (11);
        cout << "a2 after a2.resize (11)" << endl;
        cout << a2.size () << endl;
        cout << a2.max_size () << endl;
    }
    catch (std::out_of_range)
    {
        cout << endl << endl << "EXCEPTION: index out of range" << endl;
    }
    return 0;
}
