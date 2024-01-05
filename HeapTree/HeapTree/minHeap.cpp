#include <iostream>
using namespace std;


class MinHeap {
    int* array;
    int size;
    int index;
public:

    MinHeap() {
        size = 4;
        index = 0;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
    }
    bool isFull() {
        return size == index;
    }

    void resize() {

        int* temp = new int[size * 2];

        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        size = size * 2;
        delete array;
        array = temp;

    }
    void swap(int& a, int& b) {
        if (a != b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
    }
    int getLeftChildIndex(int i) {

        int child = (i * 2) + 1;
        if (child < index)
            return child;
        else return -1;
    }

    int getRightChildIndex(int i) {

        int child = (i * 2) + 2;
        if (child < index)
            return child;
        else return -1;
    }

    int getParent(int i) {
        if (i == 0)
            return -1;

        if (i % 2 == 0) {
            return (i - 2) / 2;
        }
        else {
            return (i - 1) / 2;
        }
    }

    void insert(int val) {

        if (isFull())
            resize();

        array[index] = val;
        index++;

        int i = index - 1;
        while (i > 0) {
            int parentIndex = getParent(i);
            if (parentIndex == -1)
                break;

            if (array[i] < array[parentIndex])
            {
                swap(array[i], array[parentIndex]);
            }
            else
            {
                break;
            }

            i = parentIndex;


        }


    }
   
    void deleteKey() {

        
        if (!isEmpty()) {
            swap(array[0], array[index - 1]);
            index--;
            int i = 0;
            while (i < index) {
                int leftChild = getLeftChildIndex(i);
                int rightChild = getRightChildIndex(i);
                if (leftChild == -1)
                    break;

                if (rightChild == -1)
                {
                    swap(array[i], array[leftChild]);
                    break;
                }
                if (array[leftChild] < array[rightChild]) {
                    swap(array[i], array[leftChild]);
                    i = leftChild;

                }
                else if (array[leftChild] > array[rightChild])
                {
                    swap(array[i], array[rightChild]);
                    i = rightChild;
                }
                else {
                    break;
                }
                   
            }
        }
    }

   
    bool isEmpty() {
        return index == 0;
    }
    void print() 
    {
        for (int i = 0; i < index; i++)
        { 
            cout << array[i] << endl;
        }
    }
};

int main()
{
    cout << "Hello World!\n";
    MinHeap tree;
    tree.insert(20);
    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(50);
    tree.deleteKey();
    tree.deleteKey();
    
    tree.print();
}
