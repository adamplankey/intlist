#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size)
{
    list = new int[size];
    numElements = size;
    for (int ndx = 0; ndx < size; ndx++)
        list[ndx] = 0;
}

IntegerList::~IntegerList()
{
    delete [] list;
}

IntegerList::IntegerList(const IntegerList &obj)
{
    numElements = obj.numElements;
    list = new int[numElements];
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right)
{
    if (this != &right) {
        delete [] list;
        numElements = right.numElements;
        list = new int[numElements];
        for (int i = 0; i < numElements; i++)
            list[i] = right.list[i];
    }

    return *this;
}

const IntegerList IntegerList::operator+(const IntegerList &right)
{
    int newSize = numElements + right.numElements;
    IntegerList result(newSize);

    for (int i = 0; i < numElements; i++)
        result.list[i] = list[i];
    for (int i = 0; i < right.numElements; i++)
        result.list[numElements + i] = right.list[i];

    return result;
}

int &IntegerList::operator[](const int &index)
{
    if (index < 0)
        return list[0];
    else if (index >= numElements)
        return list[numElements - 1];
    else
        return list[index];
}

void IntegerList::resize(int newSize)
{
    int *newList = new int[newSize];
    int copySize = (newSize < numElements) ? newSize : numElements;

    for (int i = 0; i < copySize; i++)
        newList[i] = list[i];
    for (int i = copySize; i < newSize; i++)
        newList[i] = 0;

    delete [] list;
    list = newList;
    numElements = newSize;
}

bool IntegerList::isValid(int element) const
{
    bool status;

    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;
    return status;
}

void IntegerList::setElement(int element, int value)
{
    if (isValid(element))
        list[element] = value;
    // Do nothing if element is out of bounds
}

int IntegerList::getElement(int element) const
{
    if (isValid(element))
        return list[element];
    else if (element < 0)
        return list[0];
    else
        return list[numElements - 1];
}

void IntegerList::displayList() const
{
    for (int i = 0; i < numElements; i++)
        std::cout << list[i] << " ";
    std::cout << endl;
}
