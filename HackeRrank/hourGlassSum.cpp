
int hourglassSum(vector<vector<int>> arr) {
    int maxSum = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int currentSum = arr[row + 1][col + 1];

            for (int k = 0; k < 3; k++) {
                currentSum += arr[row][col + k];
                currentSum += arr[row + 2][col + k];
            }

            if ((row == 0 && col == 0) || currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}
