#ifndef INTEGERLIST_H
#define INTEGERLIST_H

class IntegerList
{
private:
    int *list;
    int numElements;
    bool isValid(int) const;

public:
    IntegerList(int size = 10);
    ~IntegerList();
    void setElement(int index, int value);
    int getElement(int index) const;
    void displayList() const;
    const IntegerList operator=(const IntegerList &right);
    const IntegerList operator+(const IntegerList &right);
    int& operator[](const int &index);
    void resize(int newSize);
    IntegerList(const IntegerList &obj);
};

#endif
