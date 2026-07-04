#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures){

    vector<int> ans(temperatures.size(),0);
    stack<int> st;

    for(int i=0;i<temperatures.size();i++){

        while(!st.empty() &&
              temperatures[i] > temperatures[st.top()]){

            int idx = st.top();
            st.pop();

            ans[idx] = i - idx;
        }

        st.push(i);
    }

    return ans;
}

int main(){

    vector<int> temp = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemperatures(temp);

    for(int x : ans)
        cout<<x<<" ";

    return 0;
}