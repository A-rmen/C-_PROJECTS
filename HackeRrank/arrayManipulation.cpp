
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long> numbers(n + 1, 0);

    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        int amount = queries[i][2];

        numbers[left] += amount;
        numbers[right + 1] -= amount;
    }

    long long current = 0;
    long long highest = 0;

    for (int i = 1; i <= n; i++) {
        current += numbers[i];

        if (current > highest) {
            highest = current;
        }
    }

    return highest;
}
