#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a hashmap to store the array elements
        unordered_map<int, int> hashmap;

        // Create vector to store the indices of the answer
        vector<int> ans;

        // Iterate through the vector
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.count(target - nums[i])) {
                ans.push_back(hashmap[target - nums[i]]);
                ans.push_back(i);
            }
            // Insert the current element into the hashmap
            hashmap[nums[i]] = i;
        }
        return ans;
    }
};