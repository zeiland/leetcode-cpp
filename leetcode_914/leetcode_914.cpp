#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> ump;
        
        for(auto i:deck)
            ++ump[i];
        
        int count = (*ump.begin()).second;
        for (auto [x, y]:ump)
        {
            if ((count = gcd(count, y)) < 2)
                return false;
        }
                
        
        return true;
    }
};