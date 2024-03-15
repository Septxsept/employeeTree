#include <iostream>
#include <string>
using namespace std;

// EmployeeInfo class
class EmployeeInfo {
public:
    int employeeID;
    string employeeName;

    EmployeeInfo(int id, const std::string& name) : employeeID(id), employeeName(name) {}
};

// Node template for the binary tree
template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary tree template
template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    // Private helper function for inserting a value into the tree
    Node<T>* insert(Node<T>* currentNode, const T& value) {
        if (currentNode == nullptr) {
            return new Node<T>(value);
        }

        if (value.employeeID < currentNode->data.employeeID) {
            currentNode->left = insert(currentNode->left, value);
        }
        else {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode;
    }

    // Private helper function for searching a value in the tree
    Node<T>* search(Node<T>* currentNode, int targetID) const {
        if (currentNode == nullptr || currentNode->data.employeeID == targetID) {
            return currentNode;
        }

        if (targetID < currentNode->data.employeeID) {
            return search(currentNode->left, targetID);
        }
        else {
            return search(currentNode->right, targetID);
        }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value into the tree
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Public function to search for an employee by ID
    const T* search(int employeeID) const {
        Node<T>* resultNode = search(root, employeeID);
        return (resultNode != nullptr) ? &(resultNode->data) : nullptr;
    }
};

// Driver program
int main() {


    cout << "C++ CIS245 ** Name: Komlaga Gone **          C++" << endl;
    cout << "C++ CIS245 ** Chapter 21 binarytree **          C++" << endl;
    cout << "C++ CIS245 ** # 8 employee tree **     C++" << endl;
    cout << "C++ CIS245 ** Date Submitted:  12/15/2023 **    C++" << endl;
    // Creating a binary tree with EmployeeInfo
    BinaryTree<EmployeeInfo> employeeTree;

    // Inserting nodes into the tree
    employeeTree.insert(EmployeeInfo(1021, "John Williams"));
    employeeTree.insert(EmployeeInfo(1057, "Bill Witherspoon"));
    employeeTree.insert(EmployeeInfo(2487, "Jennifer Twain"));
    employeeTree.insert(EmployeeInfo(3769, "Sophia Lancaster"));
    employeeTree.insert(EmployeeInfo(1017, "Debbie Reece"));
    employeeTree.insert(EmployeeInfo(1275, "George McMullen"));
    employeeTree.insert(EmployeeInfo(1899, "Ashley Smith"));
    employeeTree.insert(EmployeeInfo(4218, "Josh Plemmons"));

    // Asking the user for an ID to search
    int searchID;
    cout << "Enter an Employee ID to search: ";
    cin >> searchID;

    // Searching for the employee by ID
    const EmployeeInfo* result = employeeTree.search(searchID);

    // Displaying the result
    if (result != nullptr) {
        cout << "Employee found: " << result->employeeName << endl;
    }
    else {
        cout << "Employee not found." << endl;
    }

    return 0;
}
