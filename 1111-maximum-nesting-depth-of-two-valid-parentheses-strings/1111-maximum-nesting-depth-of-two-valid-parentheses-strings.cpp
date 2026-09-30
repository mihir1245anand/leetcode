class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> st;
        vector<int> sol;
        for(auto it : seq){
            if(st.empty()){
                sol.push_back(0);
                st.push(0);
            }else{
                if(it == '('){
                    st.push((st.top()+1) % 2);
                    sol.push_back(st.top());
                }else{
                    sol.push_back(st.top());
                    st.pop();
                }
            }
        }
        return sol;
    }
};