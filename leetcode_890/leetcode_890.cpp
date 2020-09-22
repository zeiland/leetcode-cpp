#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (const auto &word : words)
        {
            if (word.size() != pattern.size())
            {
                continue;
            }
            vector<int> m(26, -1);
            set<int> s;

            bool flag = true;
            for (int i = 0; i < word.size(); ++i)
            {
                if (m[word[i] - 'a'] == -1 && s.find(pattern[i] - 'a') == s.end())
                {
                    m[word[i] - 'a'] = pattern[i] - 'a';
                    s.insert(pattern[i] - 'a');
                }
                else if (m[word[i] - 'a'] == -1 && s.find(pattern[i] - 'a') != s.end())
                {
                    flag = false;
                }
                else
                {
                    if (m[word[i] - 'a'] != pattern[i] - 'a')
                    {
                        flag = false;
                    }
                }
            }
            if (flag)
            {
                result.push_back(word);
            }
        }
        return result;
    }
};