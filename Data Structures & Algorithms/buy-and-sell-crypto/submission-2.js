class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let buy = 0
        let sell = 1

        let profit = 0

        // 1 5 1 6

        while (sell < prices.length) {
            profit = Math.max(prices[sell] - prices[buy], profit)
            if (prices[sell] >= prices[buy]) {
                sell += 1
            } else if (prices[sell] < prices[buy]) {
                buy = sell
                sell++
            }
        }

        return profit
    }
}
