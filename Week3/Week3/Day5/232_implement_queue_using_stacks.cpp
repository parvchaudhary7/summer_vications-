#include <iostream>
#include <stack>

using namespace std;

class MyQueue{

    stack<int> in;
    stack<int> out;

public:

    void push(int x){
        in.push(x);
    }

    int peek(){

        if(out.empty()){

            while(!in.empty()){

                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }

    int pop(){

        int val = peek();
        out.pop();

        return val;
    }

    bool empty(){

        return in.empty() && out.empty();
    }
};

int main(){

    MyQueue q;

    q.push(1);
    q.push(2);

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty();

    return 0;
}