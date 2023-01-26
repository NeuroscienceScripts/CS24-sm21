#include <iostream>
#include <string>
#include <queue>

using namespace std;

//class MyComparison{
//public:
//    bool operator()(const string& a, const string& b){
//        int countA =0, countB = 0;
//        for(char chr : a)
//            if (chr == 'a')
//                countA++;
//        for(char chr : b)
//            if (chr == 'a')
//                countB++;
//
//        return countA >= countB;
//    }
//};
//
//int main() {
//    priority_queue<string, vector<string>, MyComparison>  myQueue;
//    myQueue.push("aardvark");
//    myQueue.push("basin");
//    myQueue.push("Hardvard");
//
//    while(!myQueue.empty()){
//        cout << myQueue.top() << endl;
//        myQueue.pop();
//    }
//    MyComparison twoStrings;
//    cout << twoStrings("hi", "bye");
//    return 0;
//}

struct LinkedList{
    struct Node{
        int data;
        Node* nextNode = nullptr;
        Node* previousNode = nullptr; // 1

        Node(int val) {data = val; };
        void setNext(Node* nxtNode){nextNode = nxtNode; };
        void setPrevious(Node* prevNode){ previousNode = prevNode; };
    };

    Node* firstNode;
    Node* lastNode;
    explicit/* So other objects aren't implicity converted to Node type */ LinkedList(Node* firstNode):
        firstNode(firstNode){    // {this->firstNode = firstNode;};   *Ways to use firstNode as name of argument and field*
        Node* currentNode = firstNode;
        while(currentNode->nextNode)
            currentNode = currentNode->nextNode;
        lastNode = currentNode;
    };


    bool GetPredecessor(Node& currentNode); // Finds the parent of node
    void AddNode(Node& newNode){
        // Should know how to write this
    }
    void AddNodeToFront(Node& newNode){
        // Also this
    }
    void SortList(bool ascending){
        // Sort list low to high(ascending)/ high to low(!ascending)
    }
    bool SearchList(int value){
        //
    }
    bool SearchSortedList(int value){
        // Find optimized search for value in sorted list [ O(log(n)) ]
    }
};

bool LinkedList::GetPredecessor(Node& currentNode) { //2
    return currentNode . previousNode; // 3
}

int main(){
    LinkedList::Node myFirst(1);
    LinkedList::Node mySecond(2);
    LinkedList::Node myThird(3);

    myFirst.setNext(&mySecond);  //4

    mySecond.setPrevious(&myFirst);
    mySecond.setNext(&myThird);

    myThird.setPrevious(&mySecond);

    LinkedList myList(&myFirst);
    cout << myList.GetPredecessor(myFirst) << endl;
    cout << myList.GetPredecessor(mySecond);

    return 0;
}