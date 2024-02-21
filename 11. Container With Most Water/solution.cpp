class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;

        int l_border = 0;
        int r_border = height.size()-1;

        int curArea;
        while (r_border > l_border) {
            if (height[l_border] > height[r_border]) {
                curArea = height[r_border] * (r_border - l_border); 
                r_border--;
            } else {
                curArea = height[l_border] * (r_border - l_border);
                l_border++;
            }
            if (curArea > result) result = curArea;
        }

        return result;
    }
};