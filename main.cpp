#include <iostream>
using namespace std;

template<class T>
void qsort(T* firstElem, int size, bool (*firstMastBeCloserToBegin)(const T&, const T&))
{
    if(size < 2) // base case
        return;
    else if(size == 2) // base case
    {
        if(!firstMastBeCloserToBegin(firstElem[0], firstElem[1]))
            swap(*firstElem, *(firstElem + 1));
    }
    else // recursive case
    {
        swap(*firstElem, *(firstElem + int(size/2)));
        T* pivot      = firstElem;
        T  pivotValue = *pivot;

        for(T* elem = firstElem; elem != firstElem + size; ++elem)
        {
            if(firstMastBeCloserToBegin(pivotValue, *elem))
                continue;
            *pivot = *elem;
            *elem = *(++pivot);
        }
        *pivot = pivotValue;

        int leftPartSize = pivot - firstElem;
        int rightPartSize = size - leftPartSize - 1;
        if(leftPartSize > 1)
            qsort(firstElem, leftPartSize, firstMastBeCloserToBegin);
        if(rightPartSize > 1)
            qsort(firstElem + leftPartSize + 1, rightPartSize, firstMastBeCloserToBegin);
    }
}

template<class T>
void qsort(T* firstElem, int size)
{
    bool (*firstMastBeCloserToBegin)(const T&, const T&) = [](const T& elem1, const T& elem2){ 
        return elem1 <= elem2; 
    };
    qsort(firstElem, size, firstMastBeCloserToBegin);
}


int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    int* array = new int[size];
    for(int i = 0; i < size; ++i)
        cin >> array[i];

    qsort(array, size);
    
    for(int i = 0 ; i < size; ++i)

        cout << array[i] << ' ';

    delete[] array;
    return 0;
}
