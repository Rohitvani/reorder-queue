// Reorder Queue (Interleave 1st Half with 2nd Half)
// [Do this by using one Stack only] (Even Length)

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>&q){
    int n=q.size();
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
     cout<<endl;
}
void reoder(queue<int>&q){
    stack<int>st;
    int n=q.size();
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);
    reoder(q);
    display(q);
}
// output - 8 4 7 3 6 2 5 1
// but expeccted output is- 1 5 2 6 3 7 4 8