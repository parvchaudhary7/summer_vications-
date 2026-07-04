#include <iostream>
#include <queue>

using namespace std;

class RecentCounter{

    queue<int> q;

public:

    int ping(int t){

        q.push(t);

        while(q.front() < t - 3000)
            q.pop();

        return q.size();
    }
};

int main(){

    RecentCounter obj;

    cout << obj.ping(1) << endl;
    cout << obj.ping(100) << endl;
    cout << obj.ping(3001) << endl;
    cout << obj.ping(3002);

    return 0;
}