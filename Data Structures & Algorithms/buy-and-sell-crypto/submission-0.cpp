class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // To store the minimum buying price so far
        int maxProfit = 0;        // To store the maximum profit
        // Traverse through each day's price
        for (int price : prices) {
            // Update minimum price if a lower price is found
            minPrice = min(minPrice, price);
            // Calculate profit if we sell on this day
            int profit = price - minPrice;
            // Update max profit if this profit is higher
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
