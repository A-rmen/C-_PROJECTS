
int sockMerchant(int n, vector<int> ar) {
    int total = 0;

    for (int x = 0; x < n; x++) {
        if (ar[x] == 0) {
            continue;
        }

        for (int y = x + 1; y < n; y++) {
            if (ar[x] == ar[y]) {
                total++;
                ar[y] = 0;
                break;
            }
        }

        ar[x] = 0;
    }

    return total;
}
