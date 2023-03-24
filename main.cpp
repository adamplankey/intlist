#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &list);
void PopulateList2(IntegerList list);

int main()
{
    cout << "In main" << endl;

    const int SIZE = 20;
    IntegerList numbers(SIZE);

    for (int x = 0; x < SIZE; x++)
        numbers.setElement(x, x);

    numbers.displayList();

    IntegerList numbers2 = numbers;  // Copy Constructor
    numbers2.displayList();

    numbers.setElement(5, 24);
    numbers.setElement(7, -4);
    numbers.setElement(12, 12345);

    numbers.displayList();
    numbers2.displayList();

	cout << endl;

    cout << "Calling PopulateList" << endl;
    PopulateList(numbers);
    cout << "Returned from PopulateList" << endl;

	cout << endl;

    cout << "Calling PopulateList2" << endl;
    PopulateList2(numbers);
    cout << "Returned from PopulateList2" << endl;

	cout << endl;

    IntegerList numbers3(4);
    numbers3.displayList();

    numbers3 = numbers;      // Assignment
    numbers3.displayList();
    numbers.setElement(5, -17);

    numbers3.displayList();
    numbers.displayList();

	cout << endl;

	numbers = numbers2 = numbers3;

    numbers.displayList();
    numbers2.displayList();
    numbers3.displayList();

	cout << endl;

    numbers.setElement(0, 12345);
    numbers2.setElement(5, 54321);

    numbers.displayList();
    numbers2.displayList();
    numbers3.displayList();

	cout << "Out main" << endl;

    return 0;
}

void PopulateList(IntegerList &list)
{
    cout << "In PopulateList" << endl;

    list.setElement(0, 1111);
    list.setElement(1, 2222);
    list.setElement(2, 3333);

    list.displayList();

    cout << "Out PopulateList" << endl;
}

void PopulateList2(IntegerList list)
{
    cout << "In PopulateList2" << endl;

    list.setElement(0, 4444);
    list.setElement(1, 5555);
    list.setElement(2, 6666);

    list.displayList();

    cout << "Out PopulateList2" << endl;
}




