#include <iostream>
using namespace std;
template<typename T>

class TreeUsingArray {

    T* array;
    int arrSize;
    bool* status;
public:
    TreeUsingArray(int h) {
        arrSize = pow(2, h+1) - 1;
        array = new T[arrSize];
        status = new bool[arrSize];
        for (int i = 0; i < arrSize; i++) {
            status[i] = true;

           //to set values in array simply instead of tree insertion functions like setleftchild or right
            //to test other functions quickly
           // array[i] = i + 1;
        }
    }

    void setRooT(T val) {
        array[0] = val;
        status[0] = true;
    }
    void setLeftChild(T val, int par) {
        int ind = par * 2 + 1;
        if (ind < arrSize) {
            array[ind] = val;
            status[ind] = true;
        }
        else {
            
            cout<< "Error: Index out of bounds." << std::endl;
        }
    }
    void setRightChild(T val, int par) {

      int  ind = par * 2 + 2;
    
      if (ind < arrSize) {
          array[ind] = val;
          status[ind] = true;
      }
      else {

          cout<< "Error: Index out of bounds." << std::endl;
      }
        

    }

    void displayAncestors(T val) {

        int index = search(val, 0);

        while (index > 0) {
            if (index % 2 == 0) {
                index = (index - 2) / 2;
                cout << array[index];
            }
            else
            {
                index = (index - 1) / 2;
                cout << array[index];
            }
        }


    }

     int search(T val,int ind) {

         if (ind >= 0 && ind < arrSize) {
             if (array[ind] == val) {
                 return ind;
             }

             // Recursively search in left and right subtrees
             int leftResult = search(val, (ind * 2 + 1));
             if (leftResult != -1) {
                 return leftResult;
             }

             return search(val, (ind * 2 + 2));
         }

         // If index is out of range, return -1
         return -1;
    }
     void removeDes(int ind) {
         if (ind >= arrSize)
             return;

         status[ind] = false;
         removeDes((ind * 2 + 1));
         removeDes((ind * 2 + 2));

     }

    void PreOrderUsingRecursion(int ind) {
        if (ind >= arrSize)
            return;
        if (status[ind] != false) {
            cout << array[ind];
        }
        PreOrderUsingRecursion((ind * 2 + 1));
        PreOrderUsingRecursion((ind * 2 + 2));
    }

   
      
};
int main()
{

    TreeUsingArray<int>tree(2);
  //  tree.setRooT(1);


    int selection = 0;
    int ind = 0; int val;
     /*for (;;) {
         cout << "enter 1 to break" << endl;
         cout << "enter 2 for left child" << endl;
         cout << "enter 3 for right child" << endl;
         cout << "enter 4 to display ancesstors" << endl;
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
         else if (selection == 4) {
             cout << "enter Node value to display ancestors";
            
             cin >> val;
             tree.displayAncestors(val);
         }
         else if (selection==3)
         {
             cout << "enter index to set right child:";
             cin >> ind;
             cout << "enter value of right child:";
             cin >> val;
             tree.setRightChild(val, ind);
         }
     }*/


    cout << "enter val to remove descendants::";
    cin >> val;
    int index = tree.search(val, 0);
    tree.removeDes(index);
    
    tree.PreOrderUsingRecursion(0);
}


