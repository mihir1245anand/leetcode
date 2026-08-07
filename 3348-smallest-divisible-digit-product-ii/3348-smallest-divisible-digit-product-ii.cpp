#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Need {
        int a, b, c, d;
    };

    // contribution of each digit (2,3,5,7 exponents)
    const int ca[10] = {0,0,1,0,2,0,1,0,3,0};
    const int cb[10] = {0,0,0,1,0,0,1,0,0,2};
    const int cc[10] = {0,0,0,0,0,1,0,0,0,0};
    const int cd[10] = {0,0,0,0,0,0,0,1,0,0};

    static constexpr int A = 47; // max exponent of 2 in 1e14
    static constexpr int B = 30;
    static constexpr int C = 21;
    static constexpr int D = 17;

    vector<int> memo;

    inline int id(int a,int b,int c,int d){
        return ((a*B+b)*C+c)*D+d;
    }

    int dp(int a,int b,int c,int d){
        if(a==0 && b==0 && c==0 && d==0) return 0;
        int idx = id(a,b,c,d);
        if(memo[idx]!=-1) return memo[idx];

        int best = 100;
        memo[idx] = 100; // prevent cycles

        for(int dig=2; dig<=9; dig++){
            int na=max(0,a-ca[dig]);
            int nb=max(0,b-cb[dig]);
            int nc=max(0,c-cc[dig]);
            int nd=max(0,d-cd[dig]);

            // skip if state does not decrease
            if(na==a && nb==b && nc==c && nd==d) continue;

            best=min(best,1+dp(na,nb,nc,nd));
        }

        return memo[idx]=best;
    }

    Need apply(Need x,int dig){
        x.a=max(0,x.a-ca[dig]);
        x.b=max(0,x.b-cb[dig]);
        x.c=max(0,x.c-cc[dig]);
        x.d=max(0,x.d-cd[dig]);
        return x;
    }

    string buildSuffix(int len,Need need){
        string res;
        for(int i=0;i<len;i++){
            for(int dig=1;dig<=9;dig++){
                Need nxt=apply(need,dig);
                if(dp(nxt.a,nxt.b,nxt.c,nxt.d)<=len-i-1){
                    res.push_back(char('0'+dig));
                    need=nxt;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num,long long t){
        Need req{0,0,0,0};

        while(t%2==0){ req.a++; t/=2; }
        while(t%3==0){ req.b++; t/=3; }
        while(t%5==0){ req.c++; t/=5; }
        while(t%7==0){ req.d++; t/=7; }

        if(t!=1) return "-1";

        memo.assign(A*B*C*D,-1);

        int n=num.size();

        // check if num already works
        bool zeroFree=true;
        Need cur=req;
        for(char ch:num){
            if(ch=='0'){
                zeroFree=false;
                break;
            }
            cur=apply(cur,ch-'0');
        }
        if(zeroFree && cur.a==0 && cur.b==0 && cur.c==0 && cur.d==0)
            return num;

        vector<bool> ok(n+1,false);
        vector<Need> pref(n+1);

        ok[0]=true;
        pref[0]=req;
        Need running=req;

        for(int i=0;i<n;i++){
            if(!ok[i]) continue;
            if(num[i]=='0'){
                ok[i+1]=false;
            }else{
                running=apply(running,num[i]-'0');
                ok[i+1]=true;
                pref[i+1]=running;
            }
        }

        // try same length
        for(int i=n-1;i>=0;i--){
            if(!ok[i]) continue;
            Need need=pref[i];

            for(int dig=max(1,(num[i]-'0')+1); dig<=9; dig++){
                Need nxt=apply(need,dig);
                if(dp(nxt.a,nxt.b,nxt.c,nxt.d)<=n-i-1){
                    string ans=num.substr(0,i);
                    ans.push_back(char('0'+dig));
                    ans+=buildSuffix(n-i-1,nxt);
                    return ans;
                }
            }
        }

        // need longer length
        int L=max(n+1,dp(req.a,req.b,req.c,req.d));
        return buildSuffix(L,req);
    }
};