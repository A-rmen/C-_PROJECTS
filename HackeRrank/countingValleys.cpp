
int countingValleys(int steps, string path) {
    int height = 0;
    int valleys = 0;

    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            height++;
        } else {
            if (height == 0) {
                valleys++;
            }
            height--;
        }
    }

    return valleys;
}
