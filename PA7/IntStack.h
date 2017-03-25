// Specification file for the IntStack class
// Adapted from Gaddis source code

class IntStack {
private:
    static const int STACK_SIZE = 100;  // The stack size
    int stackArray[STACK_SIZE];         // The stack array
    int top;          // Index to the top of the stack
    
public:
    // Constructor
    IntStack();
    
    // Stack operations
    void push(int);
    int pop();
    bool isFull() const;
    bool isEmpty() const;
};
