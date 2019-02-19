//Working with char vector using Array
//The class FixedVector has been declared and was implemented.The code is available here.
//You want to use additional operations within the class, so the function member insert needs to be changed, as well as two new functions members, find and operator == need to be added to the class definition and implemented.
//Consider the new class definition below, and the new / modified functions being in bold.

// Augmented Declaration
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class FixedVector {
private:
	size_t size_; // number of elements in the data structure
	const size_t capacity_; // length of the array
	T* array_; // pointer to dynamically allocated array

public:
	// Constructors
	FixedVector(size_t arraysize = 0) {};        // Also serves as default constructor
	FixedVector(const FixedVector& input) {};    // Copy constructor
	~FixedVector()
	{
		delete array_;
	}

	// Getters / Setters
	T& at(size_t index);
	T& operator[](size_t index);
	void push_back(const T& value);
	void set(size_t index, const T& value);
	void erase(size_t index);
	size_t find(const T& value);
	size_t insert(size_t beforeIndex, const T& value);
	size_t size();
	bool empty();
	void clear();

	// Overloaded Operators
	FixedVector& operator= (const FixedVector& rhs);  //Copy assignment
	bool operator== (const FixedVector& rhs);
};




// Function member to look for value in FixedVector
// If value is in the FixedVector, then return the index of FixedVector that contains 
// the value. If size_ is 0 (array is empty) or the value is not in FixedVector, then
// return size_
template <typename T>
size_t FixedVector<T>::find(const T& value) {
	if (size_ = 0 || value != FixedVector) //Check if the array is empty or if the value is not in the FixedVector
	{
		return size_; //unable to find the value or the vector is empty.
	}

	else //see if value is in the object/array 
	{
		if (std::find(std::begin(FixedVector), std::end(FixedVector), value) != std::end(FixedVector)) //if the value is found 
		{
			int i = std::distance(FixedVector, (std::find(std::begin(FixedVector), std::end(FixedVector), value) != std::end(FixedVector))); //get the index of the found value
			return i;
		}
	}
}


// Function member to test the equality between two FixedVectors
// It returns true if the two FixedVectors are exactly the same, false otherwise
template <typename T>
bool FixedVector<T>::operator== (const FixedVector& rhs) 
{
	if (this != &rhs)
	{
		return false;
	}

	return true;
}

// Function member to insert value in the FixedVector at index beforeIndex and return
// beforeIndex
// If beforeIndex is between 0 and size_, then insert the value by pushing all the
// elements to the right of beforeIndex one position to the right, and increment size_
// If size would exceed capacity, then exit with an error
// If beforeIndex is >=size_ then display error and do not do any changes to FixedVector
template <typename T>
size_t FixedVector<T>::insert(size_t beforeIndex, const T& value)
{
	capacity_ = Array1.max_size();
	size_ = sizeof(Array1) / sizeof(Array1[0]); //size_ is the number of elements currently in the array
	array_ = new int[size_ + 1]; //Dynamically allocating a new array with a size + 1 of the old array

	if (size_ > capacity_)
	{
		cout << "Size exceeded capacity error." << endl;
		exit(EXIT_FAILURE);
	}

	else if (beforeIndex >= size_)
	{
		cout << "Index not found in array." << endl;
		delete[]array_;
	}

	else
	{
		int x = 0; //Index for Array1
		for (int i = 0; i < size_; i++) // for loop to copy Array1 to dynamically allocated array
		{
			array_[i] = Array1[x];
			++x;
		}

		for (int i = beforeIndex - 2; i >= 0; i--) //shift everything over to the right by 1 from beforeIndex position
		{
			array_[beforeIndex + 1] = array_[beforeIndex];
		}

		array_[beforeIndex] = value; //assign value to the beforeIndex position after shifting everything over
	}

	return beforeIndex;
}


int main() {
	// testing the new implementation of a FixedVector

	// declare & initialize a FixedVector of int with 10 elements 
	FixedVector<int> Array1(5); 

	// place 1,5,10 in the array
	cout << "FixedArray gets the elements 1, 5, 10" << endl;
	Array1.push_back(1);
	Array1.push_back(5);
	Array1.push_back(10);

	// Try the find operation
	cout << "Value 5 is at index " << Array1.find(5) << endl;

	// Try the insert operation
	cout << "Value 2 is inserted at index" << Array1.insert(1,2) << endl;

	// Try the == operator
	FixedVector<int> Array2(5);
	Array2.push_back(1);
	Array2.push_back(5);
	Array2.push_back(10);
	if (Array1 == Array2)
		cout << "The two arrays are the same." << endl;
	else
		cout << "The two arrays are different." << endl;

	return 0;
}

//Turn in the complete code, including all of the above “to be completed” sections.
//Test by running the main() function above and capture the console screen output, by attaching it as an captured image(use CTRL + PrtSc) or printed out as a file.



