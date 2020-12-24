#include <iostream>

template <typename T>
class Array {

private:
    int size;
    int capacity;
    T* arrPtr;

public:
    Array()
    {
        capacity = 10;
        size = 0;
        arrPtr = new T[10];
    }

    bool insert(int position, T value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* tempPtr = new T[capacity];
            for (int i = 0; i < position; ++i)
            {
                *(tempPtr + i) = *(arrPtr + i);
            }
            *(tempPtr + position) = value;

            for (int i = position + 1; position < capacity / 2; ++i)
            {
                *(tempPtr + i) = *(arrPtr + i);
            }

            delete [] arrPtr;
            arrPtr = tempPtr;
            tempPtr = nullptr;
        }

        else if (position >= size + 1)
        {
            return false;
        }

        else
        {
            for (int i = size - 1; i >= position; --i)
            {
                *(arrPtr + i + 1) = *(arrPtr + i);
            }
            *(arrPtr + position) = value;
        }
        ++size;
        return true;
    }

    bool append(T value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            std::cout << "Updating capacity, new capcity: " << capacity << std::endl;
            T* tempPtr = new T[capacity];
            for (int i = 0; i < capacity/2; ++i)
            {
                *(tempPtr + i) = *(arrPtr + i);
            }
            *(tempPtr + (capacity / 2)) = value;

            delete[] arrPtr;
            arrPtr = tempPtr;
            tempPtr = nullptr;
        }
        else
        {
            *(arrPtr + size) = value;
        }
        ++size;
        return true;
    }

    bool remove(int position)
    {
        if (position < 0 || position > size)
        {
            return false;
        }
        else
        {
            *(arrPtr + position) = 0;
            for (int i = position + 1; i < size; ++i)
            {
                *(arrPtr + i - 1) = *(arrPtr + i);
            }
            *(arrPtr + size - 1) = NULL;
        }
        --size;
        return true;
    }

    void print()
    {
        std::cout << "Printing elements: \n";
        for (int i = 0; i < size; ++i)
        {
            std::cout << "Address : " << arrPtr + i;
            std::cout << "Value : " << *(arrPtr + i) << std::endl;
        }
    }

    void printCapacity()
    {
        std::cout << "Capacity is: " << capacity << std::endl;
    }
};

int main()
{
    Array<int> n;
    n.append(1);
    n.append(2);
    n.append(3);
    n.print();
    std::cout << "After Inserting" << std::endl;
    n.insert(3, 50);
    n.insert(10, 20);
    n.insert(0, 20);
    n.print();
    
    std::cout << "After Removing" << std::endl;
    n.remove(1);
    n.remove(3);
    n.print();   


    Array<char> c;
    c.append('a');
    c.append('b');
    c.append('c');
    c.append('z');
    c.insert(1, 'r');
    c.remove(1);
    c.remove(0);
    c.remove(10);
    c.remove(-1);
    c.print();
}