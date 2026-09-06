#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<int, int> twoSumBruteForce(
    const std::vector<int>& nums,
    int target
) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

std::pair<int, int> twoSumHash(
    const std::vector<int>& nums,
    int target
) {
    std::unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];

        if (seen.find(needed) != seen.end()) {
            return {seen[needed], i};
        }

        seen[nums[i]] = i;
    }

    return {-1, -1};
}

int main() {
    std::vector<int> nums = {
        15, 4, 18, 8, 19, 22, 24, 59,
        59, 20, 18, 12, 36, 42, 9
    };

    int target = 24;

    std::pair<int, int> bruteResult =
        twoSumBruteForce(nums, target);

    std::pair<int, int> hashResult =
        twoSumHash(nums, target);

    std::cout << "Brute-force indices: ["
          << bruteResult.first << ", "
          << bruteResult.second << "]" << std::endl;

    std::cout << "Brute-force values: ["
          << nums[bruteResult.first] << ", "
          << nums[bruteResult.second] << "]" << std::endl;

    std::cout << "Hash-table indices: ["
          << hashResult.first << ", "
          << hashResult.second << "]" << std::endl;

    std::cout << "Hash-table values: ["
          << nums[hashResult.first] << ", "
          << nums[hashResult.second] << "]" << std::endl;

    return 0;
}