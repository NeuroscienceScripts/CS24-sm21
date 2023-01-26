#include <iostream>
#include <stack>
#include <deque>

using namespace std;

template <class T>
T GetMax(T a, T b){
    return a>b? a : b;
}

int* InsertToArray(const int original[], int newNumber, int newSize){ // Cannot return arrays but can return pointer to an array
    int* newArr = new int[newSize]; // This declares 'newSize' elements in heap space
    for(int i=0; i<newSize-1; i++){ // This is why runtime is O(n) (n=number elements)
        newArr[i] =  original[i]; // Copies over old array to new array
    }
    newArr[newSize-1] = newNumber;

    return newArr; // returns a pointer to the first location of the array in heap memory
}


int main() {
    int intArr[4] = {1, 2, 3, 4};
    int* newArray = InsertToArray(intArr, 5, 5);

    for(int i=0; i<5; i++){
        cout << "Location " << i << ": " << *(newArray+i) << endl; // newArray is an int*, this notation accesses different indexes
    }

//    int arr[4]= {1, 2, 3, 4};
//
//    int newArray[3];
//    for(int i=0; i<3; i++){
//        newArray[i] = arr[i];
//    }
//
//    cout << newArray[2];



//    deque<int> queue; // First in first out
//
//    queue.push_back(1);
//    queue.push_front(2);
//    queue.push_back(3);
//
//    cout << "Empty: " << (queue.empty()?"True":"False") << endl;
//    cout << "Size: " << queue.size() << endl;
//
//    while(!queue.empty()){
//        cout << "Popping: " << queue.back() << endl;
//        queue.pop_back();
//    }


//    stack<int> stack; // Last in first out
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//
//    auto myVar = stack.top();
//
//    cout << "Empty: " << (stack.empty()?"True":"False") << endl;
//    cout << "Size: " << stack.size() << endl;
//
//    while(!stack.empty()){
//        cout << "Popping: " << stack.top() << endl;
//        stack.pop();
//    }
////    cout << "Empty: " << (stack.empty()?"True":"False") << endl;
////    cout << "Size: " << stack.size() << endl;
//    cout << myVar+2 << endl;

    return 0;
}