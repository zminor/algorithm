#include "../precompile.h"
using namespace std;
#include <limits>
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> m;
        int mn = INT8_MAX, mx = INT8_MIN;
        for(auto & str: wordDict)
        {
            int len = str.size();
            mn = std::min(mn,len);
            mx = std::max(mx,len);
            m.insert(str);
        }
        std::vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=mn; i< dp.size();++i)
        {
            for(int j = mn; j<= mx && j<=i; ++j)
            {
                auto ss = s.substr(i-j,j);
                dp[i] = dp[i-j] && m.count( s.substr(i-j,j));
                if(dp[i]) break;
            }
        }
        return dp.back();
    }


int main (int argc, char** argv)
{
	std::string str = "applepenapple";
    std::vector<std::string> dict = {"apple","pen"};
    //std::string str1= "A man, a plan, a canal: Panama";
	auto res = wordBreak(str,dict);
	std::cout <<"fk u "<<res<<std::endl;
}
