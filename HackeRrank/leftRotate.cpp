
int hourglassSum(vector<vector<int>> arr) {
    int sums[16];
    int index = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int total = arr[row + 1][col + 1];

            for (int k = 0; k < 3; k++) {
                total += arr[row][col + k];
                total += arr[row + 2][col + k];
            }

            sums[index] = total;
            index++;
        }
    }

    int largest = sums[0];

    for (int i = 1; i < 16; i++) {
        if (sums[i] > largest) {
            largest = sums[i];
        }
    }

    return largest;
}
