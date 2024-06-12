#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:

    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        /*
        notes:
        remember base cases and side cases
        always check for really small values, like .size() == 1
        to prevent heap-buffer overflows or logic errors
        check to make sure if last and first logic work properly, as those are the most frequent edge cases
        */
        if (n == 0) return true;
        int counter = 0;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (i == 0) {
                if (flowerbed.size() > 1 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                    counter++;
                    flowerbed[i] = 1;
                }
                else if (flowerbed.size() == 1 && flowerbed[i] == 0) counter++;
            }
            else if (i == flowerbed.size() - 1) {
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                    counter++;
                    flowerbed[i] = 1;
                }
            }
            else if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                counter++;
                flowerbed[i] = 1;
            }
        }
        return counter >= n;
    }
};

int main() {

    Solution sol;
    std::vector<int> flowers = { 1 };
    std::cout << sol.canPlaceFlowers(flowers, 1);

    return 0;
}