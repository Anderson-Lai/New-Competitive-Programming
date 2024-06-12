#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int currentHeight = 0;
        int maxHeight = 0;

        for (size_t i = 0; i < gain.size(); i++) {
            currentHeight += gain[i];
            maxHeight = std::max(maxHeight, currentHeight);
        }
        return maxHeight;
    }
};

int main() {

    Solution sol;

    std::vector<int> gain = { -5,1,5,0,-7 };

    std::cout << sol.largestAltitude(gain) << "\n";

    return 0;
}