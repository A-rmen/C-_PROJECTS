
int jumpingOnClouds(vector<int> c) {
    int moves = 0;
    int pos = 0;

    while (pos < c.size() - 1) {
        if (pos + 2 < c.size() && c[pos + 2] == 0) {
            pos += 2;
        } else {
            pos++;
        }

        moves++;
    }

    return moves;
}
