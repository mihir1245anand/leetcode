class Solution {
public:   
    bool checkValidString(string& s) {
        int bMin=0, bMax=0;
        for(char c: s){
            bMin+=(c=='(')-(c==')')-(c=='*');
            bMax+=(c=='(')-(c==')')+(c=='*');
            if (bMax<0) return 0;
            bMin=max(0, bMin);
        }
        return bMin==0;
    }
};