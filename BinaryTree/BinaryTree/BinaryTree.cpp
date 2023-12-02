#include <iostream>
using namespace std;
template<typename T>
class TreeUsingArray {

    T* array;
    int totalNodes;
    bool* status;
public:
    TreeUsingArray(int h) {
        totalNodes = pow(2, h) - 1;
        array = new T[totalNodes];
        status = new bool[totalNodes];
        for (int i = 0; i < totalNodes; i++) {
            status[i] = false;
        }
    }

    void setRooT(T val) {
        array[0] = val;
        status[0] = true;
    }
    void setLeftChild(T val, int par) {
        ind = par * 2 + 1;
        array[ind] = val;
        status[ind] = true;
    }
    void setRightChild(T val, int par) {

        ind = par * 2 + 2;
        if (ind > totalNodes) {

        }
        array[ind] = val;
        status[ind] = true;

    }

    void search(int val) {

   }
      
};
int main()
{

    TreeUsingArray<int> tree(3);
    tree.setRooT(1);


    int selection = 0;
    int ind = 0; int val;
     for (;;) {
         cout << "enter 1 to break" << endl;
         cout << "enter 2 for left child" << endl;
         cout << "enter 3 for right child" << endl;
         cin >> selection;
         if (selection == 1)
             break;
         else if (selection == 2) {

             cout << "enter index to set left child:";
                 cin >> ind;
                 cout << "enter value of left child:";
             cin>> val;
             tree.setLeftChild(val, ind);
         }
         else {
             cout << "enter index to set right child:";
             cin >> ind;
             cout << "enter value of right child:";
             cin >> val;
             tree.setRightChild(val, ind);
         }
     }

    //tree.print();
    //tree.PostOrderUsingRecursion(0);
}


