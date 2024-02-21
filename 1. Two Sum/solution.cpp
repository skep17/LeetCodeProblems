class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> data;
        map<int,int>::iterator it;

        int cur;
        for (int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            if (data.empty()){
                data.insert({cur, i});
            } else {
                it = data.find(target - cur);
                if (it == data.end()) {
                    data.insert({cur, i});
                } else {
                    result.push_back(it->second);
                    result.push_back(i);
                    break;
                }
            }
        }

        return result;
    }
};