class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies[n];

        for (int i = 0; i < n; i++) {
            candies[i] = 1;
        }

        //Left to right

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        //Right to left

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += candies[i];
        }
        return ans;
    }
};