class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        int i = 1;
        char color = colors[0];
        int curr = 0;
        while(i < colors.size())
        {
            if(colors[i] == color)
            {
                ans += min(neededTime[curr],neededTime[i]);
                curr = (neededTime[curr] > neededTime[i])? curr : i;
            }
            else
            {
                color = colors[i];
                curr = i;
            }
            i++;
        }
        return ans;
    }
};