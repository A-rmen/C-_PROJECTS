
int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int size = arr.size();

    for (int pos = 0; pos < size; pos++) {
        while (arr[pos] != pos + 1) {
            int correctPos = arr[pos] - 1;

            int value = arr[pos];
            arr[pos] = arr[correctPos];
            arr[correctPos] = value;

            swaps++;
        }
    }

    return swaps;
}
