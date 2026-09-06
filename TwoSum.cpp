#include <iostream>
#include <vector>

std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums [j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    std::vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target = 24;

    std::vector<int> result = twoSumBruteForce(nums, target);

    std::cout << "Brute-force indices: "
              << result[0] << ", " << result[1] << std::endl;

    return 0;
}