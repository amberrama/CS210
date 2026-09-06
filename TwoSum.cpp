#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

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

void printResult(
    const std::string& method,
    const std::vector<int>& nums,
    int target,
    std::pair<int, int> result
) {
    bool valid =
        result.first >= 0 &&
        result.second >= 0 &&
        result.first != result.second &&
        result.first < nums.size() &&
        result.second < nums.size() &&
        nums[result.first] + nums[result.second] == target;

    std::cout << method << " indices: ["
              << result.first << ", "
              << result.second << "]"
              << std::endl;

    if (valid) {
        std::cout << method << " values: ["
                  << nums[result.first] << ", "
                  << nums[result.second] << "]"
                  << std::endl;
    }

    std::cout << method << " valid: "
              << std::boolalpha << valid
              << std::endl;
}

void runTest(
    const std::string& testName,
    const std::vector<int>& nums,
    int target
) {
    std::cout << "\n" << testName
              << " — target: " << target
              << std::endl;

    std::pair<int, int> bruteResult =
        twoSumBruteForce(nums, target);

    std::pair<int, int> hashResult =
        twoSumHash(nums, target);

    printResult(
        "Brute force",
        nums,
        target,
        bruteResult
    );

    printResult(
        "Hash table",
        nums,
        target,
        hashResult
    );
}

int main() {
    runTest(
        "Required test",
        {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9},
        24
    );

    runTest(
        "Test 2: Basic pair",
        {2, 7, 11, 15},
        9
    );

    runTest(
        "Test 3: Pair later in vector",
        {3, 2, 4},
        6
    );

    runTest(
        "Test 4: Duplicate values",
        {3, 3},
        6
    );

    runTest(
        "Test 5: Negative number",
        {-5, 2, 9, 1},
        4
    );

    return 0;
}