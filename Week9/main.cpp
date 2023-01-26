//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
////void foo(int arr[], int N){ // arr has N elements
////    int sum = 0;
////    int count = 0;
////    for(int i=0; i<N; i=i*2+1) {   //Loop 1
////        sum += arr[i];
////
////    }
////    // O(log(N))
////    //cout << count << "/" << ceil(log2(N+1)) << endl;
////        for(int i=0; i<N; i++) {     // Outer Loop 2
////            count = 0;
////            for(int j = N; j>1; j=int(j/2)) {  // Inner Loop 2
////                //cout<<i<<" "<<j<<endl;
////                sum= sum+i+2*j;
////                count++;
////            }
////            cout << count << "/" << floor(log2(N)) << endl;
////        }
////        //O(N*log(N))
////        cout<<sum<<endl;
////
////        // O(log(N) + N*log(N))
////        // O(N*log(N))
////}
//
//bool bar(int arr[], int element, int N){
//    //Precondition: input array arr is sorted in ascending order
//    int begin = 0, end = N-1, mid;
//    int count=0;
//    while (begin <=  end){ // Loop 1
//        mid = (end + begin)/2;
//        if(arr[mid]==element){
//            return true;
//        }else if (arr[mid]< element){
//            begin = mid + 1;
//        }else{
//            end = mid - 1;
//        }
//
//    }
//
//    return false;
//}
//
//void foo(int arr[], int N){
//    //Precondition: input array arr is sorted in ascending order
//   int count=0;
//    for(int i=0; i<N*N; i=i+2) { //Loop 2
//        bar(arr, i, N);
//        count++;
//    }
//    cout << count << "/" << ((N*N)/2)-1 << endl;
//}
//
//int main() {
//#include <iostream>
//#include <vector>
//    using namespace std;
//
//
//    class Eligibility {
//    public:
//        string userName;
//        int age;
//        void SetDetails(int inAge, string inName) {
//            userName = inName;
//            age = inAge;
//        }
//    };
//
//
//    int main() {
//        vector<Eligibility>inUser;
//        Eligibility userEnt;
//        userEnt.SetDetails(20,"A");
//        inUser.push_back(userEnt);
//        userEnt.SetDetails(17,"B");
//        inUser.push_back(userEnt);
//        for (auto user : inUser) {
//            if (user.age < 18) {
//                cout << user.userName << " - Not Eligible!";
//            }
//        }
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;


class Eligibility {
public:
    string userName;
    int age;
    void SetDetails(int inAge, string inName) {
        userName = inName;
        age = inAge;
    }
};


int main() {
    vector<Eligibility> inUser;
    Eligibility userEnt;
    userEnt.SetDetails(20, "A");
    inUser.push_back(userEnt);
    userEnt.SetDetails(17, "B");
    inUser.push_back(userEnt);
    for (auto user : inUser) {
        if (user.age < 18) {
            cout << user.userName << " - Not Eligible!";
        }
    }
}
