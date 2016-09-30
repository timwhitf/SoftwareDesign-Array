// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $
// 
// Author: Tim Whitfield
// 
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


#include "Array.h"
#include <stdexcept>

#define RANGE_MESSAGE_ "index is out of range\n"
#define DEFAULT_LENGTH_ 6


// Default Constructor
Array::Array (void) :
    data_ (new char [DEFAULT_LENGTH_]), 
    cur_size_ (DEFAULT_LENGTH_), 
    max_size_ (DEFAULT_LENGTH_)
{
    // no code required here
}


// Parameter Constructor (sets length)
Array::Array (size_t length) :
    data_ (new char [length]), 
    cur_size_ (length), 
    max_size_ (length)
{
    // no code required here
}


// Parameter Constructor (sets length and contents)
Array::Array (size_t length, char fill) :
    data_ (new char [length]), 
    cur_size_ (length), 
    max_size_ (length)

// Use method defined in this Array class.
{
    this->fill (fill);
}


// Copy Constructor
Array::Array (const Array & array) :
// Set data members of new array equal to those of original array.
// Then manually copy each element from original array into new
// array.
    data_ (new char [array.max_size_]), 
    cur_size_ (array.cur_size_), 
    max_size_(array.max_size_)
{
    for (size_t i = 0; i < array.size (); i++)
    {
        this->data_ [i] = array [i];
    }
}


// Destructor
Array::~Array (void)
{
    delete [] this->data_;
}


// Copy Assignment
const Array & Array::operator = (const Array & rhs)
// Calling resize () guarantees that this array will be as large as rhs.
// But if this array was already big enough, resize () will only change
// cur_size_, so that max_size_ needs to be set to equal that of rhs.
// On the other hand, if this array was enlarged (moved) by resize (), 
// then its cur_size_ is large enough to accomodate the max_size_ of rhs
// but may be larger than the cur_size_ of rhs. 
// Thus, both values must be explicitly set to match those of rhs.
// Once sizes are set, manually copy all char values within the currently
// used portion of rhs.
{
    this->resize ( rhs.max_size () );
    this->cur_size_ = rhs.size ();
    this->max_size_ = rhs.max_size ();

    for (size_t i = 0; i < rhs.size (); i++)
    {
        this->data_ [i] = rhs [i];
    }

    return (* this);
}


// Index Operator (returns mutable character reference)
char & Array::operator [] (size_t index)
{
    if (index < this->cur_size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}


// Index Operator (returns constant character reference)
const char & Array::operator [] (size_t index) const
{
    if (index < this->cur_size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}


// Get Character
char Array::get (size_t index) const
{
    if (index < this->cur_size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}


// Set Character
void Array::set (size_t index, char value)
{
    if (index < this->cur_size_)
    {
        this->data_ [index] = value;
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}


// Resize Array
void Array::resize (size_t new_size)
// Set cur_size_ equal to new_size.
// If max_size_ is big enough to accomodate new_size, then leave max_size_
// and data_ unchanged (keep the array in the same location in memory).
// If not, perform a deep copy into a larger array that can accomodate
// new_size (located at new_data_). Then set data member "data_" equal to
// this new memory address.
{
    if (new_size <= this->max_size_)
    {
        this->cur_size_ = new_size;
    }
    else
    {
        char * new_data = new char [new_size];
        for (size_t i = 0; i < this->cur_size_; i++)
        {
            new_data [i] = this->data_ [i];
        }
        delete [] this->data_;
        this->data_ = new_data;
        this->cur_size_ = new_size;
        this->max_size_ = new_size;
    }
}


// Find Character (first instance)
int Array::find (char ch) const
// Traverse array until char at position equals "ch," then return
// that position.
// If end of array is reached, return -1.
{
    return (this->find (ch, 0) );
}


// Find Character (after starting position)
int Array::find (char ch, size_t start) const
// Similar to previous method except begin traversing at start.
// Must also have if/else structure that throws exception unless
// start is within currently used portion of array.
{
    if (start < this->cur_size_)
    {
        for (size_t i = start; i < this->cur_size_; i++)
        {
            if (this->data_ [i] == ch)
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}


// Equality Operator
bool Array::operator == (const Array & rhs) const
// Test for equality of cur_size_ and of each character,
// but not location of arrays (data_ can be different for the two arrays).
{
    if (this->cur_size_ != rhs.size () )
    {
        return false;
    }
    for (size_t i = 0; i < this->cur_size_; i++)
    {
        if (this->data_ [i] != rhs [i] )
        {
            return false;
        }
    }
    return true;
}


// Inequality Operator
bool Array::operator != (const Array & rhs) const
{
    return ! (this->operator == (rhs) );
}


// Fill Array with Default Character
void Array::fill (char ch)
// Iterate through currently used portion of array, setting each
// character to "ch."
{
    for (size_t i = 0; i < this->cur_size_; i++)
    {
        this->data_ [i] = ch;
    }
}
