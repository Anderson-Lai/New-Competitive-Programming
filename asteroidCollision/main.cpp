#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> result;
        std::deque<int> stc;

        for (size_t i = 0; i < asteroids.size(); i++) {
            // if first item is negative, push
            if (i == 0 && asteroids[i] < 0) {
                stc.push_back(asteroids[0]);
                continue;
            }
            // if positive, push
            if (asteroids[i] > 0) {
                stc.push_back(asteroids[i]);
                continue;
            }
            // if negative, control flow
            if (asteroids[i] < 0) {
                // empty, push
                if (stc.empty()) {
                    stc.push_back(asteroids[i]);
                    continue;
                }
                // negative, push
                if (stc.back() < 0) {
                    stc.push_back(asteroids[i]);
                    continue;
                }
                // positive, control flow for the back
                if (stc.back() > 0) {
                    while (true) {
                        // if empty, push
                        if (stc.empty()) {
                            stc.push_back(asteroids[i]);
                            break;
                        }
                        // if negative, push
                        if (stc.back() < 0) {
                            stc.push_back(asteroids[i]);
                            break;
                        }
                        // if positive, control flow
                        else if (stc.back() > 0) {
                            int ast = std::abs(asteroids[i]);

                            // if greater than |asteroids[i]| return
                            if (stc.back() > ast) {
                                break;
                            }
                            // equal, pop back and return
                            else if (stc.back() == ast) {
                                stc.pop_back();
                                break;
                            }
                            // if less, pop back
                            else if (stc.back() < ast) {
                                stc.pop_back();
                            }
                        }
                    }
                }
            }
        }

        while (!stc.empty()) {
            result.push_back(stc.front());
            stc.pop_front();
        }
        return result;
    }
};

int main() {

    Solution sol;
    std::vector<int> asteroids = { 1, -2, -2, -2 };

    auto temp = sol.asteroidCollision(asteroids);
    for (const auto& val : temp) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}