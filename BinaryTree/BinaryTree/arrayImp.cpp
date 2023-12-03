//#include <iostream>
//using namespace std;
//template<typename T>
//
//class TreeUsingArray {
//
//    T* array;
//    int arrSize;
//    bool* status;
//public:
//    TreeUsingArray(int h) {
//        arrSize = pow(2, h+1) - 1;
//        array = new T[arrSize];
//        status = new bool[arrSize];
//        for (int i = 0; i < arrSize; i++) {
//            status[i] = false;
//        }
//    }
//
//    void setRooT(T val) {
//        array[0] = val;
//        status[0] = true;
//    }
//    void setLeftChild(T val, int par) {
//        int ind = par * 2 + 1;
//        if (ind < arrSize) {
//            array[ind] = val;
//            status[ind] = true;
//        }
//        else {
//            
//            cout<< "Error: Index out of bounds." << std::endl;
//        }
//    }
//    void setRightChild(T val, int par) {
//
//      int  ind = par * 2 + 2;
//    
//      if (ind < arrSize) {
//          array[ind] = val;
//          status[ind] = true;
//      }
//      else {
//
//          cout<< "Error: Index out of bounds." << std::endl;
//      }
//        
//
//    }
//
//  
//
//    void PreOrderUsingRecursion(int ind) {
//        if (ind >= arrSize)
//            return;
//        if (status[ind] != false) {
//            cout << array[ind];
//        }
//        PreOrderUsingRecursion((ind * 2 + 1));
//        PreOrderUsingRecursion((ind * 2 + 2));
//    }
//
//   
//      
//};
//int main()
//{
//
//    TreeUsingArray<int>tree(1);
//    tree.setRooT(1);
//
//
//    int selection = 0;
//    int ind = 0; int val;
//     for (;;) {
//         cout << "enter 1 to break" << endl;
//         cout << "enter 2 for left child" << endl;
//         cout << "enter 3 for right child" << endl;
//         cin >> selection;
//         if (selection == 1)
//             break;
//         else if (selection == 2) {
//
//             cout << "enter index to set left child:";
//                 cin >> ind;
//                 cout << "enter value of left child:";
//             cin>> val;
//             tree.setLeftChild(val, ind);
//         }
//         else {
//             cout << "enter index to set right child:";
//             cin >> ind;
//             cout << "enter value of right child:";
//             cin >> val;
//             tree.setRightChild(val, ind);
//         }
//     }
//
//    
//    tree.PreOrderUsingRecursion(0);
//}
//
//
