#include <iostream>
#include <valarray>

using namespace std;

long long int numOps = 0; // Keeps track of the number of times loops are entered

void MyFunction(){
    int n = 100; // One operation

    for(int i=3; i<n; i++){ // Runs n-3 times
        int x = 1;
        x++;
        numOps+=1;
    }
    // Total number of operations =  [n-3 (loops) * 2 (operations)] = 2n - 1 operations
}

int main() {
    int m = 30;

    for(int i=0; i<(pow(2,m)); i+=2){ //loop runs (2^m)/2 times
        MyFunction();
    }

    cout << numOps << endl;

}




//#include <iostream>
//#include <ctime>
//using namespace std;
//
//long FibSequenceForLoop(int numberIterations){ // Creates fibonacci sequence with a for loop
//    long fibArray[numberIterations];
//    fibArray[0] = 1;
//    fibArray[1] = 1;
//    for(int i=2; i<numberIterations; i++){
//        fibArray[i] = fibArray[i-1] + fibArray[i-2];
//    }
//    return fibArray[numberIterations -1];
//}
//
//long FibSequenceRecursive(int numIter){ // Creates fibonacci sequence recursively
//    if (numIter == 1 || numIter == 2)
//        return 1;
//    return FibSequenceRecursive(numIter -1) + FibSequenceRecursive(numIter -2);
//}
//
//int main() {
//    time_t start, end;   //time type (a format storing time)
//    start = time(0);
//
//    int n = 50;
//    FibSequenceRecursive(n);
////    FibSequenceForLoop(n);
//
//    end = time(0);
//    cout << "It took " << difftime(end, start) << " seconds to complete " << n << " fib sequence iterations." << endl;
//
//    return 0;
//}
//
