class Solution {
private:
    vector<vector<int>>* cache;
public:
    // DFS + Memo
    // O(n * m) time | O(n * m) space
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return false;
        
        cache = new vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        int answer = dfs(0, 0, s, t);
        delete cache;
        return answer;
    }

    int dfs(int sIndex, int tIndex, const string& s, const string& t) {
        if (tIndex == t.size()) return 1;
        if (sIndex == s.size()) return 0;
        if ((*cache)[sIndex][tIndex] != -1) return (*cache)[sIndex][tIndex];


        int ways = 0;
        if (s[sIndex] == t[tIndex]) {
            // only can use, if s char and t char match
            ways += dfs(sIndex + 1, tIndex + 1, s, t);
        }
        // always can explore, not using current s char
        ways += dfs(sIndex + 1, tIndex, s, t);

        (*cache)[sIndex][tIndex] = ways;
        return ways;
    }
};