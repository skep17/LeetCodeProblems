public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] result = new int[2];
        Dictionary<int, int> data = new Dictionary<int, int>();

        int cur;
        Nullable<int> pair;
        for (int i = 0; i < nums.Length; i++){
            cur = nums[i];
            pair = (data.TryGetValue(target-cur, out int value)) ? value : null;
            if (pair != null){
                result[0] = data[target-cur];
                result[1] = i;
                break;
            } else {
                data[cur] = i;
            }
        }      
        return result;
    }
}