int maxProfit(int* prices, int pricesSize, int fee) {

    int cash = 0;
    int hold = -prices[0];

    for (int i = 1; i < pricesSize; i++) {

        int prevCash = cash;

        // Don't own stock OR sell today
        cash = cash > hold + prices[i] - fee
             ? cash
             : hold + prices[i] - fee;

        // Keep holding OR buy today
        hold = hold > prevCash - prices[i]
             ? hold
             : prevCash - prices[i];
    }

    return cash;
}