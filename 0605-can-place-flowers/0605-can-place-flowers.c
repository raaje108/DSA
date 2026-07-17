bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            int left = (i == 0) ? 0 : flowerbed[i - 1];
            int right = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            if (left == 0 && right == 0) {
                flowerbed[i] = 1;
                n--;
                if (n <= 0)
                    return true;
            }
        }
    }

    return n <= 0;
}