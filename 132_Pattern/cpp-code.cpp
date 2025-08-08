#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int s3 = numeric_limits<int>::min();
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s3) {
                return true;
            }
            while (!s.empty() && nums[i] > s.top()) {
                s3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    getline(cin, line);
    stringstream ss(line);
    int number;
    vector<int> nums;
    while (ss >> number) {
        nums.push_back(number);
    }
    Solution sol;
    if (sol.find132pattern(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}