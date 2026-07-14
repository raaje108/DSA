int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0)
        return 0;

    int hold = -prices[0];
    int sold = 0;
    int rest = 0;

    for (int i = 1; i < pricesSize; i++) {
        int prevSold = sold;

        sold = hold + prices[i];

        if (hold < rest - prices[i])
            hold = rest - prices[i];

        if (rest < prevSold)
            rest = prevSold;
    }

    return (sold > rest) ? sold : rest;
}