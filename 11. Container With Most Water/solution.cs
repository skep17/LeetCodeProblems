public class Solution {
    public int MaxArea(int[] height) {
        int result = 0;

        int leftBorder = 0;
        int rightBorder = height.Length - 1;

        int curArea = 0;
        while (rightBorder > leftBorder)
        {
            int width = rightBorder - leftBorder;
            if (height[leftBorder] > height[rightBorder])
            {
                curArea = height[rightBorder] * width;
                rightBorder--;
            }
            else
            {
                curArea = height[leftBorder] * width;
                leftBorder++;
            }
            if (curArea > result) result = curArea;
        }

        return result;
    }
}